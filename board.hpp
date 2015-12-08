#ifndef _BOARD_H
#define _BOARD_H

#include "tiles.hpp"
#include <vector>
#include <cmath>
#include <utility>
#include <functional>
#include <string>
#include <random>

using namespace std;


typedef struct {
	string hex;
	int red;
	int green;
	int blue;
	string name;
	int num;
	
} Color;

 Color color[6] ={
	{ "#EE82EE", 238, 82,  238, "Violet", 0},
	{ "#FFFF00", 255, 255, 0,   "Yellow", 0},
	{ "#FF0000", 255, 0,   0,   "Red"   , 0},
	{ "#FFA500", 255, 165, 0,   "Orange", 0},
	{ "#008000", 0,   128, 0,   "Green" , 0},
	{ "#0000FF", 0,   0,   255, "Blue"  , 0},
};

class Board{
public:
	Board(int width, int height, int numOfRectangles){

		std::random_device seeder;
		std::mt19937 engine(seeder());

		this->width=width;
		this->height=height;
		this->numOfRectangles=numOfRectangles;

		uniform_int_distribution<int> dist(0,5);

		int newwidth=width/numOfRectangles;
		int newheight=height/numOfRectangles;

		for(int x=0,i=0;i<sqrt(numOfRectangles);x+=newwidth,++i){
			grid.push_back(vector<Tile>());
			for(int j=0,y=0;j<sqrt(numOfRectangles);y+=newheight,++j){
				int num=dist(engine);
				grid[i].push_back(Tile(color[num].name,color[num].hex,color[num].red,color[num].green,color[num].blue,newwidth,newheight,i,j));
			}
		}
	}


	int getWidth(){
		return this->width;
	}
	void setWidth(int width){
		this->width=width;
	}

	int getHeight(){
		return this->height;
	}
	void setHeight(int height){
		this->height=height;
	}

	int getnumOfRectangles(){
		return this->numOfRectangles;
	}
	void setnumOfRectangles(int num){
		this->numOfRectangles=num;
	}

private:
	int width;
	int height;

	int numOfRectangles;

	vector<vector<Tile> > grid;
	
};

#endif