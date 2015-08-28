/*
 * DuckManager.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: jairo-mm
 */

#include "DuckManager.h"

DuckManager::DuckManager() {
	// TODO Auto-generated constructor stub
	duck_counter = 0;
	duck_list = new LinkedList<Duck*>();
	facade = new Facade();
	timer = clock();
}

DuckManager::~DuckManager() {
	// TODO Auto-generated destructor stub
}

void DuckManager::insertDuckToList()
{
	cout << "tiempo " << theresNoTime() << endl;
	cout << "patos " << theresNoDuck() << endl;
	if(theresNoDuck() == true || theresNoTime() == true)
	{
		Duck* duck_tmp = new Duck(rand() % 5);
		duck_list->insertData(duck_tmp);
		facade->insertDuck();
	}
	duck_counter++;
}

bool DuckManager::theresNoDuck()
{
	double secs = (double)(timer);
	if(secs == 1.5*1000.0 || secs == 3.0*1000.0 || secs == 4.5*1000.0 || secs == 6.0*1000.0)
		return true;

	return false;
}

bool DuckManager::theresNoTime()
{
	if(duck_counter == 0)
		return true;
	return false;
}
