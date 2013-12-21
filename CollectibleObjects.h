/*
	
	$CollectibleObjects.h

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

#ifndef COLLECTIBLEOBJECTS_H_
#define COLLECTIBLEOBJECTS_H_
#include "Collectible.h"
//File for collectible objects 
// make seperate classes for each object here

class Sword:public Collectible
{
private:
	Image m_swordImg;
	Sprite m_swordSp;
public:
	Sword(int id, int x, int y, string path, int name, int a, int d, int h):Collectible(id, x, y, path, name, a, d, h)
	{
	}
	int GetAttackValue()
	{
		return this->GetAttack();
	}
	
	void Draw(RenderWindow *win)
	{
		win->Draw(this->GetSprite());
	}
};

class Potion:public Collectible
{
public:
	Potion(int id, int x, int y, string path, int name, int a, int d, int h):Collectible(id, x, y, path, name, a, d, h)
	{
	}
	
	void Draw(RenderWindow *win)
	{
		win->Draw(this->GetSprite());
	}
	int GetValue()
	{
		return this->GetHealth();
	}

};
#endif