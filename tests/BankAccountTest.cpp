/*
 * BankAccountTest.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "BankAccountTest.h"

namespace {

	struct BankAccountTest: public ::testing::Test
	{
		protected:
		BankAccount * account;
		BankAccountTest()
		{

		}
		virtual ~BankAccountTest() override
		{

		}
		virtual void SetUp() override
		{
			account = new BankAccount("test client");
		}
		virtual void TearDown() override
		{
			delete account;
		}
	};

	// account instance variables

	TEST_F(BankAccountTest, accountBalanceStartsAtZero)
	{
		ASSERT_EQ(account->balance, 0);
	}

	TEST_F(BankAccountTest, accountHolderIstestClient)
	{
		ASSERT_EQ(account->holderName, "test client");
	}

	// other methods

	TEST_F(BankAccountTest, DepositIncreasesBalance)
	{

	}
}





