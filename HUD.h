/*
	
	$HUD.h

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

#ifndef HUD_H_
#define HUD_H_
//This file should contain all the HUD related codes and nothing else
#include "Player.h"
class HUD
{
private:
	Image m_gold;
	Image m_health;
	Image m_magicLevel;
	Image m_affinityGood;
	Image m_affinityEvil;
	Image m_affinityNeutral;
	Sprite m_affinity;
	Sprite m_goldSp;
	Sprite m_healthSp;
	Sprite m_magicLevelSp;
	String gold;
	string g, h, m;
	char buffer[5];
	String health;
	String magicLevel;
public:
	HUD()
	{
		m_gold.LoadFromFile("..\\data\\Images\\gol.png");
		m_health.LoadFromFile("..\\data\\Images\\health.png");
		m_magicLevel.LoadFromFile("..\\data\\Images\\magic.png");
		m_affinityGood.LoadFromFile("..\\data\\Images\\good.png");
		m_affinityEvil.LoadFromFile("..\\data\\Images\\bad.png");
		m_affinityNeutral.LoadFromFile("..\\data\\Images\\neutral.png");
		
		m_goldSp.SetImage(m_gold);
		gold.SetPosition(35,0);
		m_healthSp.SetImage(m_health);
		m_healthSp.SetPosition(100,0);
		health.SetPosition(135,0);
		m_magicLevelSp.SetImage(m_magicLevel);
		m_magicLevelSp.SetPosition(200,0);
		magicLevel.SetPosition(235,0);
		m_affinity.SetPosition(335,0);
	}


	void Update(Player *player)
	{
		g = _itoa(player->GetGold(),buffer,10);
		m = _itoa(player->GetMagicLevel(), buffer, 10);
		h = _itoa(player->GetHealth(), buffer, 10);
		
		gold.SetText(g);
		magicLevel.SetText(m);
		health.SetText(h);
		if(player->GetAffinity() == affinity_good)
		{
			m_affinity.SetImage(m_affinityGood);
		}
		else if(player->GetAffinity() == affinity_evil)
		{
			m_affinity.SetImage(m_affinityEvil);
		}
		else if(player->GetAffinity() == affinity_neutral)
		{
			m_affinity.SetImage(m_affinityNeutral);
		}
		
	}
	void Draw(RenderWindow *win)
	{
		win->Draw(m_goldSp);
		win->Draw(gold);
		win->Draw(m_healthSp);
		win->Draw(health);
		win->Draw(m_magicLevelSp);
		win->Draw(magicLevel);
		win->Draw(m_affinity);
	}

	void MoveUp(RenderWindow *win)
	{
		m_goldSp.Move(0, -100*win->GetFrameTime());
		gold.Move(0, -100*win->GetFrameTime());
		m_healthSp.Move(0, -100*win->GetFrameTime());
		health.Move(0, -100*win->GetFrameTime());
		m_magicLevelSp.Move(0, -100*win->GetFrameTime());
		magicLevel.Move(0, -100*win->GetFrameTime());
		m_affinity.Move(0, -100*win->GetFrameTime());

	}
	void MoveDown(RenderWindow *win)
	{
		m_goldSp.Move(0, 100*win->GetFrameTime());
		gold.Move(0, 100*win->GetFrameTime());
		m_healthSp.Move(0, 100*win->GetFrameTime());
		health.Move(0, 100*win->GetFrameTime());
		m_magicLevelSp.Move(0, 100*win->GetFrameTime());
		magicLevel.Move(0, 100*win->GetFrameTime());
		m_affinity.Move(0, 100*win->GetFrameTime());

	}
};
#endif