/*
	
	$InteractiveObjectsStates.h

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

#ifndef INTERACTIVE_OBJECTS_STATES
#define INTERACTIVE_OBJECTS_STATES
#include "State.h"
//#include "InteractiveObjects.h"
class InteractiveObjects;
class NotInteracted:public State<InteractiveObjects>
{
private:
	NotInteracted(){}
	NotInteracted& operator = (const NotInteracted&);
public:
	static NotInteracted* Instance();
	void Enter(InteractiveObjects *io);
	void Execute(InteractiveObjects *io);
	void Exit(InteractiveObjects *io);
};

class Interacted:public State<InteractiveObjects>
{
private:
	Interacted(){}
	Interacted& operator = (const Interacted&);
public:
	static Interacted* Instance();
	void Enter(InteractiveObjects *io);
	void Execute(InteractiveObjects *io);
	void Exit(InteractiveObjects *io);
};

#endif