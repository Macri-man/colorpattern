
#include "display.hpp"
#include "board.hpp"

bool game;

void getInput(){
	SDL_Event e;
        while(SDL_PollEvent(&e)) {
        	switch(e.type){
        		case SDL_QUIT:
        			exit(1);
        			break;
        		case SDL_KEYDOWN:
        		case SDL_KEYUP:
        			switch(e.key.keysym.sym){
        				case SDLK_BACKSPACE:
        				case SDLK_ESCAPE:
        				case SDLK_q:
        					game=false;
        			}
        			break;
        		case SDL_MOUSEBUTTONDOWN:
        		case SDL_MOUSEBUTTONUP:
        			switch(e.key.keysym.sym){
        				case SDL_BUTTON_LEFT:
        				case SDL_BUTTON_MIDDLE:
        				case SDL_BUTTON_RIGHT:
        					continue;
        			}
        			break;
        		default:
        			continue;
        	}
            
        }
}


int main(int argc, char const *argv[]){
	
	Display disp=Display();

	disp.createWindow(800,800);

	Board gameboard=Board(800,800,9);

	game = true;
    while(game){
    	getInput();
    	disp.makeFont();
    	disp.updatewindow();
    }

	return 0;
}