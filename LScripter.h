#pragma once
#include <iostream>
extern "C" {
#include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}
#include <luabind\luabind.hpp>

using namespace std;
class LScripter
{
public:
	LScripter(void)
	{
	}

	void RunScript(lua_State *L, string scriptName, bool scripting)
	{
		//const char *script = scriptName.c_str();
	//	char *script = strdup(scriptName.c_str());
		if(scripting==true)
		{
		luaL_dofile(L, scriptName.c_str());
		cout<<scriptName.c_str();
		}
	}

	

	~LScripter(void)
	{
	}
};

