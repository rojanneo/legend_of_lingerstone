/*
	
	$Object.h

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

#ifndef OBJECT_H_
#define OBJECT_H_
//This class will load a file and place related objects in their respective positions according to the file
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Collision.h"
#include "CollectibleObjects.h"
#include "Inventory.h"
#include "NPC.h"
#include "ExitSensor.h"
#include "LScripter.h"
//#include "Comment_System.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;
enum
{
	collectible,
	noncollectible,
	exitsensor
};
class Object
{
private:
	int m_file[24][25];
	ifstream m_filename;
	
	Inventory m_inventory;

	Image m_objectImg1;
	Image m_objectImg2;
	Image m_objectImg3;
	Image m_objectImg4;
	Image m_objectImg5;
	Image m_objectImg6;
	Image m_objectImg7;
	Image m_objectImg8;
	Image m_objectImg9;
	Image m_objectImg10;

	Sprite m_objectSp1[600];
	Sprite m_objectSp2[600];
	Sprite m_objectSp3[600];
	Sprite m_objectSp4[600];
	Sprite m_objectSp5[600];
	Sprite m_objectSp6[600];
	Sprite m_objectSp7[600];
	Sprite m_objectSp8[600];
	Sprite m_objectSp9[600];
	Sprite m_objectSp10[600];

	int m_object1Count;
	int m_object2Count;
	int m_object3Count;
	int m_object4Count;
	int m_object5Count;
	int m_object6Count;
	int m_object7Count;
	int m_object8Count;
	int m_object9Count;
	int m_object10Count;
	
	char m_string[100];
	bool m_hasCollidedwithExitSensor;
	bool m_potionCollected;
	bool m_npcInteracted;

	Collision m_col;
	Sword *sword;
	Potion *potion;
	NPC *npc;
	ExitSensor *exitSensor;

	vector<NPC*> m_npcList;
	vector<Sprite> m_objList;
	vector<ExitSensor*>m_map1ExitSensorList;
	vector<ExitSensor*>m_map2ExitSensorList;
	vector<ExitSensor*>m_map3ExitSensorList;

	bool swordCreated;
	bool potionCreated;
	bool m_swordDisable;
	bool m_potionDisable;
	bool m_invDisable;
	bool ipressed;
	bool m_battleStart;
	bool m_drawSword;
	int m_collidingIndex;
	ExitSensor* collidedSensor;
	NPC* m_collidedNPC;
	bool scripting;
	int scriptedNPC;
	Comment_System m_commentSystem;
	int m_objectiveComplete1;
public:
	void Update(Player player);
	Object(lua_State *l);
	~Object();
	bool LoadObjects(VideoMode&, RenderWindow*,string filename, Player *player, lua_State *L);
	bool RenderObjects(VideoMode&, RenderWindow*, Player *player, lua_State *l);
	int HasCollidedWithObject(Player player, RenderWindow *win);
	bool IsDisabled();
	void Enable();
	vector<Sprite> GetObjList();
	Sword* GetSword();
	bool HasCollidedWithExitSensor(Player player);
	ExitSensor* GetCollidedExitSensor(Player player);
	NPC* GetCollidedNPC();
	void ClearSensors();
	bool IsBattling();
	void StopBattle();
	int GetCollidingIndex();
	void RemoveNPC(int index, RenderWindow *win, Player *player);
	void NotDisabled();
	void DrawCommentSystem();
};
#endif