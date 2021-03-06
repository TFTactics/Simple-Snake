#include "Snake.h"

Snake::Snake(COORD pos, int vel){
	this->pos = pos;
	this->vel = vel;
	len = 1;
	dir = 'n';
	
	body.push_back(pos);
}

void Snake::direction(char dir)	{	this->dir = dir;	}
void Snake::grow()	{ len++; }
COORD Snake::get_pos()	{	return pos;	}

vector<COORD> Snake::get_body()	{	return body;	}

void Snake::move_snake(){
	switch(dir){
		case 'u': pos.Y -= vel;	break;
		case 'd': pos.Y += vel;	break;
		case 'l': pos.X -= vel;	break;
		case 'r': pos.X += vel;	break;
	}
	
	body.push_back(pos);
	if(body.size() > len) body.erase(body.begin());
}

bool Snake::eaten(COORD food){
	if(food.X == pos.X && food.Y == pos.Y)	return true;
	else return false;
}

bool Snake::collided(){
	if(pos.X < 1 || pos.X > Width - 2 || pos.Y < 1 || pos.Y > Height - 2)	return true;
	
	for(int i = 0; i < len - 1; i++){
		if(pos.X == body[i].X && pos.Y == body[i].Y)
		return true;
	}
	return false;
}
