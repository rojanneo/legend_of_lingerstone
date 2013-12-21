#ifndef BUTTONS
#define BUTTONS
#include<iostream>
#include<sfml/Graphics.hpp>
class Button
{
private:
	std::string name;
	bool is_selected;
	bool active;
	sf::Image buttonImg;
	sf::Sprite buttonsp;
	sf::String m_buttonName;
public:
	Button()
	{
		is_selected = false;
		buttonImg.LoadFromFile("../data/Images/button.png");
		buttonsp.SetImage(buttonImg);
		active = false;
	}
	std::string button_name()
	{
		return name;
	}
	void set_image(std::string sth)
	{
			buttonImg.LoadFromFile(sth);
			buttonsp.SetImage(buttonImg);
	}
	bool is_active()
	{
		return active;
	}
	void Draw(sf::VideoMode &vid,sf::RenderWindow *win,float x,float y)
	{
		buttonsp.SetPosition(x,y);
		m_buttonName.SetPosition(x,y);
		win->Draw(buttonsp);
		win->Draw(m_buttonName);
	}
	void is_active(bool s)
	{
		active = s;
	}
	void select(bool selected)
	{
		is_selected = selected;
	}
	void set_name(std::string sth)
	{
		name = sth;
		m_buttonName.SetText(name);
	}
	bool selected()
	{
		return is_selected;
	}
	void set_position(float x,float y)
	{
		buttonsp.SetPosition(x,y);
		m_buttonName.SetPosition(x,y);
	}
};
#endif