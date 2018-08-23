/*
 * paymentProcessorTest.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "gtest/gtest.h"
#include "paymentProcessor.h"
#include "transaction.h"


namespace {

// class mocks

class MockAuthentication
{
public:

	// enter zero values for mock fails

	static bool validPayeeId(int payeeId)
	{
		if(payeeId == 0) { return false; }
		return true;
	}
	static bool validPayerId(int payerId)
	{
		if(payerId == 0) { return false; }
		return true;
	}
	static bool validAmount(float paymentAmount)
	{
		if(paymentAmount == 0.00) { return false; }
		return true;
	}
	static bool payerHasFunds(int payerId, int paymentAmount)
	{
		if(payerId == 42) { return false; }
		return true;
	}
};

// test class

struct PaymentProcessorTest: public ::testing::Test
	{
	protected:
		PaymentProcessor<Transaction, MockAuthentication> * paymentTester;
		Transaction * testTransaction;
		PaymentProcessorTest()
		{

		}
		virtual ~PaymentProcessorTest() override
		{

		}
		virtual void SetUp() override
		{
			testTransaction = paymentTester->createTransaction(1, 2, 3, "11/11/11 22:00", 150.00, "Test Transaction");
		}
		virtual void TearDown() override
		{
			//delete paymentTester;
		}
	};

	// succesfull payment

	TEST_F(PaymentProcessorTest, createTransaction)
	{
		// call from injected class authenticate->setDesiredResult(true);
		ASSERT_EQ(testTransaction->paymentId, 1);
		ASSERT_EQ(testTransaction->payeeId, 2);
		ASSERT_EQ(testTransaction->payerId, 3);
		ASSERT_EQ(testTransaction->transactionDate, "11/11/11 22:00");
		ASSERT_EQ(testTransaction->paymentAmount, 150.00);
		ASSERT_EQ(testTransaction->paymentNotes, "Test Transaction");
	}

	std::string errorToString(std::invalid_argument * e)
	{
		std::stringstream ss;
		ss << e->what();
		return ss.str();
	}

	// verification tests
	TEST_F(PaymentProcessorTest, verifyTransactionMockPass)
	{
		try {
			paymentTester->verifyTransaction(testTransaction);

		} catch(std::exception &e) {
			FAIL() << "Should not throw exception";
		}
		paymentTester->verifyTransaction(testTransaction);
	}

	// faliure tets

	// authentication/ verify transaction fails

	TEST_F(PaymentProcessorTest, verifyBadPayeeId)
	{
		try {
			testTransaction = paymentTester->createTransaction(1, 0, 3, "11/11/11 22:00", 150.00, "Test Transaction");
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Payee";
		} catch(std::invalid_argument * e) {


			ASSERT_EQ(errorToString(e), "Bad Payee Id");

		}

	}

	TEST_F(PaymentProcessorTest, verifyBadPayerId)
	{
		try {
			testTransaction = paymentTester->createTransaction(1, 1, 0, "11/11/11 22:00", 150.00, "Test Transaction");
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Payer";
		} catch(std::invalid_argument * e) {
			ASSERT_EQ(errorToString(e), "Bad Payer Id");
		}
	}

	TEST_F(PaymentProcessorTest, verifyBadPaymentAmount)
	{
		try {
			testTransaction = paymentTester->createTransaction(1, 1, 3, "11/11/11 22:00", 0.00, "Test Transaction");
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Amount";
		} catch(std::invalid_argument * e) {
			ASSERT_EQ(errorToString(e), "Invalid Amount");
		}
	}

	TEST_F(PaymentProcessorTest, verifyTooPoorPayer)
	{
		try {
			testTransaction = paymentTester->createTransaction(1, 2, 42, "11/11/11 22:00", 150.00, "Test Transaction");
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Funds";
		} catch(std::invalid_argument * e) {
			ASSERT_EQ(errorToString(e), "Insufficient Funds");
		}
	}

	// create transaction fails

	TEST_F(PaymentProcessorTest, failedCreateTransaction)
	{
		try {
			testTransaction = paymentTester->createTransaction(1, 0, 3, "11/11/11 22:00", 150.00, "Test Transaction");
			FAIL() << "should throw error with invalid args";
		} catch(std::invalid_argument * e) {
			ASSERT_EQ(errorToString(e), "Bad Payee Id");
		}
	}

}

