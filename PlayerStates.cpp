#include "PlayerStates.h"
#include "Player.h"

PlayerAlive* PlayerAlive::Instance()
{
	static PlayerAlive instance;
	return &instance;
}


void PlayerAlive::Enter(Player *io)
{
}

void PlayerAlive::Execute(Player *io)
{	
	if(io->GetHealth()<=0){io->GetStateManager()->ChangeState(PlayerDead::Instance());}
	
}

void PlayerAlive::Exit(Player *io)
{
	
}


PlayerDead* PlayerDead::Instance()
{
	static PlayerDead instance;
	return &instance;
}


void PlayerDead::Enter(Player *io)
{
}

void PlayerDead::Execute(Player *io)
{
	if(io->GetHealth()>0){io->GetStateManager()->ChangeState(PlayerAlive::Instance());}	
}

void PlayerDead::Exit(Player *io)
{
	
}