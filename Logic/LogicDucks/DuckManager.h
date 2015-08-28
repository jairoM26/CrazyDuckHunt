/*
 * DuckManager.h
 *
 *  Created on: Aug 28, 2015
 *      Author: jairo-mm
 */

#ifndef LOGIC_LOGICDUCKS_DUCKMANAGER_H_
#define LOGIC_LOGICDUCKS_DUCKMANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../../DataStructure/LinkedList.h"
#include "../../ClassComunication/Facade.h"
#include "Duck.h"

using namespace std;

class DuckManager {
public:
	DuckManager();
	virtual ~DuckManager();

private:
	Facade* facade;
	LinkedList<Duck*>* duck_list;
	int duck_counter;
	clock_t timer;
//	Timer timer;
	void insertDuckToList();
	bool theresNoDuck();
	bool theresNoTime();
};

#endif /* LOGIC_LOGICDUCKS_DUCKMANAGER_H_ */
