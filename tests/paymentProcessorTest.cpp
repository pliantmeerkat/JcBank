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

class MockAuthentication
{
public:

	static bool validPayeeId(int payeeId)
	{
		return true;
	}
	static bool validPayerId(int payerId)
	{
		return true;
	}
	static bool validAmount(int paymentAmount)
	{
		return true;
	}
	static bool payerHasFunds(int payerId, int paymentAmount)
	{
		return true;
	}
};

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
			//paymentTester->authentication.setPayeeValid = true;
			//paymentTester = new PaymentProcessor<Transaction>();
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

	TEST_F(PaymentProcessorTest, verifyBadPayeeId)
	{
		try {
			//paymentTester->authentication.
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Payee";
		} catch(std::exception &e) {
			ASSERT_EQ(std::string(e.what()), "Invalid Payee");
		}

	}

	TEST_F(PaymentProcessorTest, verifyBadPayerId)
	{
		try {
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Payer";
		} catch(std::exception &e) {
			ASSERT_EQ(std::string(e.what()), "Invalid Payer");
		}
	}

	TEST_F(PaymentProcessorTest, verifyBadPaymentAmount)
	{
		try {
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Amount";
		} catch(std::exception &e) {
			ASSERT_EQ(std::string(e.what()), "Invalid Amount");
		}
	}

	TEST_F(PaymentProcessorTest, verifyTooPoorPayer)
	{
		try {
			paymentTester->verifyTransaction(testTransaction);
			FAIL() << "Should Throw Error with invalid Funds";
		} catch(std::exception &e) {
			ASSERT_EQ(std::string(e.what()), "Insufficient Funds");
		}
	}


	TEST_F(PaymentProcessorTest, failedCreateTransaction)
	{

	}

}

