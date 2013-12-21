#include "NPCStates.h"
#include "NPC.h"

Strong* Strong::Instance()
{
	static Strong instance;
	return &instance;
}


void Strong::Enter(NPC *io)
{
}

void Strong::Execute(NPC *io)
{
	if(io->GetAttack()<=50) io->GetStrengthStateManager()->ChangeState(Weak::Instance());
}

void Strong::Exit(NPC *io)
{
	
}




Weak* Weak::Instance()
{
	static Weak instance;
	return &instance;
}


void Weak::Enter(NPC *io)
{
}

void Weak::Execute(NPC *io)
{
	if(io->GetAttack()>50) io->GetStrengthStateManager()->ChangeState(Strong::Instance());
	
}

void Weak::Exit(NPC *io)
{
	
}

Poor* Poor::Instance()
{
	static Poor instance;
	return &instance;
}


void Poor::Enter(NPC *io)
{
}

void Poor::Execute(NPC *io)
{
	if(io->GetGold()>=500) io->GetWealthStateManager()->ChangeState(Wealthy::Instance());	
}

void Poor::Exit(NPC *io)
{
	
}


Wealthy* Wealthy::Instance()
{
	static Wealthy instance;
	return &instance;
}


void Wealthy::Enter(NPC *io)
{
}

void Wealthy::Execute(NPC *io)
{
	if(io->GetGold()<500) io->GetWealthStateManager()->ChangeState(Poor::Instance());
	
	
}

void Wealthy::Exit(NPC *io)
{
	
}


Alive* Alive::Instance()
{
	static Alive instance;
	return &instance;
}


void Alive::Enter(NPC *io)
{
}

void Alive::Execute(NPC *io)
{	if(io->GetHealth()<=0){io->GetStateManager()->ChangeState(Dead::Instance());}
	
}

void Alive::Exit(NPC *io)
{
	
}


Dead* Dead::Instance()
{
	static Dead instance;
	return &instance;
}


void Dead::Enter(NPC *io)
{
}

void Dead::Execute(NPC *io)
{
	if(io->GetHealth()>0){io->GetStateManager()->ChangeState(Alive::Instance());}

	
}

void Dead::Exit(NPC *io)
{
	
}