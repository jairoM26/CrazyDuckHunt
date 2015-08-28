/*
 * Move.h
 *
 * 	Created on: Aug 10, 2015
 *      Author: pablo
 */

#ifndef LOGIC_LOGICDUCKMOVE_MOVE_H_
#define LOGIC_LOGICDUCKMOVE_MOVE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "../LogicConstants.h"

class Move : public LogicConstants
{
public:
	Move(int pduck_type);
	virtual ~Move();

	int getCoordX(); //retorna la coordenada X del pato instanciado.
	int getCoordY(); //retorna la coordenada Y del pato instanciado.
	int getDuckType(); //retorna el tipo de pato instanciado.
	void setFlagLifeFalse();

private:
	int _positionX, _positionY, _duckType;

	bool _lifeFlag = true; //Indica si la instancia vive o no.

	int directionXFlag = randomFlagDirection(); //Indica si el pato sale hacia la izquierda o derecha.

	int directionYFlag = 0; //Indica si el pato sube o baja. Como es el inicial, siempre sube.

	void setRandomInitCoords(); //Configura las coordenadas iniciales.

	void move(); //Método encargado de manejar el movimiento de manera general.

	int randomPositionX(); //Genera un valor aleatorio para iniciar el movimiento en X.

	int randomFlagDirection(); //Genera un valor aleatorio para la bandera.

	void moveColoradoDuck(); //Submétodo de mover() que mueve en X a pato colorado.

	void moveColoradoYDuck(); //Submétodo de mover() que mueve en Y a pato colorado.

	void moveTarroCaneloDuck(); //Submétodo de mover() que mueve en X a tarro canelo.

	void moveTarroCaneloYDuck(); //Submétodo de mover() que mueve en Y a tarro canelo.

	void moveGansoDeHawai_WildDuck(); //Submétodo de mover() que mueve en X a ganso de Hawai.

	void moveGansoDeHawai_WildDuckY(); //Subḿetodo de mover() que mueve en Y a ganso de Hawai.

	void moveYaguasaPiquirrojoDuck(); //Submétodo de mover() que mueve en X a Yaguasa Piquirrojo.

	void moveYaguasaPiquirrojoYDuck(); //Submétodo de mover() que mueve en Y a Yaguasa Piquirrojo.

	void moveWildDuck(); //Submétodo de mover() que mueve en X a pato salvaje.

	void moverWildDuckY(); //Submétodo de mover() que mueve en Y a pato salvaje.

	void generalMoveY(int pduck_speed);

	void generalMove(int pduck_speed);

	void moveY(int pduck_type);

};

#endif /* LOGIC_LOGICDUCKMOVE_MOVE_H_ */
