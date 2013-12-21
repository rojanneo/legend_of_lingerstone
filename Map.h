/*
	
	$Map.h

	Copyright (C) $2012 Anurag Prasad Pradhan, Iksha Gurung, Raj Kumar Thapa, Rojan Shrestha, Saugat Acharya
	
	This file is part of The Legend of LingerStone.
	
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


//This class will load map from text files
#ifndef MAP_H_
#define MAP_H_

#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;

class Map
{
private:
	int m_file[24][25];
	ifstream m_filename;
	ifstream m_filen;
	int m_mapCount;
	Image m_ground;
	Sprite m_groundSp[600];
	int m_groundCount;
	Image m_road;
	Sprite m_roadSp[600];
	int m_roadCount;
	Image m_grass;
	Sprite m_grassSp[600];
	int m_grassCount;
	char m_string[100];
	string str;
public:
	Map();
	~Map();
	bool LoadMap(VideoMode&, RenderWindow*,string filename);
	bool RenderMap(VideoMode&, RenderWindow*);
};
#endif