#ifndef SUB_MENU
#define SUB_MENU
#include<iostream>
#include<sfml/Graphics.hpp>
#include"Buttons.h"


class Sub_menu
{
private:
	Button buttons[6];
	bool is_selected;
	int no_buttons;
	std::string name;
	sf::Image sub_menu;
	sf::Sprite subsp;
	sf::String m_name;
	sf::Image Background;
	sf::Sprite Backgroundsp;
public:
	Sub_menu()
	{
		is_selected = false;
		sub_menu.LoadFromFile("../data/Images/button.png");
		subsp.SetImage(sub_menu);
		Background.LoadFromFile("../data/Images/Background.png");
		Backgroundsp.SetImage(Background);
	}
	bool but_sel(int i)
	{
		return buttons[i].selected();
	}
	void set_position(float x,float y)
	{
		subsp.SetPosition(x,y);
		m_name.SetPosition(x,y);
	}
	void is_active(bool selected)
	{
		is_selected = selected;
	}
	bool active()
	{
		return is_selected;
	}
	int no_of_buttons()
	{
		return no_buttons;
	}
	void set_image(std::string sth)
	{
		sub_menu.LoadFromFile(sth);
		subsp.SetImage(sub_menu);
	}
	void set_button(bool s,int i)
	{
		buttons[i].is_active(s);
	}
	void set_butt_name(std::string sth,int i)
	{
		no_buttons = i+1;
		buttons[i].select(true);
		buttons[i].set_name(sth); 
	}
	void draw_button_battle_system(int i,int j,sf::VideoMode &vid,sf::RenderWindow *win, float startx, float starty)
	{
		float x;
		float y;
		x = startx + (float)i*131+3*(i+1);
		y = starty + (float)550-((j+1)*40);
		buttons[j].Draw(vid,win,x,y);
	}
	void draw_button_comment_system(int j,sf::VideoMode &vid,sf::RenderWindow *win,float startx, float starty)
	{
		float x;
		float y;
		x = startx + 3;
		y = starty + (float) 240+(j*41);
		buttons[j].Draw(vid,win,x,y);

	}
	std::string button_name(int i)
	{
		return buttons[i].button_name();
	}
	bool but_active(int i)
	{
		return buttons[i].is_active();
	}
	void set_but_image(int i,std::string sth)
	{
		buttons[i].set_image(sth);
	}
	void set_name(std::string sth)
	{
		name = sth;
		m_name.SetText(name);
	}
	std::string menu_name()
	{
		return name;
	}
	void Draw(sf::VideoMode &vid,sf::RenderWindow *win)
	{
		win->Draw(subsp);
		win->Draw(m_name);
	}
};
#endif