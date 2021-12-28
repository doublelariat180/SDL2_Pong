#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[]){
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;

	RenderWindow window("PONG v1.0", 1280, 720);
	SDL_Texture* table_texture = window.load_texture("res/gfx/table.png");
	SDL_Texture* left_paddle_texture = window.load_texture("res/gfx/blue_paddle.png");
	SDL_Texture* right_paddle_texture = window.load_texture("res/gfx/red_paddle.png");
	SDL_Texture* ball_texture = window.load_texture("res/gfx/ball.png");

	std::vector<Entity> static_entities = {Entity(Vector2f(200, 100), table_texture)};

	std::vector<Entity> dynamic_entities = 
		{
		Entity(Vector2f(0, 0), left_paddle_texture),
	 	Entity(Vector2f(32, 0), right_paddle_texture),
	 	Entity(Vector2f(32, 32), ball_texture)
	 	};


	bool game_running = true;
	SDL_Event event;
	while(game_running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				game_running = false;
		}
		window.clear();
		for(Entity& e : static_entities){//essentially an iterator
			//essentially means to for e in entities
			window.render(e);
		}
		for(Entity& e : dynamic_entities){//essentially an iterator
			//essentially means to for e in entities
			window.render(e);
		}
		window.display();
	}

	window.clean_up();
	SDL_Quit();
	return 0;
}