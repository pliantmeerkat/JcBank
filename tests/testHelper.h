/*
 * testHelper.h
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#ifndef TESTHELPER_H_
#define TESTHELPER_H_

#include <string>

std::string errorToString(std::invalid_argument * e)
	{
		std::stringstream ss;
		ss << e->what();
		return ss.str();
	}


#endif /* TESTHELPER_H_ */
