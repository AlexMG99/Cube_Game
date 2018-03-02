#include <stdio.h>
#include "../SDL/include/SDL.h"

#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGTH = 480;

int main(int argc, char* argv[]) {

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the rectangle
	SDL_Renderer* gRenderer = NULL;

	//Create window
	window = SDL_CreateWindow("Cube Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
	//Define Quad
	SDL_Rect rectangle;
	rectangle.x = 80;
	rectangle.y = 100;
	rectangle.w = 60;
	rectangle.h = 80;

	//Print blue blackground
	gRenderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
	SDL_RenderClear(gRenderer); //Print screen 

	bool loop = true;

	while (loop)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				loop = false;
			}
		}
		//Print Rectangle
		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
		SDL_RenderFillRect(gRenderer, &rectangle);
		SDL_RenderPresent(gRenderer);

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
		SDL_RenderClear(gRenderer);
		//Move Rectangle
		if (rectangle.x <= 580) {
			rectangle.x++;
			if (rectangle.x == 580) {
				rectangle.x = 0;
			}
		}

		if (rectangle.y <= 400) {
			rectangle.y++;
			if (rectangle.y == 400) {
				rectangle.y = 0;
			}
		}
		SDL_Delay(5);
	}

	//Destroy Window
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}