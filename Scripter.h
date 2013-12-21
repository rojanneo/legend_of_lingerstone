/*
	
	$Scripter.h

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


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <SFML\Graphics.hpp>
using namespace std;
#define MAX_NO_COMMAND 20
#define COMMAND_SLEEP "Sleep"
#define COMMAND_DRAW "DrawImage"
class Scripter
{
private:
	ifstream m_file;
	int m_noOfLines;
	string m_command;
	string m_stringParameter;
	string m_entireCommand[MAX_NO_COMMAND];
	int m_intParameter;
	int m_counter;
	static int m_pointer;
public:
	Scripter(void);
	~Scripter(void);
	bool LoadScript(string filename);
	void UnLoadScript();
	void GetCommand(string entireCommand);
	int RunScript(sf::Image *im, sf::Sprite *sp);
	void GetStringParamenter(string entireCommand);
	void GetIntParameter(string entireCommand);
};

