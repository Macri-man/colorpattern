#include <SDL2/SDL.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

SDL_Renderer *renderer = NULL;
SDL_Window *win = NULL;
SDL_Texture *texture=NULL;
SDL_Surface *surface=NULL;

random_device seeder;
mt19937 engine(seeder());

struct Grid {
	int width;
	int height;
	int numOfRects;
	Grid():width(800),height(800),numOfRects(16){
	}
};

typedef struct {
	string hex;
	int red;
	int green;
	int blue;
	string name;
	int num;
	Color(string newname,string newhex,int newred,int newgreen,int newblue){
		name=newname;
		hex=newhex;
		red=newred;
		green=newgreen;
		blue=newblue;
	}
	
} Color;

const SDL_Color COL_BLACK={0, 0, 0, 255};
const SDL_Color COL_WHITE={255, 255, 255, 255};

Color color[6] ={
	{ "#EE82EE", 238, 82,  238, "Violet", 0},
	{ "#FFFF00", 255, 255, 0,   "Yellow", 0},
	{ "#FF0000", 255, 0,   0,   "Red"   , 0},
	{ "#FFA500", 255, 165, 0,   "Orange", 0},
	{ "#008000", 0,   128, 0,   "Green" , 0},
	{ "#0000FF", 0,   0,   255, "Blue"  , 0},
};

struct Board {
	SDL_Rect r;
	Color color;
	Board(SDL_Rect newr,Color newcolor){
		r=newr;
		color=newcolor;
	}
};

struct Game {
	Board board[grid.width/100][grid.width/100];
	int numOfColors;
	uniform_int_distribution<int> dist(0,5);
	Game(int num){
		numOfColors=num;
		for(int i=0;i<grid.width;i+=grid.width/100){
			for(int j=0;j<grid.height;j+=grid.width/100){
				SDL_Rect r;
				r.x=i;
				r.y=j;
				r.w=100;
				r.h=100;
				board[i][j]=Board(r,color[dist(engine)].num+=1);
			}
		}

	}
	numOfColors=6;

}g;

void calcpoint(int x1;int y1){
	
}

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
        			}
        			break;
        		default:
        			continue;
        	}
            
        }
}

void draw(){
	//cerr << "DRAW" << endl;
	for(int i=0;i<grid.width/100;i++){
		for(int j=0;j<grid.width/100;j++){
			SDL_FillRect(surface,g[i][j].r,g[i][j].r,SDL_MapRGB(s->format, color.red, color.green, color.blue));
		}
	}	
    SDL_UpdateWindowSurface(win);
    SDL_Delay(200);
}

void sdl_clear(void) {
    SDL_FillRect(disp, NULL, 0);
    SDL_UpdateWindowSurface(win);
}

void sdl_refresh(void) {
    SDL_UpdateWindowSurface(win);
}



int main(int argc, char **argv){

	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        fprintf(stderr, "Error: Unable to init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    Grid grid=Grid();

    win=SDL_CreateWindow("Color Matching", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,grid.width, grid.height,SDL_WINDOW_SHOWN);

    if(!win){
       	fprintf(stderr, "Unable to initilize SDL2: %s\n", SDL_GetError());
       	SDL_Quit();
       	exit(1);
    }

    surface=GetWindowSurface(win);

    if(!surface){
    	fprintf(stderr, "Create Surface failed: %s\n", SDL_GetError());
        exit(-1);
    }
    
    TTF_Font *font;

    SDL_Rect r;
    r.x=0;
    r.y=0;
    r.w=width;
    r.h=height;

    string descp = "Click all red colors."

    SDL_Surface *text;
    text = TTF_RenderUTF8_Solid(font, descp.c_str(), COL_BLACK);
    SDL_FillRect(disp, &r, 0);
	SDL_BlitSurface(text, NULL, disp, &r);
	SDL_FreeSurface(text);
	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);

    bool game = true;
    while(game){
    	getInput();
    	draw();
    }

	SDL_FreeSurface(surface);
	SDL_DestroyWindow(win);
	TTF_Quit()
    SDL_Quit();

	return 0;
}