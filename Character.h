/*
	
	$Character.h

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

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "BaseEntity.h"
#include "AniSprite.h"
#include "StateManager.h"
#include "CharacterStates.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Character:public BaseEntity
{
public:
	Image m_playerImgLeft;
	Image m_playerImgRight;
	Image m_playerImgUp;
	Image m_playerImgDown;
	AniSprite m_playerSp;
	float m_playerMoveSpeed;
	int m_health;
	int m_goldCarried;

	bool m_up;
	bool m_down;
	bool m_right;
	bool m_left;

	View m_view;
	bool m_interacting;
	StateManager<Character> *m_interactiveStateManager;

	Character(int id):BaseEntity(id)
	{
		m_view.SetCenter(400,300);
		m_view.SetHalfSize(400, 300);

		m_interacting = false;
		m_interactiveStateManager = new StateManager<Character>(this);
		m_interactiveStateManager->SetCurrentState(NotInteracting::Instance());
	}

	View GetView()
	{
		return m_view;
	}

	void Interacting()
	{
		m_interacting = true;
	}

	void NotInteracting()
	{
		m_interacting = false;
	}

	StateManager<Character>* GetInteractiveStateManager()
	{
		return m_interactiveStateManager;
	}
	void UpdateAI()
	{
		m_interactiveStateManager->Update();
	}
	
	void MoveUp(RenderWindow *win)
	{
		m_playerSp.SetImage(m_playerImgUp);
		m_playerSp.Move(0, -m_playerMoveSpeed*win->GetFrameTime());
		m_playerSp.Update();

		if(m_view.GetCenter().y - m_view.GetHalfSize().y > -160)
		{
			std::cout<<"Center:"<<m_view.GetCenter().y<<std::endl<<"Half:"<<m_view.GetHalfSize().y<<std::endl;
			m_view.Move(0, -m_playerMoveSpeed*win->GetFrameTime());
		}

		m_up = true;
		m_down = false;
		m_right = false;
		m_left = false;
		
	}
	void MoveDown(RenderWindow *win)
	{
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.Move(0,m_playerMoveSpeed*win->GetFrameTime());
		m_playerSp.Update();

		if(m_view.GetCenter().y <= 300)
		{
			std::cout<<"Center:"<<m_view.GetCenter().y<<std::endl<<"Half:"<<m_view.GetHalfSize().y<<std::endl;
			m_view.Move(0, m_playerMoveSpeed*win->GetFrameTime());
		}

		m_up = false;
		m_down = true;
		m_right = false;
		m_left = false;
	}
	void MoveLeft(RenderWindow *win)
	{
		m_playerSp.SetImage(m_playerImgLeft);
		m_playerSp.Move(-m_playerMoveSpeed*win->GetFrameTime(),0);
		m_playerSp.Update();

		m_up = false;
		m_down = false;
		m_right = false;
		m_left = true;
	}
	void SetHealth(int health)
	{
		m_health += health;
	}
	void DecreaseHealth(int health)
	{
		m_health-=health;
		if(m_health<0) m_health = 0;
	}
	void MoveRight(RenderWindow *win)
	{
		m_playerSp.SetImage(m_playerImgRight);
		m_playerSp.Move(m_playerMoveSpeed*win->GetFrameTime(),0);
		m_playerSp.Update();

		m_up = false;
		m_down = false;
		m_right = true;
		m_left = false;
	}
	void Draw(VideoMode &vMode, RenderWindow *win)
	{
		win->Draw(m_playerSp);
	}
	void Update()
	{
		m_playerSp.Update();
	}
	void SetPosition(float x, float y)
	{
		
		m_playerSp.SetPosition(x,y);
	}

	void SetView(float x, float y)
	{
		m_view.SetCenter(x,y);
		m_view.SetHalfSize(400,300);
	}

	Sprite GetSprite()
	{
		return m_playerSp;
	}
	
	int GetHealth()
	{
		return m_health;
	}
};

#endif