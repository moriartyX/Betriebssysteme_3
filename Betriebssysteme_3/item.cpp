#include "stdafx.h"
#include "item.h"


item::item()
{
}

item::item(int value, bool chance)
{
	setValue(value);
	setChance(chance);
}


item::~item()
{
}

void item::setValue(int value)
{
	Value = value;
}

int item::getValue()
{
	return Value;
}

void item::setChance(bool chance)
{
	Chance = chance;
}

bool item::getChance()
{
	return Chance;
}
