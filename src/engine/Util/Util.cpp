/*
 * Util.cpp
 *
 *  Created on: 02-Oct-2019
 *      Author: pluto
 */

#include "Util.h"

bool isIntercept(sf::FloatRect boundsOfBodyA, sf::FloatRect boundsOfBodyB) {
	if((boundsOfBodyB.left > boundsOfBodyA.left) && ((boundsOfBodyB.width + boundsOfBodyB.left) < (boundsOfBodyA.width + boundsOfBodyA.left)) && (boundsOfBodyB.top > boundsOfBodyA.top) && ((boundsOfBodyB.height + boundsOfBodyB.top) < (boundsOfBodyA.height + boundsOfBodyA.top))) {
		return true; //Body B is inside body A
	} else {
		sf::FloatRect temp = boundsOfBodyA;
		boundsOfBodyA = boundsOfBodyB;
		boundsOfBodyB = temp;
		if((boundsOfBodyB.left > boundsOfBodyA.left) && ((boundsOfBodyB.width + boundsOfBodyB.left) < (boundsOfBodyA.width + boundsOfBodyA.left)) && (boundsOfBodyB.top > boundsOfBodyA.top) && ((boundsOfBodyB.height + boundsOfBodyB.top) < (boundsOfBodyA.height + boundsOfBodyA.top))) {
			return true; //Body B is inside body A
		}
	}
	return false;
}

bool isMouseIntercept(sf::FloatRect boundsOfBody, const sf::RenderWindow* window) {
	if((sf::Mouse::getPosition(*window).x > boundsOfBody.left) && (sf::Mouse::getPosition(*window).x < (boundsOfBody.width + boundsOfBody.left)) && (sf::Mouse::getPosition(*window).y > boundsOfBody.top) && (sf::Mouse::getPosition(*window).y < (boundsOfBody.height + boundsOfBody.top))) {
		return true; //Mouse is inside body.
	}
	return false;
}
