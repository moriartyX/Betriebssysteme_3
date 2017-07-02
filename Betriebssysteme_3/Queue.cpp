#include "stdafx.h"
#include "Queue.h"
#include <fstream>



Queue::Queue()
{
	for (int i = 0; i < dings.size(); i++) {
		item* first = new item(-1, true);
		dings[i] = first;
	}
}


Queue::~Queue()
{
}


void Queue::addItem(item* data){
	
		if (!this->isFull(data)) {
			
			if (tail == dings.size()) {
				for (int i = dings.size() - 1; i > 0;) {
					if (dings[tail - i]->getValue() != data->getValue()) {
						if (dings[tail -i]->getChance() == true) {
							dings[tail-i]->setChance(false);
							dings[tail + 1];
							}
						}
						--i;
					}
				tail = 0;
				}
				dings[tail] = data;
				cout << "Objekt an Stelle: " << tail << " wurde gespeichert: "
					<< dings[tail]->getValue() << endl;
				tail = ((tail + 1) % (dings.size() + 1));
	}
}

//item* Queue::removeItem(){
//	item* temp;
//	temp = dings[head];
//	head = (head + 1) % (dings.size() +1);
//	return temp;
//}

int Queue::size(){
	return (tail - head);
}

void Queue::display(){
//	int i;
//	if (!this->isEmpty()) {
//		for (i = head; i != tail; i = (i + 1) % (dings.size()+1)) {
//			cout << "Wert: " << dings[i]->getValue() << " , " << "Chance: " << dings[i]->getChance() << endl;
//		}
//	}
//	else
//		cout << "Queue inhalt" << endl;
}

bool Queue::isEmpty(){
	if (abs(head == tail))
		return true;
	else
		return false;
}

//void Queue::isEmpty() {
//	//
//	//cout << "groeße "<< dings.size()<<endl;
//	//cout << "Größe?" << dings.max_size() << endl;
//}

bool Queue::isFull(item* data){

	int counter = 0;
		for (int i = 0; i < dings.size(); i++) {

			if (dings[i]->getValue() == -1)
				counter++;
			}

	if (counter != 5){
		if (head == (dings.size() - counter) % dings.size()) {
			cout << "Seitenfehler: " << data->getValue() << endl;
			for (int i = head; i != tail; i = (i + 1) % (dings.size() + 1)) {
				dings[i]->setChance(false);
			}
		}
			return false;
		}
		return false;
}


void Queue::output(){
	bool isEven;
	ofstream outputFile("test.txt", ios::out);

		for (int i=0; i< 10; i++) {
			int random;
			random = rand() % 100 + 1;
			if (isEven = ((random % 1) == 0)) {
				outputFile << random << "," << isEven << endl;
				cout << random << "," << isEven << endl;
			}
		else
		{
			outputFile << random << "," << "0" << endl;
			cout << random << "," << "0" << endl;
		}

	}

}

void Queue::menue(){
	string v, c;
	bool chance;
	ifstream inFile("test.txt", ios::in);

	cout << "Daten werden gelesen....." << endl;
	while (!inFile.eof())
	{
		getline(inFile, v, ',');
		if (v != "") {
			int value = stoi(v);

			getline(inFile, c);
			if (c == "1") {
				chance = true;
			}
			else {
				chance = false;
			}
			item* itemObjekt = new item(value, chance);
			addItem(itemObjekt);
		}
		else {
			cout << "Fertig!" << endl;
		}
	}

}
