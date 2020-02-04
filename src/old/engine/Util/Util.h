/*
 * Util.h
 *
 *  Created on: 02-Oct-2019
 *      Author: pluto
 */

#ifndef MISC_UTIL_H_
#define MISC_UTIL_H_

#include <SFML/Graphics.hpp>
#include <iostream>

bool isIntercept(sf::FloatRect boundsOfBodyA, sf::FloatRect boundsOfBodyB);
bool isMouseIntercept(sf::FloatRect boundsOfBody, const sf::RenderWindow* window);

#endif /* MISC_UTIL_H_ */
