/*
 * Observer.h
 *
 *	Created on: Aug 19, 2015
 *      Author: pablo
 */

#ifndef CLASSCOMUNICATION_OBSERVER_H_
#define CLASSCOMUNICATION_OBSERVER_H_

#include "../DataStructure/LinkedList.h"
#include "../Logic/LogicDucks/Duck.h"
#include "../Logic/LogicConstants.h"

#define SNIPERPIXELSSIZE 50

class Observer : public LogicConstants{
public:
	Observer(int sniperCoordX, int sniperCoordXY);
	virtual ~Observer();
	void shootCheck();

private:
	LinkedList<Duck*>* duck_list;
	int coordX, coordY;

};

#endif /* CLASSCOMUNICATION_OBSERVER_H_ */
