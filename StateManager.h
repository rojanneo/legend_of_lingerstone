/*
	
	$StateManager.h

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

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_
#include "State.h"

template <class BaseEntity>
class StateManager
{
private:
	BaseEntity *m_owner;
	State<BaseEntity> *m_CurrentState;
	State<BaseEntity> *m_PreviousState;
	State<BaseEntity> *m_GlobalState;
public:
	StateManager(BaseEntity *owner): m_owner(owner), m_CurrentState(0), m_PreviousState(0), m_GlobalState(0)
	{}
	void SetCurrentState(State<BaseEntity> *s) { m_CurrentState = s;}
	void SetPreviousState(State<BaseEntity> *s) {m_PreviousState = s;}
	void SetGlobalState(State<BaseEntity> *s) {m_GlobalState = s;}

	void Update()
	{
		if(m_GlobalState) m_GlobalState->Execute(m_owner);
		if(m_CurrentState) m_CurrentState->Execute(m_owner);
	}

	void ChangeState(State<BaseEntity> *newState)
	{
		m_PreviousState = m_CurrentState;
		m_CurrentState->Exit(m_owner);
		m_CurrentState = newState;
		m_CurrentState->Enter(m_owner);
	}

	void RevertToPreviousState()
	{
		ChangeState(m_PreviousState);
	}
	State<BaseEntity>*  CurrentState()  const{return m_CurrentState;}
	State<BaseEntity>*  GlobalState()   const{return m_GlobalState;}
	State<BaseEntity>*  PreviousState() const{return m_PreviousState;}

};
#endif