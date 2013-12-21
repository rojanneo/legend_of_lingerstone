/*
	
	$InteractiveObjects.h

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

#ifndef INTERACTIVE_OBJECTS_H_
#define INTERACTIVE_OBJECTS_H_
#include "BaseEntity.h"
#include "StateManager.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "InteractiveObjectsStates.h"
//class InteractiveObjectsStates;
using namespace sf;
using namespace std;
//Class to classify an object as interactive
//Do not create objects for this class
//only use this class as parent class

class InteractiveObjects:public BaseEntity
{
protected:
	bool m_hasInteracted;
	Image m_bgImg;
	Image m_navImg;
	Sprite m_bgSp;
	Sprite m_navSp;
	String m_choice1;
	String m_choice2;
	String m_choice3;
	String m_choice4;
	String m_choice5;
	bool up;
	bool down;
	int m_choiceCount;

	String m_info;

	StateManager<InteractiveObjects> *m_stateManager;
public:
	InteractiveObjects(int id):BaseEntity(id)
	{
		m_hasInteracted = false;
		up = false;
		down = false;
		m_stateManager = new StateManager<InteractiveObjects>(this);
		m_stateManager->SetCurrentState(NotInteracted::Instance());
	}
	void UpdateAI()
	{
		m_stateManager->Update();
	}
	void InitializeMenu(int c, string i, string c1, string c2, string c3, string c4, string c5)
	{
	
		m_choiceCount = c;
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);
		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);
		m_choice1.SetText(c1);
		m_choice2.SetText(c2);
		m_choice3.SetText(c3);
		m_choice4.SetText(c4);
		m_choice5.SetText(c5);
		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
		m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
		m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 100);
		m_choice5.SetPosition(m_choice4.GetPosition().x, m_choice4.GetPosition().y + 100);
	}
	void InitializeMenu(int c, string i, string c1, string c2, string c3, string c4)
	{
		m_choiceCount = c;
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);

		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);
		m_choice1.SetText(c1);
		m_choice2.SetText(c2);
		m_choice3.SetText(c3);
		m_choice4.SetText(c4);
		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
		m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
		m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 100);
		m_choice5.SetPosition(m_choice4.GetPosition().x, m_choice4.GetPosition().y + 100);
	}
	void InitializeMenu(int c, string i, string c1, string c2, string c3)
	{
		m_choiceCount = c;
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);

		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);
		m_choice1.SetText(c1);
		m_choice2.SetText(c2);
		m_choice3.SetText(c3);
		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(300, 300);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
		m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
		m_navSp.SetPosition(m_choice1.GetPosition().x - m_navSp.GetSize().x, m_choice1.GetPosition().y + 15);
	}
	void InitializeMenu(int c, string i, string c1, string c2)
	{
		m_choiceCount = c;
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);

		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);

		m_choice1.SetText(c1);
		m_choice2.SetText(c2);
		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(300,300);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
		m_navSp.SetPosition(m_choice1.GetPosition().x - m_navSp.GetSize().x, m_choice1.GetPosition().y + 15);
	}
	void InitializeMenu(int c, string i)
	{
		m_choiceCount = c;
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);

		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);

		m_choice1.SetText("Pick");
		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(300, 300);

		m_navSp.SetPosition(m_choice1.GetPosition().x - m_navSp.GetSize().x, m_choice1.GetPosition().y + 15);
	}

	void Run(RenderWindow *win, Player *player)
	{
		if(m_choiceCount == 2)
		{
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				Reset(player);
			}
			if(win->GetInput().IsKeyDown(Key::Down))
			{
				
				m_navSp.SetPosition(m_choice2.GetPosition().x - m_navSp.GetSize().x, m_choice2.GetPosition().y + 15);
			}
			if(win->GetInput().IsKeyDown(Key::Up))
			{
				m_navSp.SetPosition(m_choice1.GetPosition().x - m_navSp.GetSize().x, m_choice1.GetPosition().y + 15);
			}
		}
		else if(m_choiceCount == 3)
		{
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				Reset(player);
			}
			if(win->GetInput().IsKeyDown(Key::Down) && down == false)
			{
				if(m_navSp.GetPosition().y<=m_choice3.GetPosition().y)
				{
				m_navSp.SetPosition(m_navSp.GetPosition().x, m_navSp.GetPosition().y + 100);
				down = true;
				}
			}
			if(!win->GetInput().IsKeyDown(Key::Down) && down == true)
			{
				down = false;
			}
			if(win->GetInput().IsKeyDown(Key::Up) && up == false)
			{
				if(m_navSp.GetPosition().y>=m_choice1.GetPosition().y)
				{
					m_navSp.SetPosition(m_navSp.GetPosition().x, m_navSp.GetPosition().y - 100);
					up = true;
				}
			}
			if(!win->GetInput().IsKeyDown(Key::Up) && up == true)
			{
				up = false;
			}
		}
	}

	void Reset(Player *player)
	{
		m_hasInteracted = false;
		if(player->m_up)
		{
		player->SetPosition(player->GetSprite().GetPosition().x, player->GetSprite().GetPosition().y+ 10);
		}
		else if(player->m_down)
		{
		player->SetPosition(player->GetSprite().GetPosition().x, player->GetSprite().GetPosition().y - 10);
		}
		else if(player->m_right)
		{
		player->SetPosition(player->GetSprite().GetPosition().x - 10, player->GetSprite().GetPosition().y);
		}
		else if(player->m_left)
		{
		player->SetPosition(player->GetSprite().GetPosition().x + 10, player->GetSprite().GetPosition().y);
		}

	}

	int GetNavLocation()
	{
		if(m_navSp.GetPosition().y == m_choice1.GetPosition().y + 15)
		{
			return 1;
		}
		if(m_navSp.GetPosition().y == m_choice2.GetPosition().y + 15)
		{
			return 2;
		}
		if(m_navSp.GetPosition().y == m_choice3.GetPosition().y + 15)
		{
			return 3;
		}
		return 0;
	}
	bool HasInteracted()
	{
		return m_hasInteracted;
	}
	void Interacted()
	{
		m_hasInteracted = true;
		
	}
	void NotInteracted()
	{
		m_hasInteracted = false;
	}
	StateManager<InteractiveObjects>* GetStateManager()
	{
		return m_stateManager;
	}

	void UpdateMenu(int ch, View view)
	{
		switch(ch)
		{
		case 5:
			m_info.SetPosition(225,200);
			m_bgSp.SetPosition(view.GetCenter());
			m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y/2 + 100);
			m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
			m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
			m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 100);
			m_choice5.SetPosition(m_choice4.GetPosition().x, m_choice4.GetPosition().y + 100);
			break;
		case 4:
			m_info.SetPosition(225,200);
			m_bgSp.SetPosition(view.GetCenter());
			m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y);
			m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
			m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
			m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 100);
			break;
		case 3:
			
			m_bgSp.SetPosition(view.GetCenter());
			m_choice1.SetPosition((view.GetCenter().x - m_bgSp.GetSize().x/2 + 150), (view.GetCenter().y - m_bgSp.GetSize().y/2 + 300));
			m_info.SetPosition(225,m_choice1.GetPosition().y - 100);
			m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
			m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 100);
			m_navSp.SetPosition(m_choice1.GetPosition().x - m_navSp.GetSize().x, m_choice1.GetPosition().y +15);
			break;
		case 2:
			m_info.SetPosition(225,200);
			m_bgSp.SetPosition(view.GetCenter());
			m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y);
			m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 100);
			break;
		default:
			m_info.SetPosition(225,200);
			m_bgSp.SetPosition(view.GetCenter());
			m_choice1.SetPosition(m_bgSp.GetPosition().x - m_bgSp.GetSize().x + 100, m_bgSp.GetPosition().y - m_bgSp.GetSize().y);
			break;	
		
		
		}
	}

	void DrawMenu(RenderWindow *win)
	{
		win->Draw(m_bgSp);
		win->Draw(m_navSp);
		win->Draw(m_info);
		win->Draw(m_choice1);
		win->Draw(m_choice2);
		win->Draw(m_choice3);
		win->Draw(m_choice4);
		win->Draw(m_choice5);
	}
};
#endif