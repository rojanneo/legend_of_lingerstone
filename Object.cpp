#include "Object.h"
#include "ObjectNames.h"
#include "InteractiveObjectsStates.h"
Object::Object(lua_State *l)
{
	scripting = false;
	scriptedNPC = 0;
	ipressed = false;
	m_battleStart = false;
	m_potionCollected = false;
	m_npcInteracted = false;
//	m_commentSystem.initialize(l);

	m_objectImg1.SetSmooth(false);
	m_objectImg2.SetSmooth(false);
	m_objectImg3.SetSmooth(false);
	m_objectImg4.SetSmooth(false);
	m_objectImg5.SetSmooth(false);
	m_objectImg6.SetSmooth(false);
	m_objectImg7.SetSmooth(false);
	m_objectImg8.SetSmooth(false);
	m_objectImg9.SetSmooth(false);
	m_objectImg10.SetSmooth(false);

	m_object1Count = 0;
	m_object2Count = 0;
	m_object3Count = 0;
	m_object4Count = 0;
	m_object5Count = 0;
	m_object6Count = 0;
	m_object7Count = 0;
	m_object8Count = 0;
	m_object9Count = 0;
	m_object10Count = 0;

	
	for(int i = 0; i<19; i++)
	{
		for(int j = 0; j<25; j++)
		{
			m_file[i][j] = 0;
		}
	}
	m_swordDisable = false;
	m_potionDisable = false;
	m_invDisable = false;
	m_objectiveComplete1 = 0;
}

Object::~Object()
{}

bool Object::IsBattling()
{
	return m_battleStart;
}

bool Object::LoadObjects(VideoMode &vMode, RenderWindow *win, string filename, Player *player, lua_State *L)
{

	m_npcList.clear();
	for(int i = 0; i<24; i++)
	{
		for(int j = 0; j<25; j++)
		{
			m_file[i][j] = 0;
		}
	}


	m_filename.open(filename);
	if(!m_filename){cout<<"FAILED"; return false;}

	for(int i =0; i<475; i++)
	{
		m_objectSp1[i].SetPosition(-100,-100);
		m_objectSp2[i].SetPosition(-100,-100);
		m_objectSp3[i].SetPosition(-100,-100);
		m_objectSp4[i].SetPosition(-100,-100);
		m_objectSp5[i].SetPosition(-100,-100);
		m_objectSp6[i].SetPosition(-100,-100);
		m_objectSp7[i].SetPosition(-100,-100);
		m_objectSp8[i].SetPosition(-100,-100);
		m_objectSp9[i].SetPosition(-100,-100);
		m_objectSp10[i].SetPosition(-100,-100);
	}
	
	m_object1Count = 0;
	m_object2Count = 0;
	m_object3Count = 0;
	m_object4Count = 0;
	m_object5Count = 0;
	m_object6Count = 0;
	m_object7Count = 0;
	m_object8Count = 0;
	m_object9Count = 0;
	m_object10Count = 0;
	m_string[0] = '\0';
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		if(!m_objectImg1.LoadFromFile(m_string)){return false;}
		for(int i = 0; i<475;i++)
		{
			m_objectSp1[i].SetImage(m_objectImg1);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg2.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp2[i].SetImage(m_objectImg2);
		}
	}

	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg3.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp3[i].SetImage(m_objectImg3);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg4.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp4[i].SetImage(m_objectImg4);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg5.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp5[i].SetImage(m_objectImg5);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg6.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp6[i].SetImage(m_objectImg6);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg7.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp7[i].SetImage(m_objectImg7);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg8.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp8[i].SetImage(m_objectImg8);
		}
	}
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg9.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp9[i].SetImage(m_objectImg9);
		}
	}
	
	m_filename.getline(m_string, 100);
	if(m_string[0]!='N') 
	{
		m_objectImg10.LoadFromFile(m_string);
		for(int i = 0; i<475;i++)
		{
			m_objectSp10[i].SetImage(m_objectImg10);
		}
	}

	for(int i = 0; i<24; i++)
		{
			for(int j = 0; j<25; j++)
			{
				m_filename>>m_file[i][j];
				if(m_file[i][j]==2) m_object1Count++;
				if(m_file[i][j]==3) m_object2Count++;
				 if(m_file[i][j]==4) m_object3Count++;
				 if(m_file[i][j]==5) m_object4Count++;
				 if(m_file[i][j]==6) m_object5Count++;
				 if(m_file[i][j]==7) m_object6Count++;
				 if(m_file[i][j]==8) m_object7Count++;
				 if(m_file[i][j]==9) m_object8Count++;
				 if(m_file[i][j]==10) m_object9Count++;
				 if(m_file[i][j]==11) m_object10Count++;
			}
		}
	
	int xpos, ypos;
	int object1 = 0;
	int object2 = 0;
	int object3 = 0;
	int object4 = 0;
	int object5 = 0;
	int object6 = 0;
	int object7 = 0;
	int object8 = 0;
	int object9 = 0;
	int object10 = 0;

	for(int i = 0; i<24; i++)
	{
		for(int j= 0; j<25; j++)
		{
			
			if(m_file[i][j] == 2)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object1<m_object1Count)
				{
				m_objectSp1[object1].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp1[object1]);
				object1++;
				}	
			}
			 if(m_file[i][j] == 3)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object2<m_object2Count)
				{
				m_objectSp2[object2].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp2[object2]);
				object2++;
				}	
			}
			 if(m_file[i][j] == 4)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object3<m_object3Count)
				{
				m_objectSp3[object3].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp4[object4]);
				object3++;
				}	
			}
			 if(m_file[i][j] == 5)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object4<m_object4Count)
				{
				m_objectSp4[object4].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp4[object4]);
				object4++;
				}	
			}
			 if(m_file[i][j] == 6)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object5<m_object5Count)
				{
				m_objectSp5[object5].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp5[object5]);
				object5++;
				}	
			}
			 if(m_file[i][j] == 7)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object6<m_object6Count)
				{
				m_objectSp6[object6].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp6[object6]);
				object6++;
				}	
			}
			 if(m_file[i][j] == 8)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object7<m_object7Count)
				{
				m_objectSp7[object7].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp7[object7]);
				object7++;
				}	
			}
			 if(m_file[i][j] == 9)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object8<m_object8Count)
				{
				m_objectSp8[object8].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp8[object8]);
				object8++;
				}	
			}
			 if(m_file[i][j] == 10)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object9<m_object9Count)
				{
				m_objectSp9[object9].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp9[object9]);
				object9++;
				}	
			}
			 if(m_file[i][j] == 11)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				if(object10<m_object10Count)
				{
				m_objectSp10[object10].SetPosition((float)xpos, (float)ypos);
				m_objList.push_back(m_objectSp10[object10]);
				object10++;
				}	
			}
			if(m_file[i][j] == 33)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				player->SetPosition((float)xpos, (float)ypos);
			}
			if(m_file[i][j] == 34)
			{
				ypos = i * 32;
				xpos = j * 32;
			/*	sword = new Sword(i_object, xpos, ypos, "..\\data\\Images\\sword.png", Swords, 10, 5, 0);
				sword->InitializeMenu(2, "YOU FOUND A SWORD...", "Pick", "Leave");
			*/	swordCreated = true;
				m_drawSword = false;
				
			}

			if(m_file[i][j] == 35)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				potion = new Potion(i_object, xpos, ypos, "..\\data\\Images\\health.png", Potions, 0, 0, 25);
				potion->InitializeMenu(3, "YOU FOUND A POTION...", "Pick", "Leave", "Use");
				potionCreated = true;
			}
			/*
			
			CHANGE HERE			
			
			*/



			if(m_file[i][j] == 50)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_random, L,-1);
				npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				npc->InitializeMenu(npc->GetID(),"                   Menu");
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 51)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_enemy, L,-1);
				npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				npc->ResetHealth();
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 57)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_enemy1, L,-1);
				npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				npc->ResetHealth();
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 52)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_magician, L, -1);
				//npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				//npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				//npc->SetHealth(100);
			//	npc->ResetHealth();
				npc->RegisterToLua(e_npc_magician);
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 53)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_devils_son, L, player->GetCurrentMap());
				//npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				//npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				//npc->SetHealth(100);
			//	npc->ResetHealth();
				npc->RegisterToLua(e_npc_devils_son);
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 54)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_sajoroy, L, player->GetCurrentMap());
				//npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				//npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				//npc->SetHealth(100);
			//	npc->ResetHealth();
				npc->RegisterToLua(e_npc_sajoroy);
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 55)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_galcon, L, player->GetCurrentMap());
				//npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				//npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				//npc->SetHealth(100);
			//	npc->ResetHealth();
				npc->RegisterToLua(e_npc_galcon);
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 56)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				npc = new NPC(e_npc_alexa, L, player->GetCurrentMap());
				//npc->InitializeWealthStateManager();
				npc->SetPosition((float)xpos, (float)ypos);
				//npc->InitializeMenu(npc->GetID(),"What Do You Want To Do");
				//npc->SetHealth(100);
			//	npc->ResetHealth();
				npc->RegisterToLua(e_npc_alexa);
				m_npcList.push_back(npc);
			}
			if(m_file[i][j] == 101)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 101,(float) xpos, (float)ypos);
				m_map1ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 102)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 102,(float) xpos, (float)ypos);
				m_map2ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 103)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 103,(float) xpos, (float)ypos);
//				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map3ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 104)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 104,(float) xpos, (float)ypos);
				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map2ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 105)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 105,(float) xpos, (float)ypos);
				//exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map1ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 106)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 106,(float) xpos, (float)ypos);
				//exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map1ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 107)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 107,(float) xpos, (float)ypos);
				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map3ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 108)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 108,(float) xpos, (float)ypos);
				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map3ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 109)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 109,(float) xpos, (float)ypos);
				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map1ExitSensorList.push_back(exitSensor);
			}
			if(m_file[i][j] == 110)
			{
				ypos = (i-5) * 32;
				xpos = j * 32;
				exitSensor = new ExitSensor(L, i_object, 110,(float) xpos, (float)ypos);
//				exitSensor->ObjectiveComplete();
				//exitSensor->ObjectiveComplete();
				m_map2ExitSensorList.push_back(exitSensor);
			}

		}
	}
	m_filename.close();
	return true;
}

void Object::ClearSensors()
{
	m_map1ExitSensorList.clear();
	m_map2ExitSensorList.clear();
	m_map3ExitSensorList.clear();
	m_hasCollidedwithExitSensor = false;
	delete collidedSensor;
}

vector<Sprite> Object::GetObjList()
{
	return m_objList;
}

bool Object::RenderObjects(VideoMode &vMode, RenderWindow *win, Player *player, lua_State *l)
{
	bool pressed = false;
	for(int i = 0; i<m_object1Count; i++)
	{
		win->Draw(m_objectSp1[i]);
	}
	for(int i = 0; i<m_object2Count; i++)
	{
		win->Draw(m_objectSp2[i]);
	}
	for(int i = 0; i<m_object3Count; i++)
	{
		win->Draw(m_objectSp3[i]);
	}
	for(int i = 0; i<m_object4Count; i++)
	{
		win->Draw(m_objectSp4[i]);
	}
	for(int i = 0; i<m_object5Count; i++)
	{
		win->Draw(m_objectSp5[i]);
	}
	for(int i = 0; i<m_object6Count; i++)
	{
		win->Draw(m_objectSp6[i]);
	}
	for(int i = 0; i<m_object7Count; i++)
	{
		win->Draw(m_objectSp7[i]);
	}
	for(int i = 0; i<m_object8Count; i++)
	{
		win->Draw(m_objectSp8[i]);
	}
	for(int i = 0; i<m_object9Count; i++)
	{
		win->Draw(m_objectSp9[i]);
	}
	for(int i = 0; i<m_object10Count; i++)
	{
		win->Draw(m_objectSp10[i]);
	}

	

	for(int i = 0; i<(int)m_npcList.size(); i++)
	{
		if(m_npcInteracted == false)
		{
			m_npcList[i]->UpdateMenu(player->GetView());
		}
		m_npcList[i]->Draw(vMode, win);
		if(m_npcList[i]->HasInteracted())
		{
			
			m_swordDisable = true;
			m_npcInteracted = true;
			/*
				CHANGE HERE
			*/
			if(m_npcList[i]->GetID() != e_npc_enemy && m_npcList[i]->GetID() != e_npc_enemy1 && m_npcList[i]->GetID() != e_npc_enemy2 && m_npcList[i]->GetID() != e_npc_magician && m_npcList[i]->GetID() != e_npc_devils_son && m_npcList[i]->GetID() != e_npc_sajoroy && m_npcList[i]->GetID() != e_npc_galcon && m_npcList[i]->GetID() != e_npc_alexa)
			{
			m_npcList[i]->DrawMenu(win);
			m_npcList[i]->Run(m_npcList[i]->GetID(), win, player);
			}
			else
			{
				if(m_npcList[i]->GetID() == e_npc_enemy)
				{
					m_collidingIndex = i;
					m_collidedNPC = m_npcList[i];
					m_battleStart = true;
				}
				else if(m_npcList[i]->GetID() == e_npc_enemy1)
				{
					m_collidingIndex = i;
					m_collidedNPC = m_npcList[i];
					m_battleStart = true;
				}
				else if(m_npcList[i]->GetID() == e_npc_enemy2)
				{
					m_collidingIndex = i;
					m_collidedNPC = m_npcList[i];
					m_battleStart = true;
				}
				else if(m_npcList[i]->GetID() == e_npc_magician)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

					m_commentSystem.set_dialogue();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();
					//m_commentSystem.Run();
					if(scripting)
					{
						m_npcList[i]->RunScript(m_commentSystem, scripting);
						scripting = false;
					}
					
	
				}
				else if(m_npcList[i]->GetID() == e_npc_devils_son)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

//					m_commentSystem.set_dialogue1();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();

					if(scripting)
					{
						m_objectiveComplete1 = m_npcList[i]->RunScript(m_commentSystem, scripting);
						if(m_objectiveComplete1 == 1) m_map1ExitSensorList[0]->ObjectiveComplete();
						if(m_objectiveComplete1 == 5) 
						{
							NPC *npc;
							m_map2ExitSensorList[0]->ObjectiveComplete();
							for(int i = 0;i<(int)m_npcList.size(); i++)
							{
								if(m_npcList[i]->GetID() == e_npc_devils_son)
								{
									npc = new NPC(e_npc_enemy1, l,-1);
									npc->InitializeWealthStateManager();
									npc->SetPosition(m_npcList[i]->GetSprite().GetPosition().x,m_npcList[i]->GetSprite().GetPosition().y);
									npc->InitializeMenu(npc->GetID(), "What do you want to do");
									npc->ResetHealth();
									m_npcList[i] = npc;
								}
							}
						}
						if(m_objectiveComplete1 == 3) 
						{
							for(int i = 0; i<m_map3ExitSensorList.size(); i++)
							m_map3ExitSensorList[i]->ObjectiveComplete();
						}
						scripting = false;
					}
					
	
				}
				else if(m_npcList[i]->GetID() == e_npc_sajoroy)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

//					m_commentSystem.set_dialogue1();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();

					if(scripting)
					{
						m_objectiveComplete1 = m_npcList[i]->RunScript(m_commentSystem, scripting);
						cout<<"Objective"<<m_objectiveComplete1;
						if(m_objectiveComplete1 == 2) m_map2ExitSensorList[0]->ObjectiveComplete();
						if(m_objectiveComplete1 == 3) m_map3ExitSensorList[0]->ObjectiveComplete();
						scripting = false;
					}
					
	
				}

				else if(m_npcList[i]->GetID() == e_npc_galcon)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

//					m_commentSystem.set_dialogue1();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();

					if(scripting)
					{
						m_objectiveComplete1 = m_npcList[i]->RunScript(m_commentSystem, scripting);
						cout<<"Objective"<<m_objectiveComplete1;
						if(m_objectiveComplete1 == 1) m_map1ExitSensorList[0]->ObjectiveComplete();
//						if(m_objectiveComplete1 == 3) m_map3ExitSensorList[0]->ObjectiveComplete();
						scripting = false;
					}
					
	
				}
				else if(m_npcList[i]->GetID() == e_npc_alexa)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

//					m_commentSystem.set_dialogue1();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();

					if(scripting)
					{
						m_objectiveComplete1 = m_npcList[i]->RunScript(m_commentSystem, scripting);
						cout<<"Objective"<<m_objectiveComplete1;
						if(m_objectiveComplete1 == 2)
						{
							for(int i = 0;i<(int)m_npcList.size(); i++)
							{
								if(m_npcList[i]->GetID() == e_npc_alexa)
								{
									npc = new NPC(e_npc_alexa_final, l,-1);
//									npc->InitializeWealthStateManager();
									npc->SetPosition(m_npcList[i]->GetSprite().GetPosition().x,m_npcList[i]->GetSprite().GetPosition().y);
//									npc->InitializeMenu(npc->GetID(), "What do you want to do");
									npc->RegisterToLua(e_npc_alexa_final);
									m_npcList[i] = npc;
								}
							}
						}
//						if(m_objectiveComplete1 == 3) m_map3ExitSensorList[0]->ObjectiveComplete();
						scripting = false;
					}
					
	
				}

				else if(m_npcList[i]->GetID() == e_npc_alexa_final)
				{
					scriptedNPC = i;
					scripting = true;
	//				m_swordDisable = true;
					//m_npcList[i]->DrawBG(win);
					m_commentSystem.initialize(l, (player->GetView().GetCenter().x-player->GetView().GetHalfSize().x),(player->GetView().GetCenter().y-player->GetView().GetHalfSize().y));

//					m_commentSystem.set_dialogue1();
					m_commentSystem.set_win(vMode, win);
					m_commentSystem.set_drawing();

					if(scripting)
					{
						m_objectiveComplete1 = m_npcList[i]->RunScript(m_commentSystem, scripting);
						cout<<"Objective"<<m_objectiveComplete1;
						if(m_objectiveComplete1 == 2)
						{
							return false;
						}
//						if(m_objectiveComplete1 == 3) m_map3ExitSensorList[0]->ObjectiveComplete();
						scripting = false;
					}
					
	
				}


				/*
				
					CHANGE HERE
				
				*/
			}
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				m_swordDisable = false;
				m_npcList[i]->Reset(player);
				m_battleStart = false;
			}
			if(win->GetInput().IsKeyDown(Key::Return))
			{
				
				if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==1)
				{
					
						m_npcList[i]->Threaten(player, win);
						m_swordDisable = false;
						m_npcInteracted = false;
						m_npcList[i]->Reset(player);
						
				}
				else if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==2)
				{
					m_npcList[i]->Beat(player);
					if(m_npcList[i]->GetHealth()<=0)
					{
						if(i-1 != -1)
						m_npcList[i]->Kill(win,player);
						m_npcList[i]->Reset(player);
						m_swordDisable = false;
						m_npcInteracted = false;
						m_npcList.erase(m_npcList.begin() + i);
					}
					m_npcList[i]->Reset(player);
					m_swordDisable = false;
					m_npcInteracted = false;
				}
				else if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==3)
				{

					if(i-1 != -1)
					m_npcList[i-1]->Kill(win,player);
					m_npcList[i]->Reset(player);
					m_swordDisable = false;
					m_npcInteracted = false;
					m_npcList.erase(m_npcList.begin() + i);
				}
				else if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==4)
				{
					m_npcList[i]->Steal(player,win);
					m_npcList[i]->Reset(player);
					m_swordDisable = false;
					m_npcInteracted = false;
				}
				else if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==5)
				{
					m_npcList[i]->Talk(win);
					m_npcList[i]->Reset(player);
					m_swordDisable = false;
					m_npcInteracted = false;
				}
				else if(m_npcList[i]->GetNavLocation(m_npcList[i]->GetID())==6)
				{
					m_npcList[i]->Help(win, player);
					m_npcList[i]->Reset(player);
					m_swordDisable = false;
					m_npcInteracted = false;
				}
				else
				{}
			//run the dialog code here
		}
		m_npcList[i]->DrawString(win);

		
		}
		else
		{
		}
		
	}

	for(int i = 0; i<(int)m_map1ExitSensorList.size(); i++)
	{
		if(m_map1ExitSensorList[i]->IsRunning() && m_map1ExitSensorList[i]->IsObjectiveComplete() == false)
		{
			m_map1ExitSensorList[i]->UpdatePosition(player->GetView());
			m_map1ExitSensorList[i]->DrawMessage(win);
			m_swordDisable = true;
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				m_map1ExitSensorList[i]->NotRunning();
				m_map1ExitSensorList[i]->Reset(player);
				m_swordDisable = false;
				
			}
		}
	}

	for(int i = 0; i<(int)m_map2ExitSensorList.size(); i++)
	{
		if(m_map2ExitSensorList[i]->IsRunning() && m_map2ExitSensorList[i]->IsObjectiveComplete() == false)
		{
			m_map2ExitSensorList[i]->UpdatePosition(player->GetView());
			m_map2ExitSensorList[i]->DrawMessage(win);
			m_swordDisable = true;
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				m_map2ExitSensorList[i]->NotRunning();
				m_map2ExitSensorList[i]->Reset(player);
				m_swordDisable = false;
				
			}
		}
	}

	for(int i = 0; i<(int)m_map3ExitSensorList.size(); i++)
	{
		if(m_map3ExitSensorList[i]->IsRunning() && m_map3ExitSensorList[i]->IsObjectiveComplete() == false)
		{
			m_map3ExitSensorList[i]->UpdatePosition(player->GetView());
			m_map3ExitSensorList[i]->DrawMessage(win);
			m_swordDisable = true;
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				m_map3ExitSensorList[i]->NotRunning();
				m_map3ExitSensorList[i]->Reset(player);
				m_swordDisable = false;
				
			}
		}
	}
	
	//Add other exit Sensors here

	if(m_drawSword)
	{
	if(swordCreated)
	{
		if(!sword->IsCollected())
		{
		sword->Draw(win);
		if(sword->HasInteracted())
		{
			m_swordDisable = true;
			sword->DrawMenu(win);
			sword->Run(win, player);
			if(win->GetInput().IsKeyDown(Key::Return))
			{
				if(sword->GetNavLocation()==1)
				{
					sword->Collected();
					m_map1ExitSensorList[0]->ObjectiveComplete();
//					m_map1ExitSensorList[1]->ObjectiveComplete();
					player->AddToInventory(sword);
					m_inventory.AddToInventory(sword);
					m_swordDisable = false;
				}
				else if(sword->GetNavLocation()==2)
				{
					sword->Reset(player);
					m_swordDisable = false;
				} 
			}
		}
		else
		{
			m_swordDisable = false;
		}
		}
	}
	else
	{
		m_swordDisable = false;
	}
	}



	if(potionCreated)
	{
		if(m_potionCollected == false)
		{
		potion->UpdateMenu(3, player->GetView());
		}
		if( !potion->IsCollected())
		{
		potion->Draw(win);
		if(potion->HasInteracted())
		{
			m_potionCollected = true;
			m_potionDisable = true;
			potion->DrawMenu(win);
			potion->Run(win, player);
			if(win->GetInput().IsKeyDown(Key::Return))
			{
				if(potion->GetNavLocation()==1)
				{

					potion->Collected();
					player->PotionCollected();
					m_inventory.AddToInventory(potion);
					m_potionDisable = false;
					m_potionCollected = false;
				}
				else if(potion->GetNavLocation()==2)
				{
					potion->Reset(player);
					m_potionDisable = false;
					m_potionCollected = false;
				}
				else if(potion->GetNavLocation()==3)
				{
					potion->Collected();
					player->AddHealth(potion->GetValue());
					m_potionDisable = false;
					m_potionCollected = false;
				}
			}
		}
		else
		{
			m_potionDisable = false;
			m_potionCollected = false;
		}
		}
	}
	else
	{
		m_potionDisable = false;
		m_potionCollected = false;
	}
	
	if(win->GetInput().IsKeyDown(Key::I) && pressed == false)
	{
		//change this for map 2 objective
		if(player->GetCurrentMap() == 1)	m_map2ExitSensorList[0]->ObjectiveComplete();
		ipressed = true;
		m_invDisable = true;
	
	}
	if(win->GetInput().IsKeyDown(Key::Escape) && ipressed == true)
	{
			ipressed = false;
			m_invDisable = false;
	}
	
	if(ipressed == true)
	{
		m_inventory.RunInventory(win);
	}

	for(int i = 0; i<(int)m_npcList.size(); i++)
	{
		if(m_npcList[i]->DialogueBreak())
		{
			m_swordDisable = true;
			if(m_npcList[i]->DrawDialogue(win, player->GetView())== false)
			{
				m_swordDisable  = false;
			}
			
		}
		
	}
	return true;
}

void Object::StopBattle()
{
	m_battleStart = false;
}

NPC* Object::GetCollidedNPC()
{
	return m_collidedNPC;
}


bool Object::IsDisabled()
{
	if(m_swordDisable || m_potionDisable||m_invDisable)
	return true;
	else return false;
}
void Object::Enable()
{
}

int Object::HasCollidedWithObject(Player player, RenderWindow *win)
{
	
	
	for(int i = 0; i<m_object1Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp1[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object2Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp2[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object3Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp3[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object4Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp4[i]))
		{
			return noncollectible;
		}
	}
	
	for(int i = 0; i<m_object5Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp5[i]))
		{
			return collectible;
		}
	}
	for(int i = 0; i<m_object6Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp6[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object7Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp7[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object8Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp8[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object9Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp9[i]))
		{
			return noncollectible;
		}
	}
	for(int i = 0; i<m_object10Count; i++)
	{
		if(m_col.PixelPerfectTest(player.GetSprite(), m_objectSp10[i]))
		{
			return noncollectible;
		}
	}

	for(int i = 0; i<(int)m_npcList.size(); i++)
	{
		if(m_col.BoundingBoxTest(m_npcList[i]->GetSprite(), player.GetSprite()))
		{
				m_npcList[i]->GetInteractiveStateManager()->ChangeState(Interacting::Instance());
				m_npcList[i]->Interacted();
				return collectible;
		}
		if(!m_col.BoundingBoxTest(m_npcList[i]->GetSprite(), player.GetSprite()))
		{
				m_npcList[i]->GetInteractiveStateManager()->ChangeState(NotInteracting::Instance());
				m_npcList[i]->NotInteracted();
		}
	}

	for(int i = 0; i<(int)m_map1ExitSensorList.size(); i++)
	{
		if(m_col.BoundingBoxTest(m_map1ExitSensorList[i]->GetSprite(), player.GetSprite())) 
		{
			m_hasCollidedwithExitSensor = true;
			m_map1ExitSensorList[i]->StartRunning();
			collidedSensor = m_map1ExitSensorList[i];
			return exitsensor;
		}
	}

	for(int i = 0; i<(int)m_map2ExitSensorList.size(); i++)
	{
		if(m_col.BoundingBoxTest(m_map2ExitSensorList[i]->GetSprite(), player.GetSprite())) 
		{
			m_hasCollidedwithExitSensor = true;
			m_map2ExitSensorList[i]->StartRunning();
			collidedSensor = m_map2ExitSensorList[i];
			return exitsensor;
		}
	}

	for(int i = 0; i<(int)m_map3ExitSensorList.size(); i++)
	{
		if(m_col.BoundingBoxTest(m_map3ExitSensorList[i]->GetSprite(), player.GetSprite())) 
		{
			m_hasCollidedwithExitSensor = true;
			m_map3ExitSensorList[i]->StartRunning();
			collidedSensor = m_map3ExitSensorList[i];
			return exitsensor;
		}
	}

	

	
	if(m_drawSword)
	{
	if(swordCreated)
	{
	if(m_col.BoundingBoxTest(sword->GetSprite(), player.GetSprite()))
	{
		sword->GetStateManager()->ChangeState(Interacted::Instance());
		player.GetInteractiveStateManager()->ChangeState(Interacting::Instance());
	}
	}
	if(swordCreated)
	{
	if(!m_col.BoundingBoxTest(sword->GetSprite(), player.GetSprite()))
	{
		sword->GetStateManager()->ChangeState(NotInteracted::Instance());
		player.GetInteractiveStateManager()->ChangeState(NotInteracting::Instance());

	}
	}
	}
	if(potionCreated)
	{
	if(m_col.BoundingBoxTest(potion->GetSprite(), player.GetSprite()))
	{
		potion->GetStateManager()->ChangeState(Interacted::Instance());
		player.GetInteractiveStateManager()->ChangeState(Interacting::Instance());

	}
	}
	if(potionCreated)
	{
	if(!m_col.BoundingBoxTest(potion->GetSprite(), player.GetSprite()))
	{
		potion->GetStateManager()->ChangeState(NotInteracted::Instance());
		player.GetInteractiveStateManager()->ChangeState(NotInteracting::Instance());

	}
	}
	
	return -1;
}

void Object::NotDisabled()
{
	m_swordDisable = false;
}

void Object::Update(Player player)
{
	if(m_drawSword)
	{
	if(swordCreated) sword->UpdateAI();
	}
	if(potionCreated) potion->UpdateAI();
	player.UpdateAI();
	for(int i = 0; i<(int)m_npcList.size(); i++)
	{
		m_npcList[i]->UpdateAI();
		m_npcList[i]->UpdateNPCAI();
	}
}

bool Object::HasCollidedWithExitSensor(Player player)
{
	return m_hasCollidedwithExitSensor;
}

ExitSensor* Object::GetCollidedExitSensor(Player player)
{
	return collidedSensor;
}

int Object::GetCollidingIndex()
{
	return m_collidingIndex;
}

void Object::RemoveNPC(int index, RenderWindow *win, Player *player)
{
	m_npcList[index - 1]->Kill(win, player);
	m_npcList[index]->Reset(player);
	sword = new Sword(i_object, (int)m_npcList[index]->GetSprite().GetPosition().x, (int)m_npcList[index]->GetSprite().GetPosition().y, "..\\data\\Images\\sword.png", Swords, 10, 5, 0);
	sword->InitializeMenu(2, "YOU FOUND A SWORD...", "Pick", "Leave");
	swordCreated = true;
	m_drawSword = true;
	m_npcList.erase(m_npcList.begin() + index);
	
}

Sword* Object::GetSword()
{
	if(swordCreated)
	return sword;
	else return 0;
}

void Object::DrawCommentSystem()
{
	//m_commentSystem.start_drawing();
}