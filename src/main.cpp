/*
 * main.cpp
 *
 *  Created on: 20 Aug 2018
 *      Author: jackbranch
 */

#include "gtest/gtest.h"
#include<time.h>
#include "stadfx.h"


int main(int ac, char* argv[])
{

	srand(time(NULL));

	::testing::InitGoogleTest(&ac, argv);
	return RUN_ALL_TESTS();
}


