/*
	
	$Dialogue.h

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

#ifndef DIALOGUE_H_
#define DIALOGUE_H_
#include<iostream>
#include<vector>
#include<fstream>
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;

class Dialogue
{
private:
	vector<string>m_randomDialogueFiles;
	string m_filename;
	ifstream file;
	char m_dialogue[2000];
	String dialogue;
	int m_dialogueNumber;
	Image m_bgImg;
	Sprite m_bgSprite;
	string test;
	int m_ThreatenDialogueCount;
	int m_StealDialogueCount;
	int m_TalkDialogueCount;
	int m_KillDialogueCount;
	int m_HelpDialogueCount;
	Randomizer ra;
public:
	Dialogue()
	{
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Threaten_agg.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Threaten_neu.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Threaten_sca.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Steal_agg.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Steal_neu.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Steal_sca.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Talk_agg.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Talk_neu.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Talk_sca.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Kill.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Beat.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Help_agg.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Help_neu.txt");
		m_randomDialogueFiles.push_back("..\\data\\Dialogues\\Random\\Help_sca.txt");
		m_dialogueNumber = 0;
		m_bgImg.LoadFromFile("..\\data\\Images\\dialogueMenu.png");
		m_bgSprite.SetImage(m_bgImg);
		m_bgSprite.SetCenter((float)m_bgImg.GetWidth()/2, (float)m_bgImg.GetHeight()/2);
		m_bgSprite.SetPosition(400,500);
		dialogue.SetPosition(m_bgSprite.GetPosition().x - 300, m_bgSprite.GetPosition().y);

		m_TalkDialogueCount = 3;
		m_ThreatenDialogueCount = 6;
		m_StealDialogueCount = 6;
		m_KillDialogueCount = 3;
		m_HelpDialogueCount = 3;
	}
	string GetDialogue(int id,string action, RenderWindow *win, int attribute)
	{
		if(id == e_npc_random)
		{
			if(action == "Threaten")
			{
				
				m_dialogueNumber = ra.Random(1,m_ThreatenDialogueCount);
				if(attribute == a_aggressive) m_filename = m_randomDialogueFiles[0];
				else if(attribute == a_neutral) m_filename = m_randomDialogueFiles[1];
				else m_filename = m_randomDialogueFiles[2];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber; i++)
				{
				file.getline(m_dialogue, 2000);

				}
				file.close();
				dialogue.SetText(m_dialogue);
			}
			else if(action == "Steal")
			{
				
				m_dialogueNumber = ra.Random(1,m_StealDialogueCount);
				if(attribute == a_aggressive) m_filename = m_randomDialogueFiles[3];
				else if(attribute == a_neutral) m_filename = m_randomDialogueFiles[4];
				else m_filename = m_randomDialogueFiles[5];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber;i++)	file.getline(m_dialogue, 2000);
				file.close();
				dialogue.SetText(m_dialogue);
				
			}
			else if(action == "Talk")
			{
				m_dialogueNumber = ra.Random(1,m_TalkDialogueCount);
				if(attribute == a_aggressive) m_filename = m_randomDialogueFiles[6];
				else if(attribute == a_neutral) m_filename = m_randomDialogueFiles[7];
				else m_filename = m_randomDialogueFiles[8];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber;i++)	file.getline(m_dialogue, 2000);
				file.close();
				dialogue.SetText(m_dialogue);
				
			}
			else if(action == "Kill")
			{
				m_dialogueNumber = ra.Random(1,m_KillDialogueCount);
				m_filename = m_randomDialogueFiles[9];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber;i++)	file.getline(m_dialogue, 2000);
				file.close();
				dialogue.SetText(m_dialogue);
				
			}
			else if(action == "Beat")
			{
				m_dialogueNumber = 1;
				m_filename = m_randomDialogueFiles[10];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber;i++)	file.getline(m_dialogue, 2000);
				file.close();
				dialogue.SetText(m_dialogue);
				
			}
			else if(action == "Help")
			{
				m_dialogueNumber = ra.Random(1,m_HelpDialogueCount);
				if(attribute == a_aggressive) m_filename = m_randomDialogueFiles[11];
				else if(attribute == a_neutral) m_filename = m_randomDialogueFiles[12];
				else m_filename = m_randomDialogueFiles[13];
				file.open(m_filename);
				if(!file)
				{
					cout<<"UNABLE to OPEN FILE";
				}
				for(int i = 0; i<m_dialogueNumber;i++)	file.getline(m_dialogue, 2000);
				file.close();
				dialogue.SetText(m_dialogue);
				
			}
		}
		return m_dialogue;
	}

	void UpdatePosition(View view)
	{
		m_bgSprite.SetPosition(view.GetCenter().x,view.GetCenter().y + 200);
		dialogue.SetPosition(m_bgSprite.GetPosition().x - 300, m_bgSprite.GetPosition().y);
	}
	void DrawDialogue(RenderWindow *win, bool pass)
	{
		if(pass)
		{
			win->Draw(m_bgSprite);
		win->Draw(dialogue);
		}
	}
	int Run(RenderWindow *win)
	{
		if(win->GetInput().IsKeyDown(Key::Return))
		{
			return 0;
		}
		return -1;
	}

	int rand_lim(int limit) 
		{
		    int divisor = RAND_MAX/(limit+1);
			int retval = limit + 1;;

		    while(retval>limit)
			{
				retval = rand()/ divisor;
			}
			  return retval;
		}

};
#endif