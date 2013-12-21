/*
	
	$NPCInteraction.h

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


#ifndef NPCINTERACTION_H_
#define NPCINTERACTION_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
using namespace std;
using namespace sf;

class NPCInteraction
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
	String m_choice6;
	bool up;
	bool down;
	int m_choiceCount;

	String m_info;

public:
	NPCInteraction()
	{
		m_hasInteracted = false;
		up = false;
		down = false;
	}

	void InitializeMenu(int id, string i)
	{
		
		m_info.SetText(i);
		m_info.SetPosition(225,200);
		m_bgImg.LoadFromFile("..\\data\\Images\\objectmenu.png");
		m_bgSp.SetImage(m_bgImg);
		m_navImg.LoadFromFile("..\\data\\Images\\menunav.png");
		m_navSp.SetImage(m_navImg);

		m_choice1.SetText("Threaten");
		m_choice2.SetText("Beat");
		m_choice3.SetText("Kill");
		m_choice4.SetText("Steal");
		m_choice5.SetText("Talk");
		m_choice6.SetText("Help");

		m_bgSp.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSp.SetPosition(400, 300);
		m_choice1.SetPosition(m_bgSp.GetPosition().x - 50, m_bgSp.GetPosition().y - 50);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 50);
		m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 50);
		m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 50);
		m_choice5.SetPosition(m_choice4.GetPosition().x, m_choice4.GetPosition().y + 50);
		m_choice6.SetPosition(m_choice5.GetPosition().x, m_choice5.GetPosition().y + 50);
		m_navSp.SetPosition(m_choice1.GetPosition().x - 50, m_choice1.GetPosition().y);
		
	}

	void Run(int id,RenderWindow *win, Player *player)
	{
		
			if(win->GetInput().IsKeyDown(Key::Down) && down == false)
			{
				
				if(m_navSp.GetPosition().y<m_choice6.GetPosition().y)
				{
					m_navSp.SetPosition(m_navSp.GetPosition().x, m_navSp.GetPosition().y + 50);
					down = true;
				
				}
			}
			if(!win->GetInput().IsKeyDown(Key::Down) && down == true)
			{
				down = false;
			}
			if(win->GetInput().IsKeyDown(Key::Up) && up == false)
			{
				
				if(m_navSp.GetPosition().y>m_choice1.GetPosition().y)
				{
					m_navSp.SetPosition(m_navSp.GetPosition().x, m_navSp.GetPosition().y - 50);
					up = true;
				}
				
			}
			if(!win->GetInput().IsKeyDown(Key::Up) && up == true)
			{
				up = false;
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

	int GetNavLocation(int id)
	{
		if(m_navSp.GetPosition().y == m_choice1.GetPosition().y)
		{
			return 1;
		}
		if(m_navSp.GetPosition().y == m_choice2.GetPosition().y)
		{
			return 2;
		}
		if(m_navSp.GetPosition().y == m_choice3.GetPosition().y)
		{
			return 3;
		}
		if(m_navSp.GetPosition().y == m_choice4.GetPosition().y)
		{
			return 4;
		}
		if(m_navSp.GetPosition().y == m_choice5.GetPosition().y)
		{
			return 5;
		}
		if(m_navSp.GetPosition().y == m_choice6.GetPosition().y)
		{
			return 6;
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

	void UpdateMenu(View view)
	{
		m_bgSp.SetPosition(view.GetCenter().x, view.GetCenter().y);
		m_choice1.SetPosition(m_bgSp.GetPosition().x - 50, m_bgSp.GetPosition().y - 50);
		m_info.SetPosition(m_choice1.GetPosition().x - 150,m_choice1.GetPosition().y - 50);
		m_choice2.SetPosition(m_choice1.GetPosition().x, m_choice1.GetPosition().y + 50);
		m_choice3.SetPosition(m_choice2.GetPosition().x, m_choice2.GetPosition().y + 50);
		m_choice4.SetPosition(m_choice3.GetPosition().x, m_choice3.GetPosition().y + 50);
		m_choice5.SetPosition(m_choice4.GetPosition().x, m_choice4.GetPosition().y + 50);
		m_choice6.SetPosition(m_choice5.GetPosition().x, m_choice5.GetPosition().y + 50);
		m_navSp.SetPosition(m_choice1.GetPosition().x - 70, m_choice1.GetPosition().y);
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
		win->Draw(m_choice6);
	}

};


#endif