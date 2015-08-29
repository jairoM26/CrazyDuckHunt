/*
 * main.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#include <iostream>

#include "DataStructure/LinkedList.h"
#include "Logic/LogicDucks/Duck.h"

int main()
{
	LinkedList<Duck*>* list_duck = new LinkedList<Duck*>();
	list_duck->insertData(new Duck(1));
	list_duck->insertData(new Duck(2));
	list_duck->insertData(new Duck(3));
	list_duck->showList();
	std::cout << "Hola Mundo" << std::endl;
	return 0;
}



