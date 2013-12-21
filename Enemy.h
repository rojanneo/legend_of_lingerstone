/*
	
	$Enemy.h

	Copyright (C) $2012 Anurag Prasad Pradhan, Iksha Gurung, Raj Kumar Thapa, Rojan Shrestha, Saugat Acharya
	
	This file is part of Calendar.
	
	The Legend of LingerStone is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Legend of LingerStone is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Legend of LingerStone.  If not, see <http://www.gnu.org/licenses/>.

	rojan_neo@hotmail.com
*/

#ifndef ENEMY_H_
#define ENEMY_H_
#include <sFML\Graphics.hpp>
#include "NPC.h"
using namespace sf;
class Enemy
{
private:
	Image enemyImg;
	Sprite enemysp;
	int health;
	int magic;
	int level;
public:
	Enemy()
	{
		health = 100;
		magic  = 100;
		level = 1;
		enemyImg.LoadFromFile("../data/Images/Enemy.png");
		enemysp.SetImage(enemyImg);
		enemysp.SetPosition(0.0f,300.0f);
	}

	void Default()
	{
		health = 100;
		magic  = 100;
		level = 1;
		enemyImg.LoadFromFile("../data/Images/Enemy.png");
		enemysp.SetImage(enemyImg);
		enemysp.SetPosition(0.0f,300.0f);
	}

	
	
	void Update()
	{
	//	playersp.Update();
	}
	/*sprite Getsprite()
	{
		return playersp;
	}*/
	int GetHealth()
	{
		return health;
	}
	int GetMagicLevel()
	{
		return magic;
	}
	void SetPosition(float x, float y)
	{
		enemysp.SetPosition(x,y);
	}
	void Draw(VideoMode &vMode, RenderWindow *win, float startx, float starty)
	{
		enemysp.SetPosition(startx, starty +300);
		win->Draw(enemysp);
	}
	int get_level()
	{
		return level;
	}
	void set_position(float x,float y)
	{
		enemysp.SetPosition(x,y);
	}
	void set_image(std::string sth)
	{
		enemyImg.LoadFromFile(sth);
		enemysp.SetImage(enemyImg);
	}
	void decrease_health(int h)
	{
		health -= h;
		if(health<0) health = 0;
	}
};
#endif