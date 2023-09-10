#include "menu.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <dlfcn.h>
#include <fstream>
#include <cstdint>
#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_opengl2.h"
#include "utils/logger.h"

using namespace logger;

void hkSwapWindow(SDL_Window* window) {
	// Get the original 'SDL_GL_SwapWindow' symbol from 'libSDL2-2.0.so.0'.
	static void (*oSDL_GL_SwapWindow) (SDL_Window*) = reinterpret_cast<void(*)(SDL_Window*)>(menu::swapwindow_original);
	
	// Store OpenGL contexts.
	static SDL_GLContext original_context = SDL_GL_GetCurrentContext();
	static SDL_GLContext user_context = NULL;
    static bool show_window = false;
	
	// Perform first-time initialization.
	if (!user_context) {
		// Create a new context for our rendering.
		user_context = SDL_GL_CreateContext(window);
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        // io.WantCaptureMouse = true;

        ImGui_ImplSDL2_InitForOpenGL(window, user_context);
        ImGui_ImplOpenGL2_Init();
	}

	// Switch to our context.
	SDL_GL_MakeCurrent(window, user_context);

    std::vector<SDL_Event> unhandled_events{};

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_EQUALS) {
        show_window = !show_window;
      } else if (show_window) {
        ImGui_ImplSDL2_ProcessEvent(&event);
      } else {
        unhandled_events.push_back(event);
      }
    }

    for (SDL_Event e : unhandled_events) {
      SDL_PushEvent(&e);
    }

    if (show_window) {
      // Perform UI rendering.
      ImGui_ImplOpenGL2_NewFrame();
      ImGui_ImplSDL2_NewFrame(window);
      ImGui::NewFrame();

      // Display the UI
      ImGui::ShowDemoWindow(&show_window);
	  ImGui::Render();
      ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    }

	// Swap back to the game context.
	SDL_GL_MakeCurrent(window, original_context);

	// Call the original function.
	oSDL_GL_SwapWindow(window);
}

void menu::init() {
	Dl_info sdl_libinfo = {};
	dladdr(dlsym(RTLD_NEXT, "SDL_GL_SwapWindow"), &sdl_libinfo);

    *ofs << "fbase: " << sdl_libinfo.dli_fbase << std::endl;
    *ofs << "saddr: " << sdl_libinfo.dli_saddr << std::endl;

	// Get the address of 'SDL_GL_SwapWindow' in the jump table.
	swapwindow_ptr = reinterpret_cast<uintptr_t*>(uintptr_t(sdl_libinfo.dli_fbase) + 0xFD648);
	
	// Backup the original address.
	swapwindow_original = *swapwindow_ptr;

	// Write the address to our replacement function.
	*swapwindow_ptr = reinterpret_cast<uintptr_t>(&hkSwapWindow);

    *ofs << "finishes initing successfully..." << std::endl;
}

// TODO: add destroy function

namespace menu {
  uintptr_t* swapwindow_ptr = 0;
  uintptr_t swapwindow_original = 0;
}
