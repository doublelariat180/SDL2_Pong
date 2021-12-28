#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity{
public:
	Entity(Vector2f pos, SDL_Texture* texture);
	Vector2f& pos();
	SDL_Rect current_frame();
	SDL_Texture* texture();

private:
	Vector2f m_pos;
	SDL_Rect m_current_frame;
	SDL_Texture* m_texture;
};