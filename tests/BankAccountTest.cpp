/*
 * BankAccountTest.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "bankAccount.h"
#include "gtest/gtest.h"

namespace {

	struct BankAccountTest: public ::testing::Test
	{
		protected:
		BankAccount * account;
		BankAccountTest()
		{
			// seed input?
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

	TEST_F(BankAccountTest, accountId)
	{
		ASSERT_EQ(account->accountId, 111111);
	}

	TEST_F(BankAccountTest, transactionHistory)
	{
		//ASSERT_EQ(account->transactionHistory, []);
	}

	// other methods - with good input

	TEST_F(BankAccountTest, makeDeposit)
	{

	}

	TEST_F(BankAccountTest, makeWithdrawl)
	{

	}

	TEST_F(BankAccountTest, makePayment)
	{

	}
}





