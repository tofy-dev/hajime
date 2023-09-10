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
#include "globals/settings.h"

using namespace logger;

void menu::swap_window(SDL_Window* window) {
	// Get the original 'SDL_GL_SwapWindow' symbol from 'libSDL2-2.0.so.0'.
	static void (*oSDL_GL_SwapWindow) (SDL_Window*) = reinterpret_cast<void(*)(SDL_Window*)>(menu::swapwindow_original);
	
	// Store OpenGL contexts.
	static SDL_GLContext original_context = SDL_GL_GetCurrentContext();
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
        io.Fonts->AddFontFromFileTTF("/usr/share/fonts/TTF/Koruri-Light.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());

        ImGui_ImplSDL2_InitForOpenGL(window, user_context);
        ImGui_ImplOpenGL2_Init();
	}

	// Switch to our context.
	SDL_GL_MakeCurrent(window, user_context);

    std::vector<SDL_Event> unhandled_events{};

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_EQUALS) {
        *ofs << "equals key pressed" << std::endl;
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
      ImGui::Begin("hajime // はじめ", &show_window, ImGuiWindowFlags_MenuBar);
      if (ImGui::BeginMenuBar())
      {
          if (ImGui::BeginMenu("File"))
          {
              if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
              if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
              if (ImGui::MenuItem("Close", "Ctrl+W"))  { show_window = false; }
              ImGui::EndMenu();
          }
          ImGui::EndMenuBar();
      }

      // Edit a color stored as 4 floats
      static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
      ImGui::ColorEdit3("Color", (float*)&clear_color);

      // Generate samples and plot them
      float samples[100];
      for (int n = 0; n < 100; n++)
          samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
      ImGui::PlotLines("Samples", samples, 100);

      // Display contents in a scrolling region
      ImGui::TextColored(ImVec4(1,1,0,1), "Hacks");
      ImGui::BeginChild("Scrolling");

      ImGui::Checkbox("Aimbot", &settings::aimbot);
      ImGui::Checkbox("Triggerbot", &settings::triggerbot);
      ImGui::Checkbox("Auto backstab", &settings::auto_backstab);
      ImGui::Checkbox("Glow", &settings::glow);
      ImGui::Checkbox("Sniper scope", &settings::sniper_scope);
      ImGui::Checkbox("Bunnyhop", &settings::bunnyhop);

      ImGui::EndChild();
      ImGui::End();

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
	*swapwindow_ptr = reinterpret_cast<uintptr_t>(&swap_window);

    *ofs << "finishes initing successfully..." << std::endl;
}

void menu::destroy() {
    *ofs << "Destroying menu..." << std::endl;

	SDL_GL_MakeCurrent(window, user_context);

    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(user_context);

	*swapwindow_ptr = swapwindow_original;
}


namespace menu {
  uintptr_t* swapwindow_ptr = 0;
  uintptr_t swapwindow_original = 0;

  SDL_GLContext user_context = NULL;
  SDL_Window* window = nullptr;
}

namespace settings {
  bool aimbot = false;
  bool triggerbot = false;
  bool auto_backstab = false;

  bool glow = false;
  bool sniper_scope = false;
  bool third_person = false;

  bool bunnyhop = false;
}
