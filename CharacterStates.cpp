#include "CharacterStates.h"
#include "Character.h"

NotInteracting* NotInteracting::Instance()
{
	static NotInteracting instance;
	return &instance;
}


void NotInteracting::Enter(Character *io)
{
}

void NotInteracting::Execute(Character *io)
{
	io->NotInteracting();
	
	
}

void NotInteracting::Exit(Character *io)
{
	
}




Interacting* Interacting::Instance()
{
	static Interacting instance;
	return &instance;
}


void Interacting::Enter(Character *io)
{
}

void Interacting::Execute(Character *io)
{
	io->Interacting();
	
	
}

void Interacting::Exit(Character *io)
{
	
}