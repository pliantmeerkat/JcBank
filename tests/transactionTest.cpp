/*
 * transactionTest.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "transaction.h"
#include "gtest/gtest.h"


namespace {

	struct TransactionTest: public ::testing::Test
	{
	protected:
		Transaction * testTransaction;
		TransactionTest()
		{

		}
		virtual ~TransactionTest() override
		{

		}
		virtual void SetUp() override
		{
			int paymentId = 1;
			int payeeId = 1;
			int payerId = 2;
			testTransaction = new Transaction(paymentId, payeeId, payerId,
											  "11/11/11 24:00", 150.00, "A test payment");
		}
		virtual void TearDown() override
		{
			delete testTransaction;
		}
	};

	// instance variable tests

	TEST_F(TransactionTest, transactionId)
	{
		ASSERT_EQ(testTransaction->paymentId, 1);
	}

	TEST_F(TransactionTest, payeeId)
	{
		ASSERT_EQ(testTransaction->payeeId, 1);
	}

	TEST_F(TransactionTest, payerId)
	{
		ASSERT_EQ(testTransaction->payerId, 2);
	}

	TEST_F(TransactionTest, transactionDate)
	{
		ASSERT_EQ(testTransaction->transactionDate, "11/11/11 24:00");
	}

	TEST_F(TransactionTest, paymentAmount)
	{
		ASSERT_EQ(testTransaction->paymentAmount, 150.00);
	}

	TEST_F(TransactionTest, paymentNotes)
	{
		ASSERT_EQ(testTransaction->paymentNotes, "A test payment");
	}
	// bad data tests

	TEST_F(TransactionTest, transactionStringId)
	{

	}
}
