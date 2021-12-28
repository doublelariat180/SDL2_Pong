#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(Vector2f pos, SDL_Texture* texture)
:m_pos(pos), m_texture(texture)
{
	m_current_frame.x = 0;
	m_current_frame.y = 0;
	m_current_frame.w = 32;
	m_current_frame.h = 32;
}

Vector2f& Entity::pos(){
	return m_pos;
}

SDL_Rect Entity::current_frame(){
	return m_current_frame;
}

SDL_Texture* Entity::texture(){
	return m_texture;
}