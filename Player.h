/*
	
	$Player.h

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

#ifndef PLAYER_H_
#define PLAYER_H_
//Obviously this file will be used especially for our player
#include "BaseEntity.h"
#include "AniSprite.h"
#include "Character.h"
#include "StateManager.h"
#include "PlayerStates.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "LScripter.h"
using namespace sf;
using namespace std;
enum
{
	affinity_good,
	affinity_evil,
	affinity_neutral
};
class Collectible;
class Player:public Character
{
private:
	
	int m_magicLevel;
	int m_affinity;
	int m_currentMap;
	vector<Collectible*> m_inventory;
	Image m_battleImage;
	Sprite m_battleSprite;
	StateManager<Player> *m_stateManager;
	bool m_hasPotion;
	int m_potionCount;
	LScripter scripter;
	lua_State *L;
public:
	Player(lua_State *l, int id, int map):Character(id)
	{
		L = l;
		m_stateManager = new StateManager<Player>(this);
		m_stateManager->SetCurrentState(PlayerAlive::Instance());
		m_goldCarried = 10;
		m_health = 100;
		m_currentMap = map;
		m_magicLevel  = 0;
		m_affinity = 50; // less than 50 is good, more than 50 is evil and 50 is neutral
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\playerdown.png");
		m_battleImage.LoadFromFile("..\\data\\Images\\Player.png");
		m_battleSprite.SetImage(m_battleImage);
		m_battleSprite.SetPosition(700.0f, 300.0f);
		m_playerSp.SetImage(m_playerImgUp);
		m_up = true;
		m_down = false;
		m_right = false;
		m_left = false;
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_hasPotion = false;
		m_potionCount = 0;
	}
	void Default()
	{
		m_stateManager = new StateManager<Player>(this);
		m_stateManager->SetCurrentState(PlayerAlive::Instance());
		m_goldCarried = 10;
		m_health = 100;
//		m_currentMap = map;
		m_magicLevel  = 0;
		m_affinity = 50; // less than 50 is good, more than 50 is evil and 50 is neutral
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\playerdown.png");
		m_battleImage.LoadFromFile("..\\data\\Images\\Player.png");
		m_battleSprite.SetImage(m_battleImage);
		m_battleSprite.SetPosition(700.0f, 300.0f);
		m_playerSp.SetImage(m_playerImgUp);
		m_up = true;
		m_down = false;
		m_right = false;
		m_left = false;
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
	}

	void PotionCollected()
	{
		m_hasPotion = true;
		m_potionCount++;
	}
	void NoPotion()
	{
		m_hasPotion = false;
	}
	void PotionUsed()
	{
		m_potionCount--;
		if(m_potionCount<=0) m_potionCount = 0;
		if(m_potionCount == 0) m_hasPotion = false;
	}
	bool HasPotion()
	{
		return m_hasPotion;
	}


	void ChangeMap(int map)
	{
		m_currentMap = map;
	}

	int GetAffinity()
	{
		if(m_affinity<50)
		{
			return affinity_good;
		}
		else if(m_affinity > 50)
		{
			return affinity_evil;
		}
		else
		{
			return affinity_neutral;
		}
	}

	void UpdateAI()
	{
		m_stateManager->Update();
	}

	StateManager<Player>* GetStateManager()
	{
		return m_stateManager;
	}

	void MakeAffinityEvil()
	{
		m_affinity += 10;
	}

	void MakeAffinityGood()
	{
		m_affinity -= 10;
	}
	
	void AddHealth(int x)
	{
		m_health += x;
		if(m_health>100) m_health = 100;
	}
	
	
	int GetGold()
	{
		return m_goldCarried;
	}
	
	void SetGold(int f)
	{
		m_goldCarried = f; 
	}
	int GetMagicLevel()
	{
		return m_magicLevel;
	}
	void AddToInventory(Collectible *col)
	{
		m_inventory.push_back(col);

	}
	void DrawInventory(RenderWindow *win)
	{
	}
	void DrawBattleImage(RenderWindow *win, float startx, float starty)
	{
		m_battleSprite.SetPosition(700, starty + 300);
		win->Draw(m_battleSprite);
	}
	void RegisterClassToLua()
	{
		luabind::module(L)
		[
		luabind::class_<Player>("Player")
		//.def(luabind::constructor<string, float, float>())
		.def("GetGold", &Player::GetGold)
		];

	}
	void RunGoldScript()
	{
		scripter.RunScript(L, "GetGoldScript.lua", true);
		luabind::call_function<void>(L, "getg", this);
	}

	int GetCurrentMap()
	{
		return m_currentMap;
	}

	bool IsUp()
	{
		return m_up;
	}
	bool IsDown()
	{
		return m_down;
	}
};
#endif