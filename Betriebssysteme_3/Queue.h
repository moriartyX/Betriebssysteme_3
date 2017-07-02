#pragma once

#include "item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Queue
{
private:
	array<item*, 5> dings;
	int head = 0;
	int tail = 0;
public:
	Queue();
	~Queue();

	void addItem(item*);
	item* removeItem();
	int size();
	void display();
	bool isEmpty();
	/*void isEmpty();*/
	bool isFull(item*);
	

	void output();
	void menue();
};

