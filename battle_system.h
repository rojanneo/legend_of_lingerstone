/*
	
	$Battle_System.h

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


#ifndef BATTLE_SYSTEM
#define BATTLE_SYSTEM
#include<iostream>
#include<string>
#include<sfml/Graphics.hpp>
#include"Menu2.h"
#include"Enemy.h"
#include"Player.h"
#include"tree_try.h"
#include "Attack.h"
#include "FuzzyMachine.h"
#include "FuzzyOperator.h"
#include<vector>
class battle_system
{
private:
	bool Players_turn;
	BMenu menu;
	sf::Image Background;
	sf::Sprite backsp;
	sf::Image h_back;
	sf::Sprite enemy_backsp;
	sf::Sprite player_backsp;
	sf::Image health;
	sf::Sprite health_enemy[100];
	sf::Sprite health_player[100];
	sf::Sprite enemy_blank;
	sf::Sprite player_blank;
	sf::Image blank;
	Attack *m_powerAttack;
	Attack *m_powerAttack1;
	Attack *m_powerAttack2;
	Attack *m_powerAttack3;
	Attack *m_magicAttack;
	Attack *m_paralyzeAttack;
	Attack *m_swordAttack;
	Attack *m_fistAttack;
	Attack *m_shieldAttack;
	Attack *m_shield1Attack;
	Attack *m_shield2Attack;
	Attack *m_cSwordAttack;
	Attack *m_cSword1Attack;
	vector<node> tree1;
	vector<node> tree2;
	sf::Randomizer ran;
	float startx;
	float starty;
	FuzzyMachine fm;
	bool fuzzy;
	
	
public:
	battle_system()
	{
		fuzzy = false;
		m_powerAttack = new Attack("Light Sword", 10);
		m_powerAttack1 = new Attack("Power Attack 1", 12);
		m_powerAttack2 = new Attack("Power Attack 2", 13);
		m_powerAttack3 = new Attack("Power Attack 3", 15);
		m_magicAttack = new Attack("Magic", 20);
		m_paralyzeAttack = new Attack("Paralyze", 0);
		m_swordAttack = new Attack("Sword", 10);
		m_fistAttack = new Attack("Fist", 5);
		m_cSwordAttack = new Attack("CSword", 10);
		m_cSword1Attack = new Attack("CSword1", 10);
		m_shieldAttack = new Attack("Shield",0);
		m_shield1Attack = new Attack("Shield1", 5);
		m_shield2Attack = new Attack("Shield2", 10);
		h_back.LoadFromFile("../data/images/Health_Bar.jpg");
		health.LoadFromFile("../data/images/Health_Block.jpg");
		blank.LoadFromFile("../data/images/Health_Bar_Main.png");
		enemy_blank.SetImage(blank);
		player_blank.SetImage(blank);
		for(int i = 0; i<100; i++)
		{
		health_enemy[i].SetImage(health);
		health_player[i].SetImage(health);
		}
		enemy_backsp.SetImage(h_back);
		player_backsp.SetImage(h_back);
		


		menu.setbuttonname(0,"Game Menu");
		menu.setbuttonname(1,"Attack");
		menu.setbuttonname(2,"Defend");
		menu.setbuttonname(3,"Counter Attack");
		menu.setbuttonname(4,"Potion");
		menu.setbuttonname(5,"Magic");
		menu.sub_menu_name(0,0,"Exit");
		menu.sub_menu_name(1,0,"Sword");
		menu.sub_menu_name(1,1,"Fist");
		menu.sub_menu_name(2,0,"Shield");
		menu.sub_menu_name(2,1,"Shield1");
		menu.sub_menu_name(2,2,"Shield2");
		menu.sub_menu_name(3,0,"CSword");
		menu.sub_menu_name(3,1,"CSword1");
		menu.sub_menu_name(4,0,"Health");
		//menu.sub_menu_name(4,1,"Strength");
		menu.sub_menu_name(5,0,"Paralyze");
		menu.sub_menu_name(5,1,"Spell");
		Background.LoadFromFile("../data/Images/background.png");
		backsp.SetImage(Background);
		node *anc;
		for(int i = 0;i<7;i++)
		{
			anc = new node;
			anc->set_id();
			if(i>=3)
			{         
				anc->set_leaf(true);                       
			}
			else
			{
			   anc->set_leaf(false);
			}
			create_tree1(anc); 
           
		}
			tree1[3].set_string("Light Sword");
			tree1[4].set_string("Fist");
			tree1[5].set_string("Power Attack 1");
			tree1[6].set_string("Fist");

					anc->reset_id();

		for(int i = 0;i<7;i++)
		{
			anc = new node;
			anc->set_id();
			if(i>=3)
			{         
				anc->set_leaf(true);                       
			}
			else
			{
			   anc->set_leaf(false);
			}
			create_tree2(anc); 
           
		}
			
		
			tree2[3].set_string("Power Attack 2");
			tree2[4].set_string("Power Attack 3");
			tree2[5].set_string("Magic");
			tree2[6].set_string("Magic");
			/*tree1[13].set_string("Magic");
			tree1[14].set_string("Magic");
			tree1[15].set_string("Magic");
			tree1[16].set_string("Magic");
			tree1[17].set_string("Power Attack");
			tree1[18].set_string("Power Attack 1");
			tree1[19].set_string("Power Attack 2");
			tree1[20].set_string("Power Attack 3");*/



	}

	double Fuzzy(double playerHealth, double enemyHealth)
	{
		FuzzyVariable& PlayerHealth = fm.CreateFLV("PlayerHealth");
		FzSet Player_Low_Health = PlayerHealth.AddLeftShoulderSet("Player_Low_Health", 0, 25,50);
		FzSet Player_Ok_Health = PlayerHealth.AddTriangularSet("Player_Ok_Health", 25, 50, 75);
		FzSet Player_Good_Health = PlayerHealth.AddRightShoulderSet("Player_Good_Health", 50, 75, 100);


		FuzzyVariable& EnemyHealth = fm.CreateFLV("EnemyHealth");
		FzSet Enemy_Low_Health = EnemyHealth.AddLeftShoulderSet("Enemy_Low_Health", 0, 25,50);
		FzSet Enemy_Ok_Health = EnemyHealth.AddTriangularSet("Enemy_Ok_Health", 25, 50, 75);
		FzSet Enemy_Good_Health = EnemyHealth.AddRightShoulderSet("Enemy_Good_Health", 50, 75, 100);

		FuzzyVariable& AttackType = fm.CreateFLV("AttackType");
		FzSet Attack_Strong = AttackType.AddLeftShoulderSet("Attack_Strong", 0, 25, 150);
		FzSet Attack_Weak = AttackType.AddRightShoulderSet("Attack_Weak", 150, 300, 500);

		fm.AddRule(FuzzyAND(Player_Good_Health, Enemy_Good_Health), Attack_Strong);//12.5
		fm.AddRule(FuzzyAND(Player_Good_Health, Enemy_Ok_Health), Attack_Weak);//400
		fm.AddRule(FuzzyAND(Player_Good_Health, Enemy_Low_Health), Attack_Weak);//400

		fm.AddRule(FuzzyAND(Player_Ok_Health, Enemy_Good_Health), Attack_Strong);	
		fm.AddRule(FuzzyAND(Player_Ok_Health, Enemy_Ok_Health), Attack_Strong);
		fm.AddRule(FuzzyAND(Player_Ok_Health, Enemy_Low_Health), Attack_Weak);//322 245
	
		fm.AddRule(Player_Low_Health, Attack_Strong);

		fm.Fuzzify("PlayerHealth", playerHealth);
		fm.Fuzzify("EnemyHealth", enemyHealth);

		return fm.DeFuzzify("AttackType", FuzzyMachine::max_av);

	}
	void Initialize(float startx, float starty)
	{
		this->startx = startx;
		this->starty = starty;
		backsp.SetPosition(this->startx, this->starty);
		enemy_blank.SetPosition(this->startx + 0.0f,this->starty + 0.0f);
		player_blank.SetPosition(this->startx + 425.0f,this->starty + 0.0f);
		enemy_backsp.SetPosition(this->startx + 75.0f,this->starty + 10.0f);
		player_backsp.SetPosition(this->startx + 425.0f,this->starty + 10.0f);
		menu.Initialize(this->startx, this->starty);
	}
	string Run(sf::VideoMode &vid,sf::RenderWindow &win,Enemy *enemy,Player &player)
	{
		std::cout<<"y1:"<<starty<<std::endl;
		std::cout<<"y:"<<health_enemy[0].GetPosition().y<<std::endl;
/*
			backsp.SetPosition(startx, starty);
			enemy_blank.SetPosition(startx + 0.0f,starty + 0.0f);
			player_blank.SetPosition(startx + 425.0f,starty + 0.0f);
			enemy_backsp.SetPosition(startx + 75.0f,starty + 10.0f);
			player_backsp.SetPosition(startx + 425.0f,starty + 10.0f);
*/
		//Player player(players);
		int heal = 0;
		float fuzzyResult = -700;
		Players_turn =true;
		std::string sth;
		std::string  enemySth;
		sf::Event e;
		bool enemyAttack = false;
		bool playerAttack = false;
		bool chance[100];
		for(int k=0;k<100;k++)
		{
			chance[k]=true;
		}

		while(win.IsOpened())
		{
			while (win.GetEvent(e))
			{
            if (e.Type == sf::Event::Closed)
                win.Close();
			}
			if(player.GetHealth()<=0)
			{
				return "Enemy Win";
			}
			
			if(Players_turn==false)
			{
				
			//	enemySth = traversal2(calculate(enemy->get_level(),enemy->GetHealth(),enemy->GetMagicLevel()));
				if(fuzzy == false)
				{
				fuzzyResult = Fuzzy((double)player.GetHealth(), (double)enemy->GetHealth());
				if(fuzzyResult<=100) enemySth = traversal2(calculate(enemy->get_level(),enemy->GetHealth(),enemy->GetMagicLevel()));
				else enemySth = traversal(calculate(enemy->get_level(),enemy->GetHealth(),enemy->GetMagicLevel()));
				fuzzy = true;
				}				
				
				if(enemySth == m_powerAttack->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_powerAttack->GetDamage());

					}

				}
				else if(enemySth == m_fistAttack->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_fistAttack->GetDamage());

					}
				}
				else if(enemySth == m_powerAttack1->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_powerAttack1->GetDamage());

					}
				}
				else if(enemySth == m_powerAttack2->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_powerAttack2->GetDamage());

					}
				}
				else if(enemySth == m_powerAttack3->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_powerAttack3->GetDamage());

					}
				}
				else if(enemySth == m_magicAttack->GetName())
				{
					enemyAttack = true;
					for(int k=0;k<100;k++)
					{
						chance[k]=true;
					}
					
					for(int k=0;k<20;k++)
					{
						chance[ran.Random(0,99)] = false;
					}
					
					if(chance[ran.Random(0,99)]==true)
					{
						player.DecreaseHealth(m_magicAttack->GetDamage());

					}
				}
				if(playerAttack == false && enemyAttack)
				{
					enemy->decrease_health(m_powerAttack->GetDamage());
					//player.DecreaseHealth(m_powerAttack.GetDamage());
				}
				
				Players_turn = true;
				

			}

			
			
			if((sth = menu.Run(vid,win,Players_turn,backsp,*enemy,player,&h_back,&health,&blank)) == "Exits")
			{
				win.Close();
			}
			else if(sth == "Break")
			{
				break;
			}
			else if(sth == "Shield") 
			{
					player.DecreaseHealth(m_shieldAttack->GetDamage()/2);
					enemy->decrease_health(m_shieldAttack->GetDamage() * 2);
					Players_turn = false;
//					player.SetHealth(5);
					fuzzy = false;
			}
			else if(sth == "Change Form")
			{
				enemy->decrease_health(m_magicAttack->GetDamage());
				player.DecreaseHealth(m_magicAttack->GetDamage()/4);
				Players_turn = false;
				fuzzy = false;
			}
			else if(sth == "Paralyze")
			{
				//enemy->decrease_health(m_magicAttack->GetDamage());
				//player.DecreaseHealth(m_magicAttack->GetDamage()/4);
				Players_turn = true;
				fuzzy = false;
			}
			else if(sth == "Sword")
			{
					playerAttack = true;
					enemy->decrease_health(m_swordAttack->GetDamage());
					Players_turn = false;
					fuzzy = false;
			}
			else if(sth == "Fist")
			{
					playerAttack = true;
					enemy->decrease_health(m_fistAttack->GetDamage());
					Players_turn = false;
					fuzzy = false;
			}
			else if(sth == "Shield1")
			{
					player.DecreaseHealth(m_shield1Attack->GetDamage()/2);
					enemy->decrease_health(m_shield1Attack->GetDamage() * 2);
					Players_turn = false;
					fuzzy = false;
			}
			else if(sth == "Shield2")
			{
					player.DecreaseHealth(m_shield2Attack->GetDamage()/2);
					enemy->decrease_health(m_shield2Attack->GetDamage() * 2);
					Players_turn = false;
					fuzzy = false;
			}
			else if(sth == "CSword")
			{
					playerAttack = true;
					enemy->decrease_health(m_cSwordAttack->GetDamage());
					Players_turn = false;
					fuzzy = false;
			}
			else if(sth == "CSword1")
			{
					playerAttack = true;
					enemy->decrease_health(m_cSword1Attack->GetDamage());
					//if(enemy->GetHealth()<=0) break;
					Players_turn = false;
					fuzzy = false;
			}

			else if(sth == "Health")
			{
					if(player.HasPotion())
					{
						player.AddHealth(25);
						player.PotionUsed();
					}
					Players_turn = false;
					fuzzy = false;
			}

			else
			{
				playerAttack = true;
				enemy->decrease_health(m_magicAttack->GetDamage());
				Players_turn = false;
				fuzzy = false;
			}

			
			win.Draw(backsp);
//			win.Draw(health_player);
			player.DrawBattleImage(&win,startx,starty);
			enemy->Draw(vid,&win,startx,starty);
			win.Draw(enemy_blank);
			win.Draw(player_blank);
			win.Draw(enemy_backsp);
			win.Draw(player_backsp);
			int x = enemy->GetHealth();
			int y = player.GetHealth();
			if(x<=0) 
			{
				//break;
				heal = 1;
				return "Player Win";
			}
			if(y==0)
			{
				return "Enemy Win";
			}
			for(int i = 0; i<player.GetHealth(); i++)
			{
				win.Draw(health_player[i]);
			}

			for(int i = 0; i<enemy->GetHealth(); i++)
			{
				win.Draw(health_enemy[i]);
			}

			win.Display();
		}
		return "Exits";
	}
void create_tree1(node *nd2)
	{
     
		 node nd1;
		 int temp=0;
		 nd1.set_id(nd2->Get_ID());
		 nd1.set_string(nd2->get_action());
		 nd1.set_leaf(nd2->is_leaf());
		 tree1.push_back(nd1);
		 temp = nd1.Get_ID();
     
		 for(int i = 0;i<temp;i++)
		 {
            
				 if(tree1[i].get_child_no()<2)
				 {
       
						  tree1[i].add_child(&tree1[temp-1]);
						  break;
				 }
		 }

}

void create_tree2(node *nd2)
	{
     
		 node nd3;
		 int temp=0;
		 nd3.set_id(nd2->Get_ID());
		 nd3.set_string(nd2->get_action());
		 nd3.set_leaf(nd2->is_leaf());
		 std::cout<<"ND3: "<<nd3.Get_ID();
		 tree2.push_back(nd3);
		 temp = nd3.Get_ID();
     
		 for(int i = 0;i<temp;i++)
		 {
            
				 if(tree2[i].get_child_no()<2)
				 {
       
						  tree2[i].add_child(&tree2[temp-1]);
						  break;
				 }
		 }

}


	float calculate(int level,int health,int magic)
	{
		float total=0;
//		if(health <= 80) return -1;
		if(health>=60)
		{
			health = 2*level;
		}
		else
		{
			health = 1*level;
		}
		if(magic>=60)
		{
			magic = 2*level;
		}
		else
		{
			magic = 1*magic;
		}
		total = (float)(magic+health)/(float)(level+level);
		return (total);
	}

	std::string traversal(float value)
	{

		   
		  // if(value == -1) return "N";
			   int i = 0;
		   int *temp;
		   float corr_val = 2;
				while(i<(signed int)tree1.size())
			   {
							   temp = tree1[i].get_child_ids();
                       
							   if(value <= (corr_val/2) && value > 0)
							   {
											 i = temp[0]-1;
											 corr_val = corr_val/2;
                         
							   }      
							   else if(value > (corr_val/2) && value <= ((corr_val*2)/2))
							   {
											 i = temp[1]-1;
											 corr_val = (corr_val*2)/2;
                         
							   }
							   
							   if(tree1[i].is_leaf())
							   {
													return tree1[i].get_action();
							   }
		   }
		   return 0;
	}    

	std::string traversal2(float value)
	{
			int i = 0;
			int *temp;
			float corr_val = 2;
			std::cout<<(int)tree2.size();
				while(i<(int)tree2.size())
				{
								std::cout<<(int)tree2.size();

							   temp = tree2[i].get_child_ids();
							   std::cout<<"Temp0: "<<temp[0];
                       
							   std::cout<<"Temp1: "<<temp[1];
							   if(value <= (corr_val/2) && value > 0)
							   {
											 i = temp[0]-1;
											 corr_val = corr_val/2;
                         
							   }      
							   else if(value > (corr_val/2) && value <= ((corr_val*2)/2))
							   {
											 i = temp[1]-1;
											 corr_val = (corr_val*2)/2;
                         
							   }
							   std::cout<<"I: "<<i;
							   if(tree2[i].is_leaf())
							   {
													return tree2[i].get_action();
							   }
			   }
	}
              
		bool is_players_turn()
		{
			return Players_turn;
		}
	


};
#endif