/*
	
	$Collectible.h

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
#ifndef COLLECTIBLE_H_
#define COLLECTIBLE_H_
//Class to classify interactive objects as collectible
//Do not create objects for this class
//only use this class as parent class

#include "InteractiveObjects.h"
class Collectible:public InteractiveObjects
{
protected:
	bool m_collected;
	Sprite m_sp;
	Image m_img;
	int m_attack;
	int m_defence;
	int m_health;
	int m_name;
public:
	Collectible(int id, int x, int y, string path, int name, int attack, int defence, int health):InteractiveObjects(id)
	{
		m_img.LoadFromFile(path);
		m_sp.SetImage(m_img);
		m_sp.SetPosition((float)x,(float) y);
		m_collected = false;
		m_attack = attack;
		m_defence = defence;
		m_health = health;
		m_name = name;
	}
	int GetAttack()
	{
		return m_attack;
	}
	
	int GetDefence()
	{
		return m_defence;
	}

	int GetHealth()
	{
		return m_health;
	}
	void AddSprite(Sprite sp)
	{
		m_sp = sp;
	}
	Sprite GetSprite()
	{
		return m_sp;
	}
	bool IsCollected()
	{
		return m_collected;
	}
	void Collected()
	{
		m_collected = true;
	}
	void SetPosition(float x, float y)
	{
		m_sp.SetPosition(x, y);
	}
};
#endif