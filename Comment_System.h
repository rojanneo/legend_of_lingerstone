#include<iostream>
#include<vector>
#include<SFML\Graphics.hpp>
#include <sstream>
#include"Sub_menu.h"
#include"including.h"
#include "LScripter.h"
#define MAX_NO_OF_DIALOGUES 2
class Comment_System
{
private:
	Sub_menu sub_menu;
	sf::Image Dialogue3Img;
	sf::Sprite Dialogue3Sp;
	sf::Image comment_opt;
	sf::Sprite comment_NPC_sp;
	sf::Sprite comment_PC_sp;
	sf::Image option;
	sf::Sprite optionsp;
	sf::Image background;
	sf::Sprite backgroundsp;
	std::string dialogue_angry_array[MAX_NO_OF_DIALOGUES];
	std::string dialogue_neu_array[MAX_NO_OF_DIALOGUES];
	std::string dialogue_good_array[MAX_NO_OF_DIALOGUES];
	std::string PC_comment;
	sf::String PC_cmt;
	sf::String jpt;
	std::string PC_comment1;
	sf::String PC_cmt1;
	sf::RenderWindow *win;
	sf::VideoMode vid;

	sf::Image m_narrationImage[11];
	sf::Sprite m_narration[11];
	including str;
	bool is_narrating;
	bool is_drawing;
	bool has_to_comment;
		bool up;
		bool down;
		bool left;
		bool right;
		bool sub_menu_active;
	
		int butt_no;
		int i;
		int j;
		int dialogue_no;
		int flag;
		float m_startx;
		float m_starty;
	lua_State *l;
public:

	void initialize(lua_State *ls, float startx, float starty)
	{
		m_narrationImage[0].LoadFromFile("../data/images/narration0.png");
		m_narrationImage[1].LoadFromFile("../data/images/narration1.png");
		m_narrationImage[2].LoadFromFile("../data/images/narration2.png");
		m_narrationImage[3].LoadFromFile("../data/images/narration3.png");
		m_narrationImage[4].LoadFromFile("../data/images/narration4.png");
		m_narrationImage[5].LoadFromFile("../data/images/narration5.png");
		m_narrationImage[6].LoadFromFile("../data/images/narration6.png");
		m_narrationImage[7].LoadFromFile("../data/images/narration7.png");
		m_narrationImage[8].LoadFromFile("../data/images/narration8.png");
		m_narrationImage[9].LoadFromFile("../data/images/narration9.png");
		m_narrationImage[10].LoadFromFile("../data/images/narration10.png");

		m_narration[0].SetImage(m_narrationImage[0]);
		m_narration[1].SetImage(m_narrationImage[1]);
		m_narration[2].SetImage(m_narrationImage[2]);
		m_narration[3].SetImage(m_narrationImage[3]);
		m_narration[4].SetImage(m_narrationImage[4]);
		m_narration[5].SetImage(m_narrationImage[5]);
		m_narration[6].SetImage(m_narrationImage[6]);
		m_narration[7].SetImage(m_narrationImage[7]);
		m_narration[8].SetImage(m_narrationImage[8]);
		m_narration[9].SetImage(m_narrationImage[9]);
		m_narration[10].SetImage(m_narrationImage[10]);
		is_narrating = false;
		Dialogue3Img.LoadFromFile("../data/images/Background.png");
		Dialogue3Sp.SetImage(Dialogue3Img);
		m_startx = startx;
		m_starty = starty;
		l = ls;
		comment_opt.LoadFromFile("../data/images/comment.png");
		background.LoadFromFile("../data/images/Background.png");
		comment_NPC_sp.SetImage(comment_opt);
		comment_PC_sp.SetImage(comment_opt);
		backgroundsp.SetImage(background);
		backgroundsp.SetPosition(startx,starty);
		sub_menu.set_name("Reply modes");
		sub_menu.set_butt_name("Good",0);
		sub_menu.set_butt_name("Neutral",1);
		sub_menu.set_butt_name("Angry",2);
		comment_NPC_sp.SetPosition(startx, starty);
		comment_PC_sp.SetPosition(startx,starty+450.0f);
		optionsp.SetPosition(startx+150.0f,starty+240.0f);
		PC_cmt.SetPosition(startx+50.0f,starty+500.0f);
		PC_cmt1.SetPosition(startx+50.0f, starty + 20.0f);
		PC_cmt1.SetText("");
		jpt.SetPosition(startx+200.0f,starty+270.0f);
//		jpt.SetText("TEST");
		is_drawing=false;
		has_to_comment=true;
		str.RegisterToLua(l);
		luabind::module(l)
			[
				luabind::class_<Comment_System>("Comment")
			//.def(luabind::constructor<string, float, float>())
			.def("SetDrawing", &Comment_System::set_drawing)
			.def("StopDrawing", &Comment_System::stop_drawing)
			.def("SetDialogue", &Comment_System::set_dialogue_new)
			.def("Run", &Comment_System::Run)
			.def("SetFlag", &Comment_System::SetFlag)
			.def("GetFlag", &Comment_System::GetFlag)
			.def("GetDummy", &Comment_System::GetDummy)
			.def("HasToComment",&Comment_System::HasToComment)
			.def("StopComment", &Comment_System::StopCommenting)
			.def("SetNPCText", &Comment_System::SetNPCText)
			.def("ShowDialogue3", &Comment_System::ShowDialogue3)
			.def("StartNarration", &Comment_System::StartNarration)
			.def("StopNarration", &Comment_System::StopNarration)
			.def("Narrate", &Comment_System::Narrate)
			];
		flag = 0;
		
	}
	void set_win(sf::VideoMode &Vmode,sf::RenderWindow *window)
	{
		vid=Vmode;
		win=window;
	}
	int GetFlag()
	{
		return flag;
	}
	void SetFlag()
	{
		flag = 1;
	}
	void set_drawing()
	{
		is_drawing =true;
	}
	void stop_drawing()
	{
		is_drawing = false;
	}
	void set_dialogue()
	{
		std::stringstream convert;
		


		for(int i=0;i<2;i++)
		{
			convert<<i;
			dialogue_angry_array[i]="c";
			
			dialogue_neu_array[i]="b";
			dialogue_good_array[i]="a";
			//std::cout<<dialogue_good_array[i]<<std::endl;
			dialogue_angry_array[i].append(convert.str());
			dialogue_neu_array[i].append(convert.str());
			dialogue_good_array[i].append(convert.str());
			
		}
	}

	void set_dialogue_new(string good1, string good2, string angry1, string angry2, string neu1, string neu2)
	{
	
		std::stringstream convert;

		dialogue_neu_array[0] = neu1;
		dialogue_neu_array[1] = neu2;
		dialogue_angry_array[0] = angry1;
		dialogue_angry_array[1] = angry2;
		dialogue_good_array[0] = good1;
		dialogue_good_array[1] = good2;

		for(int i=2;i<2;i++)
		{
			convert<<i;
			dialogue_angry_array[i]="c";
			
			dialogue_neu_array[i]="b";
			dialogue_good_array[i]="a";
			//std::cout<<dialogue_good_array[i]<<std::endl;
			dialogue_angry_array[i].append(convert.str());
			dialogue_neu_array[i].append(convert.str());
			dialogue_good_array[i].append(convert.str());
			
		}
	}
	void start_drawing()
	{
		if(is_drawing)
		{
				win->Draw(backgroundsp);
				win->Draw(comment_NPC_sp);
				win->Draw(comment_PC_sp);
				win->Draw(PC_cmt);
				win->Draw(PC_cmt1);
				
				if(has_to_comment== true)
				{

					for(int a=0;a<3;a++)
					{
					if(a==butt_no)
					{
						sub_menu.set_but_image(a,"../data/Images/s_button.png");
					}
					else if(a!=butt_no)
					{
						sub_menu.set_but_image(a,"../data/Images/button.png");
					}
				
					sub_menu.draw_button_comment_system(a,vid,win,m_startx, m_starty);
					}
				
				
				
				if (sub_menu_active==false&&dialogue_no==0)
				{
					

						option.LoadFromFile("../data/images/comment_1.png");
						
						optionsp.SetImage(option);
						win->Draw(optionsp);
						win->Draw(jpt);
				}
				else if(sub_menu_active==false&&dialogue_no==MAX_NO_OF_DIALOGUES-1)
				{
							
						option.LoadFromFile("../data/images/comment_fin.png");
						optionsp.SetImage(option);
						win->Draw(optionsp);
						win->Draw(jpt);
						
				}
				else if(sub_menu_active==false&&dialogue_no!=0&&dialogue_no!=MAX_NO_OF_DIALOGUES-1)
				{
						
						option.LoadFromFile("../data/images/comment_mid.png");
						optionsp.SetImage(option);
						win->Draw(optionsp);
						win->Draw(optionsp);
						win->Draw(jpt);		
						
				}
				
			}
			
			win->Display();
		}
	}
	void StartNarration()
	{
		is_narrating = true;
	}
	void StopNarration()
	{
		is_narrating = false;
	}
	int Narrate(int index)
	{
		if(is_narrating)
		{
			m_narration[index].SetPosition(m_startx, m_starty);
			win->Draw(m_narration[index]);
			win->Display();
		}
		int x = Run().get_i();
		return x;
	}
	void HasToComment()
	{
		has_to_comment=true;
	}
	void StopCommenting()
	{
		has_to_comment = false;
	}
	including Run()
	{
		sf::Event E;
		up=false;
		down=false;
		left=false;
		right=false;
		sub_menu_active=true;
		butt_no=0;
		i=0;
		j=0;
		dialogue_no=0;

		sub_menu.set_button(true,0);
		while(win->IsOpened())
		{
			while (win->GetEvent(E))
			{
            if (E.Type == sf::Event::Closed)
                win->Close();
			}
			if(is_narrating == true)
			{
				if(win->GetInput().IsKeyDown(Key::Q))
				{	
					str.set_i(-5);
					str.set_j(-5);
					return str;
				}
				else
				{
					str.set_i(-1);
					str.set_j(-1);
					return str;
				}
			}
			
			if(has_to_comment==true)
			{
				if(sub_menu_active==true&&win->GetInput().IsKeyDown(sf::Key::Up) && up== false)
				{
					if(butt_no>0)
					{
						up = true;
						butt_no = --i;
						
						std::cout<<butt_no<<std::endl;
						for(int i=0;i<3;i++)
						{
							if(i==butt_no)
							{
								sub_menu.set_button(true,i);
							}
							else
							{
								sub_menu.set_button(false,i);
							}
						}
		
					}
				}
				if(sub_menu_active==true&&!win->GetInput().IsKeyDown(sf::Key::Up) && up== true)
				{
					up = false;
				}
				if(sub_menu_active==true&&win->GetInput().IsKeyDown(sf::Key::Down) && down== false )
				{
					if(butt_no<sub_menu.no_of_buttons()-1)
					{
						down = true;
						butt_no = ++i;
						
						std::cout<<butt_no<<std::endl;
						for(int i=0;i<3;i++)
						{
							if(i==butt_no)
							{
								sub_menu.set_button(true,i);
							}
							else
							{
								sub_menu.set_button(false,i);
							}
						}
		
					}
				}
				if(sub_menu_active==true&&!win->GetInput().IsKeyDown(sf::Key::Down) && down== true)
				{
					down = false;
				}
				
					
				if(sub_menu_active==false&&win->GetInput().IsKeyDown(sf::Key::Up) && up== false)
				{
					if(dialogue_no>0)
					{
						up = true;
						dialogue_no = --j;
						std::cout<<dialogue_no<<std::endl;
					}
				}
				if(!win->GetInput().IsKeyDown(sf::Key::Down) && down== true)
				{
					down = false;
				}
				if(sub_menu_active==false&&win->GetInput().IsKeyDown(sf::Key::Down) && down== false)
				{
					if(dialogue_no<MAX_NO_OF_DIALOGUES-1)
					{
						down = true;
						dialogue_no = ++j;
						std::cout<<dialogue_no<<std::endl;	
					}
				}
				if(!win->GetInput().IsKeyDown(sf::Key::Up) && up== true)
				{
					up = false;
				}
			
				if(sub_menu_active==false&&win->GetInput().IsKeyDown(sf::Key::Left)&&left==false)
				{
					dialogue_no = 0;
					j=0;
					sub_menu_active=true;
					left=true;
				}
				if(sub_menu_active==false&&!win->GetInput().IsKeyDown(sf::Key::Left)&&left==true)
				{
					left=false;
				}
			
				if(sub_menu_active==true&&win->GetInput().IsKeyDown(sf::Key::Right)&&right==false)
				{
					sub_menu_active=false;
					right=true;
				}
				if(sub_menu_active==true&&!win->GetInput().IsKeyDown(sf::Key::Right)&&right==true)
				{
					right=false;
				}
				if(sub_menu_active==false&&sub_menu.but_active(0))
				{
					
					jpt.SetText(dialogue_good_array[dialogue_no]);
				}
				else if(sub_menu_active==false&&sub_menu.but_active(1))
				{
					jpt.SetText(dialogue_neu_array[dialogue_no]);
				}
				else if(sub_menu_active==false&&sub_menu.but_active(2))
				{
					jpt.SetText(dialogue_angry_array[dialogue_no]);
				}
				if(sub_menu_active==false&&win->GetInput().IsKeyDown(sf::Key::Return))
				{
					sub_menu_active=true;
					
					if(sub_menu.but_active(0))
					{
						PC_cmt.SetText(dialogue_good_array[dialogue_no]);
						
					}
					else if(sub_menu.but_active(1))
					{
						PC_cmt.SetText(dialogue_neu_array[dialogue_no]);
					}
					else if(sub_menu.but_active(2))
					{
						PC_cmt.SetText(jpt.GetText());
					}
				
				
					str.set_i(butt_no);
					str.set_j(dialogue_no);
					
					dialogue_no=0;
					
					return str;
					
				}
				
				}
				else
				{
				//	PC_cmt1.SetText("Test");

				}
				if(win->GetInput().IsKeyDown(Key::Escape))
				{	
					str.set_i(-1);
					str.set_j(-1);
					return str;
				}
				if(win->GetInput().IsKeyDown(Key::P))
				{
					HasToComment();
				}
				start_drawing();
			}
			str.set_i(-1);
			str.set_j(-1);

			return str;
		}

		void SetNPCText(std::string text)
		{
			PC_cmt1.SetText(text);
		}

		including GetDummy()
		{
			including s;
			s.set_i(0);
			s.set_j(0);
			return s;
		}

		including ShowDialogue3()
		{
			win->Draw(Dialogue3Sp);
			including str;
			str.set_i(0);
			str.set_j(0);
			if(win->GetInput().IsKeyDown(Key::Escape))
			{
				str.set_i(-2);
				str.set_j(-2);
				return str;
			}
			return str;
		}


		
	
};