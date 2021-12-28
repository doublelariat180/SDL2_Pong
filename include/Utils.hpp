#pragma once
#include <SDL2/SDL.h>

namespace utils{
	inline float hire_time_in_seconds(){
		float t = SDL_GetTicks();
		t*=0.001f;//converting ms to s
		return t;
	}
}