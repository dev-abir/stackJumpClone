/*
 * Log.h
 *
 * Works as a Logging utility.
 *
 *  Created on: 04-Jan-2020
 *      Author: pluto
 */

#ifndef UTIL_LOG_H_
#define UTIL_LOG_H_

#include <iostream>


//TODO : Add an if condition to check whether verbose, debug or release settings is on or off... Turn logging on and off accordingly.

#define logD(x) std::cout << "###LOG DEBUG###\t" << x << "\n";
#define logV(x) std::cout << "###LOG VERBOSE###\t" << x << "\n";
#define logI(x) std::cout << "###LOG INFO###\t" << x << "\n";

#endif /* UTIL_LOG_H_ */
