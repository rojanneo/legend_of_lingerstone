#include "Map.h"
Map::Map()
{
	m_mapCount = 0;
	m_groundCount = 0;
	m_ground.SetSmooth(false);
	m_road.SetSmooth(false);
	m_grass.SetSmooth(false);
	for(int i = 0; i<24; i++)
	{
		for(int j = 0; j<25; j++)
		{
			m_file[i][j] = 0;
		}
	}
}

Map::~Map()
{}

bool Map::LoadMap(VideoMode &vMode, RenderWindow *win, string filename)
{
	m_filename.open(filename);
	if(!m_filename){cout<<"Unable to Load File "<<filename;return false;}
	

	m_filename.getline(m_string,100);
	if(!m_ground.LoadFromFile(m_string)){return false;}

	m_filename.getline(m_string,100);
	if(!m_road.LoadFromFile(m_string)){return false;}
	
	m_filename.getline(m_string,100);
	if(!m_grass.LoadFromFile(m_string)){return false;}
	
	for(int i = 0; i<24; i++)
		{
			for(int j = 0; j<25; j++)
			{
				m_filename>>m_file[i][j];
			}
		}

	m_groundCount = 0;
	m_roadCount = 0;
	m_grassCount = 0;
	for(int i = 0; i<24; i++)
		{
			for(int j = 0; j<25; j++)
			{
				m_filename>>m_file[i][j];
				if(m_file[i][j]==1) m_roadCount++;
				else if(m_file[i][j] == 99) m_grassCount++;
				else m_groundCount++;
			}
		}
	
	for(int i = 0; i<m_groundCount; i++)
	{
		m_groundSp[i].SetImage(m_ground);
	}
	for(int i = 0; i<m_roadCount; i++)
	{
		m_roadSp[i].SetImage(m_road);
	}
	for(int i = 0; i<m_grassCount; i++)
	{
		m_grassSp[i].SetImage(m_grass);
	}

	int xpos, ypos;
	int ground = 0;
	int road = 0;
	int grass = 0;

	for(int i = 0; i<24; i++)
	{
		for(int j= 0; j<25; j++)
		{
			
			if(m_file[i][j] == 1)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(road<m_roadCount)
				{
				m_roadSp[road].SetPosition((float)xpos, (float)ypos);
				road++;
				}	
			}
			else if(m_file[i][j] == 99)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(grass<m_grassCount)
				{
				m_grassSp[grass].SetPosition((float)xpos, (float)ypos);
				grass++;
				}	
			}

			
			
			else
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(ground<m_groundCount)
				{
				m_groundSp[ground].SetPosition((float)xpos, (float)ypos);
				ground++;
				}
			}

		}
	}
	m_filename.close();
	return true;
}

bool Map::RenderMap(VideoMode &vMode, RenderWindow *win)
{
	for(int i = 0; i<m_groundCount; i++)
	{
		win->Draw(m_groundSp[i]);
	}
	
	for(int i = 0; i<m_roadCount; i++)
	{
		win->Draw(m_roadSp[i]);
	}
	for(int i = 0; i<m_grassCount; i++)
	{
		win->Draw(m_grassSp[i]);
	}
	return true;
}
