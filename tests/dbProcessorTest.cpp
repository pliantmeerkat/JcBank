/*
 * dbProcessorTest.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */


#include "gtest/gtest.h"

#include "bankAccount.h"
#include "dbProcessor.h"

namespace dbProcessorTesting
{
	struct DbProcessorTest: public ::testing::Test
	{
	protected:
		DbProcessor * dbProcessor;
		DbProcessorTest()
		{

		}
		virtual ~DbProcessorTest() override
		{

		}
		virtual void SetUp() override
		{

		}
		virtual void TearDown() override
		{

		}
	};

	TEST_F(DbProcessorTest, createConnection)
	{
		try {
			dbProcessor->createConnection();
		} catch(std::invalid_argument * e) {
			FAIL() << "Should not throw exception";
		}
	}

	TEST_F(DbProcessorTest, throwsErrorWhenBadConnection)
		{
			try {
				dbProcessor->createConnection();
				FAIL() << "Should throw error when no connection";
			} catch(std::invalid_argument * e) {
				//ASSERT_EQ(errorToString(e), "eeee");
			}
		}

}



