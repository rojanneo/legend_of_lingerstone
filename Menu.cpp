#include "Menu.h"
#include <SFML\Audio.hpp>
using namespace sf;
using namespace std;
Menu::Menu()
{}
Menu::~Menu()
{}
int Menu::Run(sf::RenderWindow &win, sf::VideoMode &vMode)
{	
	m_menuBgImg.LoadFromFile("../data/Images/title.png");
	m_menuBgSp.SetImage(m_menuBgImg);
	m_menuText1.SetText("START");
	m_menuText1.SetColor(Color::Black);
	m_menuText2.SetText("EXIT");
	m_menuText2.SetColor(Color::Black);

	m_menuText1.SetPosition(1000, (float)m_menuBgImg.GetHeight()/2);
	m_menuText2.SetPosition(1000, (float)m_menuBgImg.GetHeight()/2 + 50);
	//m_menuText1.SetPosition((float)m_menuBgImg.GetWidth()/2 - m_chooserImg.GetWidth(), (float)m_menuBgImg.GetHeight()/2);
	//m_menuText2.SetPosition((float)m_menuBgImg.GetWidth()/2- m_chooserImg.GetWidth(), (float)m_menuBgImg.GetHeight()/2 + 50);
	m_chooserImg.LoadFromFile("../data/Images/neutral.png");
	m_chooser.SetImage(m_chooserImg);
	m_chooser.SetPosition(1000, m_menuText1.GetPosition().y);
	Event events;
	Music mus;
	mus.OpenFromFile("../data//Sound//AKISLOW.ogg");
	mus.SetLoop(true);
	mus.Play();
	bool start = false;
	while(win.IsOpened())
	{
		while(win.GetEvent(events))
		{
			if(events.Type == Event::Closed)
				win.Close();
			
			
			
			if(win.GetInput().IsKeyDown(Key::Return))
			{
				//mus.Stop();
				if(m_chooser.GetPosition().y == m_menuText1.GetPosition().y) return 1;
				else win.Close();
			}
			
			
			if(win.GetInput().IsKeyDown(Key::Down))
			{
				if(m_chooser.GetPosition().y == m_menuText1.GetPosition().y)
				{
					m_chooser.SetPosition(m_menuText2.GetPosition().x - m_chooserImg.GetWidth(), m_menuText2.GetPosition().y);
				}
			}
			if(win.GetInput().IsKeyDown(Key::Up))
			{
				if(m_chooser.GetPosition().y == m_menuText2.GetPosition().y)
				{
					m_chooser.SetPosition(m_menuText1.GetPosition().x - m_chooserImg.GetWidth(), m_menuText1.GetPosition().y);
				}
			}
		}
		if(m_menuText1.GetPosition().x >= m_menuBgImg.GetWidth()/2 - m_chooserImg.GetWidth())
			{
				m_chooser.Move(-500*win.GetFrameTime(), 0);
				m_menuText1.Move(-500*win.GetFrameTime(), 0);				
				m_menuText2.Move(-500*win.GetFrameTime(), 0);
			}
		if(m_chooser.GetPosition().x>= m_menuText1.GetPosition().x - m_chooserImg.GetWidth())
		{
			m_chooser.Move(-1000*win.GetFrameTime(), 0);

		}
		win.Clear();
		win.Draw(m_menuBgSp);
		win.Draw(m_menuText1);
		win.Draw(m_menuText2);
		win.Draw(m_chooser);

		win.Display();
	}
	return -1;
}
