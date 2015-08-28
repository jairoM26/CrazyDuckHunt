/*
 * Duck.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef LOGIC_LOGICDUCKS_DUCK_H_
#define LOGIC_LOGICDUCKS_DUCK_H_

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../LogicConstants.h"
#include "../LogicDuckMove/Move.h"

class Duck : public LogicConstants
{
public:
	Duck(int pduck_type);
	virtual ~Duck();
	void setDuckValues(int pduck_type); //Metodo que le asgina las propiedades al pato.
	int getLife(); //Retorna la cantidad de balas que puede recibir antes de morir.
	int getDuckType(); //Retorna el indice que identifica a cada pato.
	void reduceLife(); //Reduce en 1 la vida del pato al ser impactado por una bala.
	int getPointsToGive(); //Retorna la cantidad de puntos que aporta un pato al morir.
	float getProbability(); //Retorna la probabilidad inicial.
	virtual void releaseProbability(); //Reduce o aumenta la probabilidad de cada pato.
	void setId(); //Le asigna una identificación aleatoria a la instancia de pato.
	int getId(); //Retorna el identificador creado anteriormente.
	Move* getMoveObject();

private: //Definición de los atributos de una clase.

	int _life , _pointsToGive, _duckType, _id;
	float _probability;
	Move* _movement;
};

#endif /* LOGIC_LOGICDUCKS_DUCK_H_ */
