#include "Splash.h"
#include <iostream>
using namespace sf;
Splash::Splash()
{
	m_scripter.LoadScript("../data/Scripts/splash_script.txt");
}
Splash::~Splash()
{}
int Splash::Run(sf::RenderWindow &win, sf::VideoMode &vMode)
{
	Event events;
	while(win.IsOpened())
	{
		while(win.GetEvent(events))
		{
			if(events.Type == Event::Closed)
				win.Close();
			if(win.GetInput().IsKeyDown(Key::Space)) return 2;
		}
		if(m_scripter.RunScript(&m_splashBgImg, &m_splashBgSp) == 2) return 2;
		win.Clear();
		win.Draw(m_splashBgSp);
		win.Display();
	}
	return -1;
}
