/*
 * authenticationTest.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */


#include "authentication.h"
#include "gtest/gtest.h"
#include "bankAccount.h"

namespace AuthenticationTesting
{
	class mockDatabaseProcessor
	{
	public:
		static BankAccount * getAccount(int accountId)
		{
			if(accountId == 0)
			{
				return new BankAccount("Test User", 500.00); // returns a valid account
			}
			else if(accountId == 1)
			{
				throw new std::invalid_argument("Account doesn't exist");
			}
			else
			{
				return new BankAccount("Poor User", 0.00);
			}
		}
		// get account
		// get transaction
	};

	struct AuthenticationTest: public ::testing::Test
	{
	protected:
		Authentication<mockDatabaseProcessor> * authentication;
		AuthenticationTest()
		{

		}
		virtual ~AuthenticationTest() override
		{

		}
		virtual void SetUp() override
		{

		}
		virtual void TearDown() override
		{

		}

	};

	// passing tests

	TEST_F(AuthenticationTest, validAccount)
	{
		ASSERT_TRUE(authentication->validAccount(0));
	}

	TEST_F(AuthenticationTest, validAmount)
	{
		ASSERT_TRUE(authentication->validAmount(100.00));
	}

	TEST_F(AuthenticationTest, payerHasFunds)
	{
		ASSERT_TRUE(authentication->payerHasFunds(0, 100));
	}

	// failing tests

	TEST_F(AuthenticationTest, validAccountFail)
	{
		ASSERT_FALSE(authentication->validAccount(1));
	}

	TEST_F(AuthenticationTest, validAmountFail)
	{
		ASSERT_FALSE(authentication->validAmount((100000.00)));
	}

	TEST_F(AuthenticationTest, payerHasFundsFail)
	{
		ASSERT_FALSE(authentication->payerHasFunds(2, 1000.00));
	}


}


