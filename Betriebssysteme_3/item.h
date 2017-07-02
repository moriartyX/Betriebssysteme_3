#pragma once

#include <iostream>
#include <array>
#include <string>

using namespace std;

class item
{
private:
	int Value = 0;
	bool Chance;
public:
	item();
	item(int, bool);
	~item();

	void setValue(int);
	int getValue();

	void setChance(bool);
	bool getChance();

};
