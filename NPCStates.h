/*
	
	$NPCStates.h

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

#ifndef NPC_STATES
#define NPC_STATES
#include "State.h"
//#include "Character.h"

class NPC;
class Strong:public State<NPC>
{
private:
	Strong(){}
	Strong& operator = (const Strong&);
public:
	static Strong* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};

class Weak:public State<NPC>
{
private:
	Weak(){}
	Weak& operator = (const Weak&);
public:
	static Weak* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};

class Wealthy:public State<NPC>
{
private:
	Wealthy(){}
	Wealthy& operator = (const Wealthy&);
public:
	static Wealthy* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};

class Poor:public State<NPC>
{
private:
	Poor(){}
	Poor& operator = (const Poor&);
public:
	static Poor* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};

class Alive:public State<NPC>
{
private:
	Alive(){}
	Alive& operator = (const Alive&);
public:
	static Alive* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};


class Dead:public State<NPC>
{
private:
	Dead(){}
	Dead& operator = (const Dead&);
public:
	static Dead* Instance();
	void Enter(NPC *io);
	void Execute(NPC *io);
	void Exit(NPC *io);
};


#endif