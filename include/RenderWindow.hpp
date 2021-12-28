#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow{
public:
	RenderWindow(const char* title, int w, int h);
	SDL_Texture* load_texture(const char* file_path);
	int refresh_rate();
	void clean_up();
	void clear();
	void render(Entity& entity);
	void display();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

/*
Pass by reference
rather than passing a copy of the object into the function, we pass the original variable
*/