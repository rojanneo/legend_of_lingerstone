/*
	
	$Menu.h

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

#ifndef MENU_H_
#define MENU_H_
#include "Screens.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Menu:Screens
{
private:
	Image m_menuBgImg;
	Image m_chooserImg;
	Sprite m_menuBgSp;
	String m_menuText1;
	String m_menuText2;
	Sprite m_chooser;
public:
	Menu();
	~Menu();
	int Run(sf::RenderWindow&, sf::VideoMode&);
};
#endif