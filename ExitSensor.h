/*
	
	$ExitSensors.h

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

#ifndef EXIT_SENSOR_H_
#define EXIT_SENSOR_H_
#include "BaseEntity.h"
#include <SFML\Graphics.hpp>
class ExitSensor:public BaseEntity
{
private:
	Image m_image;
	Sprite m_sprite;
	int m_destination;
	Image m_bgImage;
	Sprite m_bgSprite;
	String m_message;
	bool m_objectiveComplete;
	bool m_running;
	string m_textMessage;
public:
	ExitSensor(lua_State *L, int id, int destination, float posx, float posy):BaseEntity(id)
	{	
		m_running = false;
		m_objectiveComplete = false;
		m_textMessage = "You cannot leave the area yet";
		m_image.LoadFromFile("..\\data\\Images\\exitsensorhor.png");
		m_sprite.SetImage(m_image);
		m_bgImage.LoadFromFile("..\\data\\Images\\dialogueMenu.png");
		m_bgSprite.SetImage(m_bgImage);
		m_bgSprite.SetCenter((float)m_bgImage.GetWidth()/2, (float)m_bgImage.GetHeight()/2);
		m_bgSprite.SetPosition(400,500);
		m_message.SetText(m_textMessage);
		m_message.SetPosition(m_bgSprite.GetPosition().x - 300, m_bgSprite.GetPosition().y);
		m_sprite.SetPosition(posx, posy);
		m_destination = destination - 100;
	
		luabind::module(L)
			[
				luabind::class_<ExitSensor>("ExitSensor")
				.def("ObjectiveComplete", &ExitSensor::ObjectiveComplete)
			];
	}
	void Reset(Player *player)
	{
		if(player->IsUp()) player->SetPosition(player->GetSprite().GetPosition().x , player->GetSprite().GetPosition().y + 20);
		else if(player->IsDown()) player->SetPosition(player->GetSprite().GetPosition().x , player->GetSprite().GetPosition().y - 20);
	}

	void SetDestination(int id)
	{
		m_destination = id;
	}
	int GetDestinationID()
	{
		return m_destination;
	}
	void Draw(RenderWindow* win)
	{
		win->Draw(m_sprite);
	}
	Sprite GetSprite()
	{
		return m_sprite;
	}
	bool IsObjectiveComplete()
	{
		return m_objectiveComplete;
	}
	void ObjectiveComplete()
	{
		m_objectiveComplete = true;
	}

	bool Run(RenderWindow *win)
	{
		if(win->GetInput().IsKeyDown(Key::Escape)) 
		{
			m_running = false;
			return false;
		}
		return true;
	}

	void NotRunning()
	{
		m_running = false;
	}

	void StartRunning()
	{
		m_running = true;
	}

	bool IsRunning()
	{
		return m_running;
	}

	void UpdatePosition(View view)
	{
		m_bgSprite.SetPosition(view.GetCenter().x,view.GetCenter().y+200);
		m_message.SetPosition(m_bgSprite.GetPosition().x - 300, m_bgSprite.GetPosition().y);
	}

	void DrawMessage(RenderWindow *win)
	{

		win->Draw(m_bgSprite);
		win->Draw(m_message);
	}

};
#endif