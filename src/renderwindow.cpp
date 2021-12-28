#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* title, int w, int h)
	:m_window(NULL), m_renderer(NULL)
{
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	/*title, x pos, y pos, width, height, frontmost window?*/
	/*returns pointer*/
	if(m_window == NULL){
		std::cout << "WINDOW FAILED TO INIT. ERROR: " << SDL_GetError() << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	/*where to render to, driver used to render, flags*/
	/*-1 for driver just means first one we can find that
	gets the job done*/
	/*Accelerated flag just means use the resources necessary 
	(gpu) to get opt performance*/
}

SDL_Texture* RenderWindow::load_texture(const char* file_path){
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(m_renderer, file_path);
	if(texture == NULL){
		std::cout << "FAILED TO LOAD TEXTURE. ERROR: " << SDL_GetError() << std::endl;
	}
	return texture;
}

int RenderWindow::refresh_rate(){
	int display_index = SDL_GetWindowDisplayIndex(m_window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(display_index, 0, &mode);
	/*display index, mode index*/
	/*a 60hz display can also work at 30hz*/
	return mode.refresh_rate;
}

void RenderWindow::clean_up(){
	SDL_DestroyWindow(m_window);
}

void RenderWindow::clear(){
	SDL_RenderClear(m_renderer);
}

void RenderWindow::render(Entity& entity){
	SDL_Rect src;
	src.x = entity.current_frame().x;
	src.y = entity.current_frame().y;
	src.w = entity.current_frame().w;
	src.h = entity.current_frame().h;

	SDL_Rect dst;
	dst.x = entity.pos().x() * 4;
	dst.y = entity.pos().y() * 4;
	dst.w = entity.current_frame().w * 4;//width * scaling factor
	dst.h = entity.current_frame().h * 4;
	/*
	+------->+x
	|
	|
	|
	|
	v
	+y
	*/

	SDL_RenderCopy(m_renderer, entity.texture(), &src, &dst);
	/*what to render with, object to render, viewable x, viewable y*/
	/*NULL for x and y means use entire screen*/
}

void RenderWindow::display(){
	SDL_RenderPresent(m_renderer);
}