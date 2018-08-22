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
	bool desiredResult = false; // defaults to true for failing tests
	void setDesiredResult(bool result)
	{
		desiredResult = result;
	}
	bool validPayeeId(int * payeeId)
	{
		return desiredResult;
	}
	bool validPayerId(int * payerId)
	{
		return desiredResult;
	}
	bool validAmount(int * paymentAmount)
	{
		return desiredResult;
	}
	bool payerHasFunds(int * payerId, int * paymentAmount)
	{
		return desiredResult;
	}
};

struct PaymentProcessorTest: public ::testing::Test
	{
	protected:
		PaymentProcessor<Transaction> * paymentTester;
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

