#ifndef INCLUDING_H_
#define INCLUDING_H_

#include<iostream>

class including
{
private:
	int i;
	int j;
	lua_State *l;
public:
	void set_i(int a)
	{
		i=a;
	}
	void set_j(int b)
	{
		j=b;
	}
	int get_i()
	{
		return i;
	}
	int get_j()
	{
		return j;
	}
	void RegisterToLua(lua_State *ls)
	{
		l = ls;
		luabind::module(l)
			[
				luabind::class_<including>("including")
			//.def(luabind::constructor<string, float, float>())
			.def("GetI", &including::get_i)
			.def("GetJ", &including::get_j)
			.def("SetI", &including::set_i)
			.def("SetJ", &including::set_j)
			];
	}
};

#endif