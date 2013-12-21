/*
	
	$Inventory.h

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

#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Object.h"

class Inventory
{
private:
	vector<Collectible*> m_inventoryItems;
public:
	Inventory()
	{}
	void AddToInventory(Collectible *col)
	{
		m_inventoryItems.push_back(col);
	}
	void RunInventory(RenderWindow *win)
	{
		if(!m_inventoryItems.empty())
		{
			for(int i = 0; i<(int)m_inventoryItems.size(); i++)
			{
				m_inventoryItems[i]->SetPosition(100,100);
				win->Draw(m_inventoryItems[i]->GetSprite());
			}
		}
	}

};
#endif