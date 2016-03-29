#include "ExitRoom.h"



ExitRoom::ExitRoom()
{
	descript.Append("\nYou are in a Tunnel.\nThere is a largedemon blocking your path to freedom.\n\n");
}

ExitRoom::~ExitRoom()
{
}

void ExitRoom::Update(MyString command)
{
	descript.print();

}
