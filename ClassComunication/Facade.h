/*
 * Facade.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef CLASSCOMUNICATION_FACADE_H_
#define CLASSCOMUNICATION_FACADE_H_

#include "../Logic/LogicDucks/Duck.h"
#include "../DataStructure/LinkedList.h"
class Facade {
public:
	Facade();
	virtual ~Facade();
	void insertDuck();
};

#endif /* CLASSCOMUNICATION_FACADE_H_ */
