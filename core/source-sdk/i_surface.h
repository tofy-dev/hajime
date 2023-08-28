#pragma once
#include "utils/utils.h"

class Color {};
class i_surface {
  void draw_set_color(int r, int g, int b, int a) {
	typedef void(*fn)(void*, int r, int g, int b, int a);
    return utils::get_virtual_function<fn>(this, 10)(this, r, g, b, a);
  }
  void draw_set_color(Color clr) {
	typedef void(*fn)(void*, Color);
    return utils::get_virtual_function<fn>(this, 11)(this, clr);
  }
  void draw_filled_rect(int x, int y, int w, int h) {
	typedef void(*fn)(void*, int, int, int, int);
    return utils::get_virtual_function<fn>(this, 12)(this, x, y, w, h);
  }
  void draw_outlined_rect(int x, int y, int w, int h) {
	typedef void(*fn)(void*, int, int, int, int);
    return utils::get_virtual_function<fn>(this, 14)(this, x, y, w, h);
  }
};
