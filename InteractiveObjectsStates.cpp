#include "InteractiveObjectsStates.h"
#include "InteractiveObjects.h"

NotInteracted* NotInteracted::Instance()
{
	static NotInteracted instance;
	return &instance;
}


void NotInteracted::Enter(InteractiveObjects *io)
{
}

void NotInteracted::Execute(InteractiveObjects *io)
{
	io->NotInteracted();
	
	
}

void NotInteracted::Exit(InteractiveObjects *io)
{
	
}




Interacted* Interacted::Instance()
{
	static Interacted instance;
	return &instance;
}


void Interacted::Enter(InteractiveObjects *io)
{
}

void Interacted::Execute(InteractiveObjects *io)
{
	io->Interacted();
	
	
}

void Interacted::Exit(InteractiveObjects *io)
{
	
}