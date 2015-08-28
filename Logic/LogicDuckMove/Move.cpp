/*
 * Move.cpp
 *
 *  Created on: Aug 10, 2015
 *      Author: pablo
 */

#include "Move.h"

using namespace std;

Move::Move(int pduck_type) {
	// TODO Auto-generated constructor stub
	this->_duckType = pduck_type;
	setRandomInitCoords();
	move();
}

Move::~Move() {
	// TODO Auto-generated destructor stub
}

void Move::setRandomInitCoords(){

	this->_positionX = this->randomPositionX(); //Función random que retorna un punto en X.

	this->_positionY = POSICIONYINICIAL; //100, pues siempre sale del piso.

}

int Move::getCoordX(){

	return _positionX;

}

/**
 * LONGITUDPANTALLAEFECTIVA hace referencia a los 1170 pixeles que se poseen para mover
 * los patos. La ventana mide 1200 pixeles, pero se le debe restar los 80 del pato.
 *
*/
int Move::randomPositionX(){

	srand((unsigned)time(0));

	return rand() % LONGITUDPANTALLAEFECTIVA;
}

int Move::randomFlagDirection(){

	srand((unsigned)time(0));

	return rand() % 2; //Retorna un 0 o 1. Se interpretará como izquierda o derecha.
}

int Move::getCoordY(){

	return _positionY;

}

int Move::getDuckType(){

	return _duckType;
}

void Move::moveY(int pduck_type){

	switch(pduck_type){

	case 1:

		moveColoradoYDuck();

		break;

	case 3:

		moveTarroCaneloYDuck();

		break;

	case 4:

		moveYaguasaPiquirrojoYDuck();

		break;

	default:

		moveGansoDeHawai_WildDuckY();

		break;

	}

}

void Move::setFlagLifeFalse(){

	this->_lifeFlag = false;

}

void Move::generalMove(int pduck_speed){

	/*
	 * Este método se encarga de manejar el eje X de los objetos.
	 */

	switch(directionXFlag){ //Esta bandera es igual a la de Y, pero maneja el eje X.

		case 0: //Se mueve hacia la derecha

			while(this->_positionX + LONGITUDIMAGENPATO < LONGITUDPANTALLA){

				/*
				 * En este caso se debe de considerar la variable de la longitud de la
				 * imagen del pato, puesto que el punto de referencia se encuentra en
				 * la esquina superior izquierda de la imagen.
				 */

				this->_positionX += pduck_speed;

				moveY(this->_duckType);

				std::cout << "Nueva posicion X: " << this->_positionX << std::endl;

				std::cout << "Nueva posicion Y: " << this->_positionY << std::endl;

			}

			directionXFlag = 1;

			break;

		case 1: //Se mueve hacia la izquierda.

			while(this->_positionX > 0){

				this->_positionX+= -pduck_speed;

				moveY(this->_duckType);

				std::cout << "Nueva posicion X: " << this->_positionX << std::endl;

				std::cout << "Nueva posicion Y: " << this->_positionY << std::endl;

			}

			directionXFlag = 0;

			break;

		}

}

/**
 * Este método se encarga únicamente de mover los objetos en el eje Y, verificando
 * que ninguno esté saliéndose del área de cobertura y que se tomen las medidas
 * apropiadas cuando estos llegan a los extremos de la ventana.
 * Este método es genérico prácticamente, su única variación con el resto
 * es que es especificado tanto para Ganso De Hawai como para Pato Salvaje por cuestión
 * de que comparten la velocidad de movimiento, factor determinante para no realizar
 * un solo método y utilizarlo para todos los patos.
 * @param pduck_speed
 */
void Move::generalMoveY(int pduck_speed){

		switch(directionYFlag){ //Se evalúa el índice de la BANDERADEDIRECCIONY.

			case 0: //Se mueve hacia arriba

				if (this->_positionY < ANCHOPANTALLA) //Evitando que el pato choque.

					this->_positionY+= pduck_speed; //Aumenta la coordenada Y.
					//Aumenta la cantidad de pixeles definidos previamente en constantes.

				else{

					directionYFlag = true; //De chocar el objeto con el límite superior
					//se cambia la bandera para que ahora se mueva hacia abajo.

					this->_positionY+= -pduck_speed; //Se le suma un valor
					//negativo, asegurando un movimiento en picada.

				}

				break;

			default: //Se mueve hacia abajo. Todos estos valores son iguales a los anteriores
				//sólo que con los valores invertidos.

				if (this->_positionY > LONGITUDIMAGENPATO)

					this->_positionY-= pduck_speed;

				else{

					directionYFlag = false;

					this->_positionY+= +pduck_speed;

				}

				break;

			}

}

void Move::moveGansoDeHawai_WildDuckY(){

		generalMoveY(VELOCIDADGANSODEHAWAI_PATOSALVAJE);

}

void Move::moveTarroCaneloYDuck(){

	generalMoveY(VELOCIDADTARROCANELO);

}

void Move::moveYaguasaPiquirrojoYDuck(){

	generalMoveY(VELOCIDADYAGUASAPIQUIRROJO);

}

void Move::moveColoradoYDuck(){

	generalMove(VELOCIDADPATOCOLORADO);

}

void Move::moveColoradoDuck(){

	generalMove(VELOCIDADPATOCOLORADO);

}

void Move::moveTarroCaneloDuck(){

	generalMove(VELOCIDADTARROCANELO);

}

void Move::moveGansoDeHawai_WildDuck(){

	generalMove(VELOCIDADGANSODEHAWAI_PATOSALVAJE);

}

void Move::moveYaguasaPiquirrojoDuck(){

	generalMove(VELOCIDADYAGUASAPIQUIRROJO);

}

void Move::move(){

	//Éste es el método general que manejará de manera general el movimiento de todos
	//los patos en pantalla. Tiene submétodos, con sus propios submétodos.

	while(this->_lifeFlag == true){
		//El pato obviamente se va a mover únicamente si se encuentra vivo en pantalla.
		sleep(0.8);
		switch(_duckType){

			case 1:

				this->moveColoradoDuck();

				break;
				/*
				 * Aquí se evidencia el uso del índice de tipoDePato para controlar
				 * diferentes tipos de patos. En este caso, el 1 simboliza al Pato
				 * Colorado, el 3 al Tarro Canelo, el 4 al Yaguasa Piquirrojo y tanto el 2 como el 5
				 * simbolizan al GansoDeHawai y al Pato Salvaje. Esta situación fue previamente
				 * explicada en el método de moverGansoDeHawai_PatoSalvajeY().
				 */

			case 3:

				this->moveTarroCaneloDuck();

				break;

			case 4:

				this->moveYaguasaPiquirrojoDuck();

				break;

			default:

				this->moveGansoDeHawai_WildDuckY();

				break;
		}
	}
}

