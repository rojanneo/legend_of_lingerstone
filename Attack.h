/*
	
	$Attack.h

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

#ifndef ATTACKS_H_
#define ATTACKS_H_
#include <iostream>
using namespace std;
class Attack
{
private:
	int m_damage;
	string m_name;
	bool m_usable;
public:
	Attack(string name, int damage)
	{
		m_damage = damage;
		m_name = name;
	}

	int GetDamage()
	{
		return m_damage;
	}
	string GetName()
	{
		return m_name;
	}
};

#endif
