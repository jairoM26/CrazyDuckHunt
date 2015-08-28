/*
 * Duck.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: pablo
 */

#include "Duck.h"

using namespace std;

/**
 * El parametro "Vida" se basa en la cantidad de balas que puede
 * recibir el pato, el cual se va a ir reduciendo con cada bala recibida.
 * El parametro PuntosQueAporta se va a mantener constante y va
 * a depender de cada pato.
 * El parametro Probabilidad va a ir cambiando con cada cambio de nivel
 * @param pDuckType: es un índice que refleja la naturaleza de cada pato.
 */
Duck::Duck(int pDuckType) {
	// TODO Auto-generated constructor stub
	_duckType = pDuckType;

	setDuckValues(_duckType);

	_movement = new Move(_duckType);

	setId();
}

Duck::~Duck() {
	// TODO Auto-generated destructor stub
}

void Duck::setDuckValues(int pduck_type){

	switch(_duckType){ //De acuerdo al tipo de pato se le asignan los valores correspondientes.

	case 1:

		this->_life = VIDAPATOCOLORADO ;

		this->_pointsToGive = PUNTOSPATOCOLORADO;

		this->_probability = PROBABILIDADINICIALPATOCOLORADO;

		break;

	case 3:

		this->_life = VIDATARROCANELO ;

		this->_pointsToGive = PUNTOSTARROCANELO;

		this->_probability = PROBABILIDADINICIALTARROCANELO;

		break;

	case 2:

		this->_life = VIDAPATOSALVAJE;

		this->_pointsToGive = PUNTOSPATOSALVAJE;

		this->_probability = PROBABILIDADINICIALPATOSALVAJE;

		break;

	case 4:

		this->_life = VIDAYAGUASAPIQUIRROJO;

		this->_pointsToGive = PUNTOSYAGUASAPIQUIRROJO;

		this->_probability = PROBABILIDADINICIALYAGUASAPIQUIRROJO;

		break;

	default:

		this->_life = VIDAGANSODEHAWAI;

		this->_pointsToGive = PUNTOSGANSODEHAWAI;

		this->_probability = PROBABILIDADINICIALGANSODEHAWAI;

	}

}

void Duck::releaseProbability(){

	this->_probability = _probability + AUMENTOPROBABILIDAD;

	/*
	 * Dado que en la mayoría de los casos los patos aumentan de probabilidad,
	 * y sólo uno la disminuye, por motivos de eficiencia se decidió que to -
	 * dos la aumentaran y el que la disminuye que acople el método.
	 */

}

/**
 * Retorna la vida del pato
 * @return _life
 */
int Duck::getLife(){

	return _life;
}

/**
 * Se utiliza una función aleatorioa que retorne un número entre 0 y el límite
 * (100 en este caso) con el fin de utilizar dicho número como un identificador
 * y evitar así que dos o más patos tengan el mismo identificador.
 */
void Duck::setId(){

	srand(unsigned(time(0)));

	this->_id = rand()%100;
}

/**
 *
 */
void Duck::reduceLife(){

	this->_life = _life - 1; //Puesto que están en función de las balas que aguanta.

}

/**
 *
 * @return
 */
int Duck::getPointsToGive(){

return _pointsToGive;

}

/**
 *
 * @return
 */
float Duck::getProbability(){

	return _probability;

}

/**
 *
 * @return
 */
int Duck::getDuckType(){

	return this->_duckType;

}

Move* Duck::getMoveObject(){

	return _movement;

}
