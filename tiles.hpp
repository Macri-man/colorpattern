#ifndef _TILE_H
#define _TILE_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

class Tile{
public:

	Tile(string name,string hex,int red,int blue,int green, int width, int height, int x, int y){

		this->name=name;
		this->hex=hex;
		this->red=red;
		this->blue=blue;
		this->green=green;
		this->rect.x=x;
		this->rect.y=y;
		this->rect.w=width;
		this->rect.h=height;

	};

	int getRed(){
		return this->red;
	};
	void setRed(int red){
		this->red=red;
	}

	int getGreen(){
		return this->green;
	}
	void setGreen(int green){
		this->green=green;
	}

	int getBlue(){
		return this->blue;
	}
	void setBlue(){
		this->blue=blue;
	}

	string getName(){
		return this->name;
	}
	void setName(string name){
		this->name=name;
	}

	string getHex(){
		return this->hex;
	}
	void setHex(string hex){
		this->hex=hex;
	}

	int getWidth(){
		return this->rect.w;
	}
	void setWidth(int width){
		this->rect.w=width;
	}

	int getHeight(){
		return this->rect.h;
	}
	void setHeight(int height){
		this->rect.h=height;
	}

	int getXpos(){
		return this->rect.x;
	}
	void setXpos(int xpos){
		this->rect.x=xpos;
	}

	int getYpos(){
		return this->rect.y;
	}
	void setYpos(int ypos){
		this->rect.y=ypos;
	}


	int getnumColor(){
		return this->numColor;
	}
	void setnumColor(int numColor){
		this->numColor=numColor;
	}

	int red,blue,green;	
	string name;
	string hex;
	
	SDL_Rect rect;
	int numColor;
	
};

#endif