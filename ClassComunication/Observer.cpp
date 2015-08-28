/*
 * Observer.cpp
 *
 * 	Created on: Aug 19, 2015
 *      Author: pablo
 */

#include "Observer.h"

Observer::Observer(int sniperCoordX, int sniperCoordY) {
	// TODO Auto-generated constructor stub
	this->coordX = sniperCoordX;

	this->coordY = sniperCoordY;

	duck_list = new LinkedList<Duck*>();
}

Observer::~Observer() {
	// TODO Auto-generated destructor stub
}

void Observer::shootCheck()
{
	for(int i = 0; i < duck_list->getLen(); i++)
	{
		Duck* duck_tmp = duck_list->getDatabyIndex(i);
		if((duck_tmp->getMoveObject()->getCoordX() + LONGITUDIMAGENPATO <= coordX ) &&
				(duck_tmp->getMoveObject()->getCoordX() - LONGITUDIMAGENPATO >= coordX) )
		{
			if ((duck_tmp->getMoveObject()->getCoordY() + LONGITUDIMAGENPATO <= coordX ) &&
				(duck_tmp->getMoveObject()->getCoordY() - LONGITUDIMAGENPATO >= coordX) )
			{
				duck_tmp->reduceLife();
				if(duck_tmp->getLife() <= 0)
				{
					duck_tmp->getMoveObject()->setFlagLifeFalse();
					duck_list->deleteData(duck_tmp);
				}
			}
		}
	}
}
