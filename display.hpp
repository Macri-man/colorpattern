#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "tiles.hpp"

using namespace std;

const SDL_Color COL_BLACK={0, 0, 0, 255};
const SDL_Color COL_WHITE={255, 255, 255, 255};

class Display{
public:
	Display(){
		if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        	fprintf(stderr, "Error: Unable to init SDL: %s\n", SDL_GetError());
        	exit(1);
    	}

    	if(TTF_Init() < 0) {
    		fprintf(stderr, "Error: Unable to init SDL Fonts: %s\n", SDL_GetError());
        	exit(1);
		}
	};

	void createWindow(int width, int height){
		this->win = SDL_CreateWindow("Color Matching", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_SHOWN);

		if(!this->win){
       		fprintf(stderr, "Unable to initilize SDL2: %s\n", SDL_GetError());
       		SDL_Quit();
       		exit(1);
    	}

    	this->surface=SDL_GetWindowSurface(win);

    	if(!this->surface){
    		fprintf(stderr, "Create Surface failed: %s\n", SDL_GetError());
        	exit(-1);
    	}

	};
	void createTexture();
	void createSurface(){

		this->surface=SDL_GetWindowSurface(win);

    	if(!this->surface){
    		fprintf(stderr, "Create Surface failed: %s\n", SDL_GetError());
        	exit(-1);
    	}
	};
	void createRenderer();

	void updateTile(Tile t){
		if(SDL_FillRect(surface, &t.rect, SDL_MapRGB(surface->format, t.red, t.green, t.blue))){
			fprintf(stderr, "%s\n","Unable to update color: ");
		}
	}

	void updatewindow(){
		SDL_UpdateWindowSurface(win);
	}

	string getDecrip(){
		return this->descp;
	}
	void setDecrip(string descp){
		this->descp=descp;
	}

	void makeFont(){
		SDL_Surface *text;
    	text = TTF_RenderUTF8_Solid(font, this->descp.c_str(), COL_BLACK);
    	SDL_FillRect(surface, 0, 0);
		SDL_BlitSurface(text, NULL, surface, 0);
		SDL_FreeSurface(text);
		SDL_Delay(1000);
		SDL_UpdateWindowSurface(win);

	}

private:
	SDL_Renderer *renderer = NULL;
	SDL_Window *win = NULL;
	SDL_Texture *texture=NULL;
	SDL_Surface *surface=NULL;
	TTF_Font *font;
	string descp;

	
};

#endif