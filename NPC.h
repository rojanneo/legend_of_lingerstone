/*
	
	$NPC.h

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


#ifndef NPC_H_
#define NPC_H_
#include "Character.h"
#include "NPCStates.h"
#include "NPCInteraction.h"
#include "Dialogue.h"
#include "LScripter.h"
#include "Comment_System.h"
#include "ExitSensor.h"

class NPC:public Character, public NPCInteraction
{
private:
	int m_npcID;
	bool m_hasInteracted;
	int m_npcAttribute;
	Dialogue *m_dialogueSystem;
	bool m_threaten;
	bool m_dialoguebreak;
	Randomizer ra;
	bool m_stolen;
	int m_ranImgCount;
	int m_attack;
	int m_level;
	int m_magicLevel;
	StateManager<NPC> *m_strengthStateManager;
	StateManager<NPC> *m_wealthStateManager;
	StateManager<NPC> *m_stateManager;
	string m_script;
	string m_scriptDevilSon[10];
	string m_scriptSajoroy[10];
	string m_scriptGalcon[10];
	string m_scriptAlexa[10];
	lua_State *m_L;
	LScripter m_scripter;
	bool m_drawpause;
	sf::String m_string;
	bool stringEmpty;
	int stringtry;
	int m_sajoroyCurrentScript;
	int m_magicianCurrentScript;
	//Comment_System commentSystem;
private:
	static const int m_devilSonCurrentScript = 0;

public:
	NPC(int id, lua_State *l, int script):Character(id)
	{
		m_sajoroyCurrentScript = 0;
		m_magicianCurrentScript = 0;

		stringtry = 0;
		stringEmpty = true;
		m_drawpause = false;
		m_L = l;
		m_stolen = false;
		m_npcID = id;
		m_threaten = false;
		m_dialogueSystem = new Dialogue();
		m_hasInteracted = false;
		m_strengthStateManager = new StateManager<NPC>(this);
		m_strengthStateManager->SetCurrentState(Strong::Instance());
		m_stateManager = new StateManager<NPC>(this);
		m_stateManager->SetCurrentState(Alive::Instance());
		m_ranImgCount = 2;
		m_script = "NONE";
		int m_image = ra.Random(1, m_ranImgCount);
		if(id == e_npc_random)
		{
			if(m_image == 1)
			{
				m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
				m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
				m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
				m_playerImgDown.LoadFromFile("..\\data\\Images\\playerdown.png");
			}
			else if(m_image == 2)
			{
				m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
				m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
				m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
				m_playerImgDown.LoadFromFile("..\\data\\Images\\magiciandown.png");
			}
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_attack = 100;
		if(ra.Random(1,3) == 1)
		{
			m_npcAttribute = a_aggressive;
		}
		else if(ra.Random(1,3) == 2)
		{
			m_npcAttribute = a_neutral;
		}
		else
		{
			m_npcAttribute = a_scared;
		}
		SetGold(ra.Random(1, 1000));
		
		SetHealth(100);
		m_dialoguebreak = false;
		}
		else if(id == e_npc_magician)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\magiciandown.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_script = "..\\data\\Scripts\\magician_entry.lua";
		}
		else if(id == e_npc_devils_son)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\devilson_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_scriptDevilSon[0] = "..\\data\\Scripts\\devil_entry.lua";
		m_scriptDevilSon[1] = "..\\data\\Scripts\\s_d_1.lua";
		m_scriptDevilSon[2] = "..\\data\\Scripts\\s_d_2.lua";
		m_scriptDevilSon[3] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[4] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[5] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[6] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[7] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[8] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[9] = "..\\data\\Scripts\\devil_confront.lua";
		m_scriptDevilSon[10] = "..\\data\\Scripts\\devil_confront.lua";

		m_script = m_scriptDevilSon[script];
		}
		else if(id == e_npc_enemy)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\enemy_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		}
		else if(id == e_npc_enemy1)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\devilson_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		}
		else if(id == e_npc_enemy2)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\alexa_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		}
		else if(id == e_npc_sajoroy)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\sajoroy_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		
		m_scriptSajoroy[0] = "None";
		m_scriptSajoroy[1] = "..\\data\\Scripts\\sajoroy_entry.lua";
		m_scriptSajoroy[2] = "..\\data\\Scripts\\s_d_1.lua";
		m_script = m_scriptSajoroy[script];
		}

		else if(id == e_npc_galcon)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\galcon_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		
		m_script = "..\\data\\Scripts\\galcon_entry.lua";
		}

		else if(id == e_npc_alexa)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\alexa_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		
		m_script = "..\\data\\Scripts\\alexa_devil.lua";
		}
		else if(id == e_npc_alexa_final)
		{
		m_playerImgLeft.LoadFromFile("..\\data\\Images\\playerleft.png");
		m_playerImgRight.LoadFromFile("..\\data\\Images\\playerright.png");
		m_playerImgUp.LoadFromFile("..\\data\\Images\\playerup.png");
		m_playerImgDown.LoadFromFile("..\\data\\Images\\alexa_down.png");
		m_playerSp.SetImage(m_playerImgDown);
		m_playerSp.SetFrameSize(32,32);
		m_playerSp.SetLoopSpeed(5);
		m_playerSp.Play();
		m_playerMoveSpeed = 100;
		m_dialoguebreak = false;
		m_level = 10;
		m_magicLevel = 5;
		
		m_script = "..\\data\\Scripts\\alexa_final.lua";
		}
		/*
		
			CHANGE HERE
		
		*/
	}

	void InitializeString(string s, float x, float y)
	{
		cout<<s;
		m_string.SetText(s);
		m_string.SetPosition(x, y);
		stringEmpty = false;
		stringtry++;
	}

	int GetStringTry()
	{
		return stringtry;
	}

	void ResetHealth()
	{
		this->SetHealth(100);
	}
	int GetMagicLevel()
	{
		return m_magicLevel;
	}

	int get_level()
	{
		return m_level;
	}


	void InitializeWealthStateManager()
	{
		m_wealthStateManager = new StateManager<NPC>(this);
		if(GetGold()>=500) m_wealthStateManager->SetCurrentState(Wealthy::Instance());
		else m_wealthStateManager->SetCurrentState(Poor::Instance());
		
	}


	StateManager<NPC>* GetStrengthStateManager()
	{
		return m_strengthStateManager;
	}

	StateManager<NPC>* GetWealthStateManager()
	{
		return m_wealthStateManager;
	}

	StateManager<NPC>* GetStateManager()
	{
		return m_stateManager;
	}

	void UpdateNPCAI()
	{
		m_stateManager->Update();
		/*
			CHANGE HERE
		*/
		if(m_npcID != e_npc_magician && m_npcID != e_npc_devils_son && m_npcID != e_npc_sajoroy && m_npcID != e_npc_galcon && m_npcID != e_npc_alexa && m_npcID != e_npc_alexa_final)
		{
		m_strengthStateManager->Update();
		m_wealthStateManager->Update();
		}
	}


	int GetID()
	{
		return m_npcID;
	}

	void SetGold(int gold)
	{
		m_goldCarried = gold;
	}


	int GetGold()
	{
		return m_goldCarried;
	}

	void Steal(Player *player,RenderWindow *win)
	{
		if(!m_stolen)
		{
		int value = rand_lim(GetGold());
		int remainingGold = GetGold() - value;
		if(remainingGold < 0 ) remainingGold = 0;
		SetGold(remainingGold);
		player->SetGold(player->GetGold() + value);
		player->MakeAffinityEvil();
		m_dialogueSystem->GetDialogue(this->GetID(), "Steal", win, this->GetAttribute());
		m_dialoguebreak = true;
		m_stolen = true;
		}
		else
		{
		m_dialogueSystem->GetDialogue(this->GetID(), "Steal", win, this->GetAttribute());
		m_dialoguebreak = true;
		}
			
		}
	int GetAttribute()
	{
		return m_npcAttribute;
	}
	void Help(RenderWindow *win, Player *player)
	{
		m_dialogueSystem->GetDialogue(this->GetID(), "Help", win, this->GetAttribute());
		m_dialoguebreak = true;
		player->MakeAffinityGood();
	}
	void Threaten(Player *player, RenderWindow *win)
	{
		m_threaten = true;
		player->MakeAffinityEvil();
		m_dialogueSystem->GetDialogue(this->GetID(),"Threaten", win, this->GetAttribute());
		m_dialoguebreak = true;
	}
	bool DialogueBreak()
	{
		return m_dialoguebreak;
	}
	bool DrawDialogue(RenderWindow *win, View view)
	{
		m_dialogueSystem->UpdatePosition(view);
		m_dialogueSystem->DrawDialogue(win, m_dialoguebreak);
		if(win->GetInput().IsKeyDown(Key::Escape))
			{
				Resets();
				return false;
			}
		return true;
	}
	void DialogueFalse()
	{
		m_dialoguebreak = false;
	}
	void Beat(Player *player)
	{
		DecreaseHealth(40);
		DecreaseAttack(50);
		player->MakeAffinityEvil();
		m_dialogueSystem->GetDialogue(this->GetID(), "Beat", NULL, this->GetAttribute());
		m_dialoguebreak = true;
	}

	int GetAttack()
	{
		return m_attack;
	}

	void DecreaseAttack(int x)
	{
		m_attack -= x;
	}
	void Talk(RenderWindow *win)
	{
		if(m_stolen == true)
		{
			m_dialogueSystem->GetDialogue(this->GetID(), "Steal", win, this->GetAttribute());
			m_dialoguebreak = true;			
		}
		else
		{
			m_dialogueSystem->GetDialogue(this->GetID(), "Talk", win, this->GetAttribute());
			m_dialoguebreak = true;

		}
	}
	void Kill(RenderWindow *win, Player *player)
	{
		player->MakeAffinityEvil();
		this->DecreaseHealth(100);
		m_dialogueSystem->GetDialogue(this->GetID(), "Kill", win, this->GetAttribute());
		m_dialoguebreak = true;
	}
	void Resets()
	{
		m_dialoguebreak = false;
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

	void DrawBG(RenderWindow *win)
	{
		cout<<"DRAWSTART";
		Image im;
		im.LoadFromFile("..\\data\\Images\\background.png");
		Sprite sp;
		sp.SetImage(im);
		win->Draw(sp);
	}

	

	void RegisterToLua(int id)
	{
		if(id == e_npc_magician)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("Magician")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			];

			
		}
		else if(id == e_npc_devils_son)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("DevilSon")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			.def("Random", &NPC::rand_lim)
			];
		}
		else if(id == e_npc_sajoroy)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("Sajoroy")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			.def("Random", &NPC::rand_lim)
			];
		}
		else if(id == e_npc_galcon)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("Sajoroy")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			.def("Random", &NPC::rand_lim)
			];
		}
		else if(id == e_npc_alexa)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("Sajoroy")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			.def("Random", &NPC::rand_lim)
			];
		}
		else if(id == e_npc_alexa_final)
		{
			luabind::module(m_L)
			[
				luabind::class_<NPC>("Sajoroy")
			//.def(luabind::constructor<string, float, float>())
			.def("String", &NPC::InitializeString)
			.def("Try", &NPC::GetStringTry)
			.def("Random", &NPC::rand_lim)
			];
		}
		/*
				CHANGE HERE
		*/
	}

	int RunScript(Comment_System s, bool scripting)
	{
		int o;
		if(m_npcID == e_npc_devils_son)
		{
			m_scripter.RunScript(m_L, m_script, scripting);
//			cout<<e.GetDestinationID();
			o = luabind::call_function<int>(m_L, "Run", s);
			/*o = luabind::call_function<int>(m_L, "test");*/
			//cout<<"Script: "<<m_devilSonCurrentScript;
			//m_devilSonCurrentScript++;
			return o;
		}
		else if(m_npcID == e_npc_magician)
		{
		m_scripter.RunScript(m_L, m_script, scripting);
		luabind::call_function<void>(m_L,"Run", s);
		}
		else if(m_npcID == e_npc_sajoroy)
		{
		m_scripter.RunScript(m_L, m_script, scripting);
		o = luabind::call_function<int>(m_L,"Run", s);
		return o;
		}
		else if(m_npcID == e_npc_galcon)
		{
		m_scripter.RunScript(m_L, m_script, scripting);
		o = luabind::call_function<int>(m_L,"Run", s);
		return o;
		}
		else if(m_npcID == e_npc_alexa)
		{
		m_scripter.RunScript(m_L, m_script, scripting);
		o = luabind::call_function<int>(m_L,"Run", s);
		return o;
		}
		else if(m_npcID == e_npc_alexa_final)
		{
		m_scripter.RunScript(m_L, m_script, scripting);
		o = luabind::call_function<int>(m_L,"Run", s);
		return o;
		}
		/*
			CHANGE HERE
		*/
	}
	void DrawString(RenderWindow *win)
	{
		if(stringEmpty == false)
		{
			win->Draw(m_string);
		}
	}
};



#endif