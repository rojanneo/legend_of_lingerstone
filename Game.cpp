#include "Game.h"
#include "Map.h"
#include "Object.h"
#include "Player.h"
#include "NPC.h"
#include "HUD.h"
#include "battle_system.h"
#include "Enemy.h"
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include "LScripter.h"
Game::Game()
{}

Game::~Game()
{}
int Game::Run(RenderWindow &win, VideoMode &vMode)
{
	lua_State *luaState = luaL_newstate();
	luaL_openlibs(luaState);
	luabind::open(luaState);
	Map map;
	Player player(luaState, e_player,0);// 0 should be loaded from file
	player.RegisterClassToLua();
	battle_system battle;

	Object *object;
	object = new Object(luaState);
	Event Event;
	NPC npc(e_npc_random, luaState, -1);
	npc.SetPosition(200,200);
	
	bool collisionUp = false;
	bool collisionDown = false;
	bool collisionLeft = false;
	bool collisionRight = false;
	bool change = true;
	bool running = false;
	bool gameOver = false;
	bool load = false;
	bool load2 = false;


	Image gameOverImg;
	gameOverImg.LoadFromFile("../data/Images//presents.png");
	Sprite gameOverSp(gameOverImg);
	
	vector<string> mapList;
	vector<string> objectList;
	mapList.push_back("..\\data\\Levels\\Map1.txt");
	mapList.push_back("..\\data\\Levels\\Map2.txt");
	mapList.push_back("..\\data\\Levels\\Map3.txt");
	mapList.push_back("..\\data\\Levels\\Map2.txt");
	mapList.push_back("..\\data\\Levels\\Map1.txt");
	mapList.push_back("..\\data\\Levels\\Map2.txt");
	mapList.push_back("..\\data\\Levels\\Map3.txt");
	mapList.push_back("..\\data\\Levels\\Map3.txt");
	mapList.push_back("..\\data\\Levels\\Map1.txt");
	mapList.push_back("..\\data\\Levels\\Map2.txt");






	objectList.push_back("..\\data\\Levels\\Object1.txt");
	objectList.push_back("..\\data\\Levels\\Object2.txt");
	objectList.push_back("..\\data\\Levels\\Object3.txt");
	objectList.push_back("..\\data\\Levels\\Object4.txt");
	objectList.push_back("..\\data\\Levels\\Object5.txt");
	objectList.push_back("..\\data\\Levels\\Object6.txt");
	objectList.push_back("..\\data\\Levels\\Object7.txt");
	objectList.push_back("..\\data\\Levels\\Object8.txt");
	objectList.push_back("..\\data\\Levels\\Object9.txt");
	objectList.push_back("..\\data\\Levels\\Object10.txt");


	string level = mapList[0];//Load from file
	string levelObject = objectList[0];
	
	HUD hud;
	Enemy enemy;
	while(win.IsOpened())
	{
		while(win.GetEvent(Event))
		{
			if(Event.Type == Event::Closed)
			{
				win.Close();
			}
		}
		if(win.GetInput().IsKeyDown(Key::Space))
		{
			level = mapList[1];
			change = true;
			load2 = true;
			if(!object->LoadObjects(vMode, &win, levelObject, &player, luaState))
			{
				win.Close();
			}
		}

		if(!win.GetInput().IsKeyDown(Key::Space) && load2 == true)
		{
			load2 = false;
			change = false;
		}
		if(win.GetInput().IsKeyDown(Key::T))
		{
			player.RunGoldScript();
		}
		if(win.GetInput().IsKeyDown(Key::LShift))
		{
			level = mapList[0];
			change = true;
			load = true;
			player.ChangeMap(0);
			/*if(!map.LoadMap(vMode, &win, "..\\data\\Levels\\Map1.txt"))
			{
				win.Close();
			}*/
			if(!object->LoadObjects(vMode, &win, "..\\data\\Levels\\Object1.txt", &player, luaState))
			{
				win.Close();
			}
		}

		if(!win.GetInput().IsKeyDown(Key::LShift) && load == true)
		{
			load = false;
			change = false;
		}
		
		if(!object->IsDisabled())
		{
		if(win.GetInput().IsKeyDown(Key::Up)&& !win.GetInput().IsKeyDown(Key::Left) && !win.GetInput().IsKeyDown(Key::Right))
		{
				if(object->HasCollidedWithObject(player, &win) == exitsensor)
				{
					cout<<"collided"<<object->GetCollidedExitSensor(player)->GetDestinationID();
					if(object->GetCollidedExitSensor(player)->GetDestinationID() == 1)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 2)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 3)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 4)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 5)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 7)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 8)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 9)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 10)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					
				}

				else
					{
					if(object->HasCollidedWithObject(player, &win) == -1 )
					{	
						player.MoveUp(&win);
						if(player.GetView().GetCenter().y - player.GetView().GetHalfSize().y > -160)
						{
							hud.MoveUp(&win);
						}
				
					}
					else
					{
					player.SetPosition(player.GetSprite().GetPosition().x , player.GetSprite().GetPosition().y + 10);
					}
			
				}
				}

		if(win.GetInput().IsKeyDown(Key::Down)&& !win.GetInput().IsKeyDown(Key::Left) && !win.GetInput().IsKeyDown(Key::Right))
		{
			if(player.GetSprite().GetPosition().y + player.GetSprite().GetSize().y<600)
			{
				if(object->HasCollidedWithObject(player, &win) == exitsensor)
				{
					cout<<"collided"<<object->GetCollidedExitSensor(player)->GetDestinationID();
					if(object->GetCollidedExitSensor(player)->GetDestinationID() == 1)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 2)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 3)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 4)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 5)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 7)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 8)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 9)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}
					else if(object->GetCollidedExitSensor(player)->GetDestinationID() == 110)
					{
						cout<<"dest:";
						if(object->GetCollidedExitSensor(player)->IsObjectiveComplete())
						{
							cout<<"Exit";
							level = mapList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							levelObject = objectList[object->GetCollidedExitSensor(player)->GetDestinationID()];
							change = true;
							player.ChangeMap(object->GetCollidedExitSensor(player)->GetDestinationID());
							object->ClearSensors();
						}
						else
						{
						}
					}

					
				}
				else
				{
				if(object->HasCollidedWithObject(player, &win) == -1)
				{	
				player.MoveDown(&win);
				if(player.GetView().GetCenter().y <= 300)
				{
					hud.MoveDown(&win);
				}
				}
				else
				{
				player.SetPosition(player.GetSprite().GetPosition().x , player.GetSprite().GetPosition().y - 10);
				}
				}
			}
		
		}
		if(win.GetInput().IsKeyDown(Key::Left) && !win.GetInput().IsKeyDown(Key::Up) && !win.GetInput().IsKeyDown(Key::Down)&& !win.GetInput().IsKeyDown(Key::Right))
		{	
			if(object->HasCollidedWithObject(player, &win) == -1)
			{
				player.MoveLeft(&win);
				
			}
			else
			{
				player.SetPosition(player.GetSprite().GetPosition().x + 10, player.GetSprite().GetPosition().y);
			}
		}
		if(win.GetInput().IsKeyDown(Key::Right)&& !win.GetInput().IsKeyDown(Key::Up) && !win.GetInput().IsKeyDown(Key::Down)&& !win.GetInput().IsKeyDown(Key::Left))
		{
			if(object->HasCollidedWithObject(player, &win) == -1)
			{
				player.MoveRight(&win);
				
			}
			else
			{
				player.SetPosition(player.GetSprite().GetPosition().x - 10, player.GetSprite().GetPosition().y);
			}
		}
		}
		if(win.GetInput().IsKeyDown(Key::A))
		{
		}
		if(object->HasCollidedWithObject(player, &win) == noncollectible)
		{
			if(player.m_up) player.SetPosition(player.GetSprite().GetPosition().x , player.GetSprite().GetPosition().y + 10);
			if(player.m_down) player.SetPosition(player.GetSprite().GetPosition().x , player.GetSprite().GetPosition().y - 10);
			if(player.m_right) player.SetPosition(player.GetSprite().GetPosition().x - 10, player.GetSprite().GetPosition().y);
			if(player.m_left) player.SetPosition(player.GetSprite().GetPosition().x + 10, player.GetSprite().GetPosition().y);
		}
		
		

		hud.Update(&player);
		object->Update(player);
		if(!object->IsBattling())
		{
		win.Clear();
		if(change)
		{
			if(!map.LoadMap(vMode, &win, level))
			{
				win.Close();
			}
			if(!object->LoadObjects(vMode, &win, levelObject, &player, luaState))
			{
				win.Close();
			}
			
			change = false;
		}
		map.RenderMap(vMode, &win);
		player.Draw(vMode, &win);
		if(object->RenderObjects(vMode, &win, &player, luaState) == false) return 0;
		hud.Draw(&win);
		}
		else
		{
			win.Clear();
			NPC* npc;
			npc = object->GetCollidedNPC();
			battle.Initialize((player.GetView().GetCenter().x-player.GetView().GetHalfSize().x),(player.GetView().GetCenter().y-player.GetView().GetHalfSize().y));
			if(battle.Run(vMode, win, &enemy, player) == "Exits")
			{
				object->StopBattle();
			}
			else if(battle.Run(vMode, win, &enemy, player) == "Player Win")
			{
				object->StopBattle();
				object->RemoveNPC(object->GetCollidingIndex(), &win, &player);
			}
			else if(battle.Run(vMode, win, &enemy, player) == "Enemy Win")
			{
				object->StopBattle();
				object->NotDisabled();
				player.Default();
				enemy.Default();

				if(!map.LoadMap(vMode, &win, "..\\data\\Levels\\Map1.txt"))
				{
					win.Close();
				}
				if(!object->LoadObjects(vMode, &win, "..\\data\\Levels\\Object1.txt", &player, luaState))
				{
					win.Close();
				}
			}
			player.SetView(400,300);
		}
		object->DrawCommentSystem();
		win.SetView(player.GetView());
		win.Display();
	}
	lua_close(luaState);
	return -1;
}


