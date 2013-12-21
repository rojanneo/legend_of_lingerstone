/*
	
	$Menu2.h

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

#ifndef MENU
#define MENU
#include<SFML/Graphics.hpp>
#include "Sub_menu.h"
#include"Player.h"
#include"Enemy.h"
#define SUB 6

class BMenu
{
private:
	Sub_menu sub_menu[SUB];
	bool is_active;
	int button_no;
	int sub_button_no;
	float startx;
	float starty;
	sf::Event e;
public:
	BMenu()
	{
		
	}
	void Initialize(float startx, float starty)
	{
		this->startx=startx;
		this->starty = starty;
		float x = startx + 3;
		float y = starty + 550;
		is_active = false;
		button_no = 0;
		for(int i= 0;i<SUB;i++)
		{
			sub_menu[i].is_active(false);
			sub_menu[i].set_position(x,y);
			x = x+133;
		}
	}
	void sub_menu_name(int i,int j,std::string sth)
	{
		sub_menu[i].set_butt_name(sth,j);
	}
	void setbuttonname(int i,std::string sth)
	{
		sub_menu[i].set_name(sth);
	}
	
	std::string Run(sf::VideoMode &vid,sf::RenderWindow &win,bool Players_turn,sf::Sprite backsp,Enemy &enemy,Player &player,sf::Image *h_back,sf::Image *health,sf::Image *blank)
	{
		sf::Sprite enemy_backsp;
		sf::Sprite player_backsp;
		sf::Sprite health_enemy[100];
		sf::Sprite health_player[100];
		sf::Sprite enemy_blank;
		sf::Sprite player_blank;
		enemy_blank.SetImage(*blank);
		player_blank.SetImage(*blank);
		enemy_backsp.SetPosition(startx+75.0f, starty+10.0f);
		player_backsp.SetPosition(startx+500.0f, starty+10.0f);
		player_blank.SetPosition(startx+425.0f,starty);
		enemy_blank.SetPosition(startx,starty);
		float x2 = 75;
		float x1 = 500;
	for(int j=0;j<100;j++)
	{
		health_enemy[j].SetImage(*health);
		health_player[j].SetImage(*health);
		if(j==0)
		{
			health_enemy[j].SetPosition(startx+75.0f,starty+10.0f);
			health_player[j].SetPosition(startx+500.0f,starty+10.0f);
		}
		else
		{
			x2=x2+3;
			x1=x1+3;
			health_enemy[j].SetPosition(startx+x2,starty+10.0f);
			health_player[j].SetPosition(startx+x1,starty+10.0f);
		}
	}
	enemy_backsp.SetImage(*h_back);
		player_backsp.SetImage(*h_back);

		button_no = 0;
		float x = 0;
		float y = 0;
		is_active = true;
		int i = 0;
		bool up =false;
		bool down =false;
		bool right = false;
		bool left = false;
		int butt_no = 0;
		sub_menu[0].is_active(true);
		bool sub_menu_selected = true;
		for(int j = 1;j<6;j++)
		{
			sub_menu[j].is_active(false);
		}
		while(win.IsOpened()&&Players_turn)
		{
		//	if(enemy.GetHealth()<=0) return "Break";
					while (win.GetEvent(e))
			        {
						if (e.Type == sf::Event::Closed)
							return "Exits";
						if(win.GetInput().IsKeyDown(Key::Escape))
							return "Break";
					}
			

			if(win.GetInput().IsKeyDown(sf::Key::Right) && button_no<(SUB-1)&&is_active == true && right == false)
			{
				sub_menu[++button_no].is_active( true);
				sub_menu[button_no-1].is_active(false);
				right = true;
			}
			else if(!win.GetInput().IsKeyDown(Key::Right) && right == true)
			{
				right = false;
			}
			else if(win.GetInput().IsKeyDown(sf::Key::Left) && button_no>0&&is_active == true && left == false)
			{
				sub_menu[--button_no].is_active( true);
				sub_menu[button_no+1].is_active(false);
				left = true;
			}
			else if(!win.GetInput().IsKeyDown(Key::Left) && left == true)
			{
				left = false;
			}
			if(win.GetInput().IsKeyDown(sf::Key::Up) && up== false)
			{
				up = true;
				if(sub_menu_selected==true)
				{
					butt_no = i;
					i = i+1;
					is_active = false;
					sub_menu_selected=false;
				}
				else if(sub_menu_selected==false&&i<sub_menu[button_no].no_of_buttons())
				{
					butt_no = i;
					i = i+1;
				}
				
				
			}
			if(!win.GetInput().IsKeyDown(sf::Key::Up) && up== true)
			{
				up = false;
			}
			if(win.GetInput().IsKeyDown(sf::Key::Down) && down == false)
			{
				down  = true;
				if(sub_menu_selected==false&&butt_no >0&&butt_no==sub_menu[button_no].no_of_buttons()-1)
				{
					i  = sub_menu[button_no].no_of_buttons()-1;
					butt_no = --i;
				}
				else if(sub_menu_selected==false&&butt_no >0&&butt_no<(sub_menu[button_no].no_of_buttons()-1))
				{
					butt_no = --i;
				}
				else if(sub_menu_selected==false&&butt_no==0)
				{
					sub_menu[button_no].set_button(false,butt_no);
					sub_menu_selected=true;
					is_active = true;
					i=0;
				}
				}
			else if(!win.GetInput().IsKeyDown(sf::Key::Down) && down== true)
			{
				down = false;
				
			}
			
			if(win.GetInput().IsKeyDown(sf::Key::Return) && is_active== false)
			{
				string name = sub_menu[button_no].button_name(butt_no);
				if(name == "Exit") return "Break";
				else return sub_menu[button_no].button_name(butt_no);
			}
			win.Draw(backsp);
			player.DrawBattleImage(&win, startx, starty);
			enemy.Draw(vid,&win, startx, starty);
			for(int i=0;i<6;i++)
			{
				if(sub_menu[i].active() == true)
				{
					sub_menu[i].set_image("../data/Images/s_button.png");
				}
				else
				{
					sub_menu[i].set_image("../data/Images/button.png");
				}
				sub_menu[i].Draw(vid,&win);
		
			
			for(int j = 0;j<sub_menu[i].no_of_buttons();j++)
				{
					if (sub_menu[i].active()&&j==butt_no&&is_active==false)
					{
						sub_menu[i].set_button(true,j);
						sub_menu[i].set_but_image(j,"../data/Images/s_button.png");
						sub_menu[i].draw_button_battle_system(i,j,vid,&win,(player.GetView().GetCenter().x-player.GetView().GetHalfSize().x),(player.GetView().GetCenter().y-player.GetView().GetHalfSize().y));
					}
					else if(sub_menu[i].active()&&j!=butt_no&&is_active==false)
					{
						sub_menu[i].set_button(false,j);
						sub_menu[i].set_but_image(j,"../data/Images/button.png");
						sub_menu[i].draw_button_battle_system(i,j,vid,&win,(player.GetView().GetCenter().x-player.GetView().GetHalfSize().x),(player.GetView().GetCenter().y-player.GetView().GetHalfSize().y));
					}
				}
			}
			win.Draw(enemy_blank);
			win.Draw(player_blank);
			win.Draw(enemy_backsp);
			win.Draw(player_backsp);
			for(int i = 0; i<player.GetHealth(); i++)
			{
				win.Draw(health_player[i]);
			}
			for(int i = 0; i<enemy.GetHealth(); i++)
			{
				win.Draw(health_enemy[i]);
			}

			win.Display();
		}
		return 0;
	}


};
#endif