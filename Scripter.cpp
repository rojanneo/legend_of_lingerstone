#include "Scripter.h"

Scripter::Scripter(void)
{
	m_noOfLines = 1;
	m_stringParameter = "";
	m_command = "";
	m_intParameter = 0;
	m_counter = 0;
	string path = "..\\Scripts\\copyright.png";
	
}

int Scripter::m_pointer = 0;

bool Scripter::LoadScript(string filename)
{
	m_file.open(filename);
	
	if(!m_file)
	{
		cout<<"Unable to Load Script";
		return false;
	}

	while(!m_file.eof())
	{
		if(m_file.get() == '\n')
		{
			m_noOfLines++;
		}
	}

	m_file.close();
	m_file.open(filename);
	char tempCommand[1000];
	for(int i = 0; i<m_noOfLines; i++)
	{
		m_file.getline(tempCommand, 1000);
		m_entireCommand[i] = tempCommand;
	}
	return true;
}

int Scripter::RunScript(sf::Image *img, sf::Sprite *spr)
{
		if(m_pointer>=m_noOfLines) return 2;
		int i = m_pointer;
		GetCommand(m_entireCommand[i]);
		if(m_command == COMMAND_SLEEP)
		{
			GetIntParameter(m_entireCommand[i]);
			int time = m_intParameter;
			Sleep(time*1000);
		}
		else if(m_command == COMMAND_DRAW)
		{
			GetStringParamenter(m_entireCommand[i]);
			string path = m_stringParameter;
			img->LoadFromFile(path);
			spr->SetImage(*img);
		}
		else 
		{
			cout<<endl<<"INVALID COMMAND: "<<m_entireCommand[i]<<endl;
			_getch();
		}
		m_pointer++;
		return 0;
}


void Scripter::GetCommand(string entireCommand)
{
	char temp[1000];
	for(int i = 0; i<1000; i++)
	{
		temp[i] = '\0';
	}
	int count = 0;
	for(int i = 0; i<(int)entireCommand.length(); i++)
	{
		if(entireCommand.c_str()[i] == ' ')
		{
			temp[count] = '\0';
			break;
		}
		else
		{
			count++;
			temp[i] = entireCommand.c_str()[i];
		}
	}
	m_command = temp;
	m_counter = count;
}

void Scripter::GetStringParamenter(string entireCommand)
{
	char temp[1000];
	for(int i = 0; i<1000; i++)
	{
		temp[i] = '\0';
	}
	
	for(int i = m_counter + 2, j = 0; i<(int)entireCommand.length(); i++, j++)
	{
		if(entireCommand.c_str()[i] == '"')
		{
			temp[m_counter] = '\0';
			break;
		}
		else
		{
			m_counter++;
			temp[j] = entireCommand.c_str()[i];
		}
	}
	m_counter+=2;
	m_stringParameter = temp;
}

void Scripter::GetIntParameter(string entireCommand)
{
	char temp[1000];
	for(int i = 0; i<1000; i++)
	{
		temp[i] = '\0';
	}
	
	for(int i = m_counter+1, j = 0; i<(int)entireCommand.length(); i++, j++)
	{
		if(entireCommand.c_str()[i] == ' ')
		{
			temp[m_counter] = '\0';
			break;
		}
		else
		{
			m_counter++;
			temp[j] = entireCommand.c_str()[i];
		}
	}
	m_counter++;
	m_intParameter = atoi(temp);
}


Scripter::~Scripter(void)
{
}
