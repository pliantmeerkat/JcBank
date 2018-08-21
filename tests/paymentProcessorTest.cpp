/*
 * paymentProcessorTest.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "gtest/gtest.h"
#include "paymentProcessor.h"

namespace {

	struct PaymentProcessorTest: public ::testing::Test
	{
	protected:
		PaymentProcessor * paymentTester;
		PaymentProcessorTest() { }
		virtual ~PaymentProcessorTest() override
		{

		}
		virtual void SetUp() override
		{
			paymentTester = new PaymentProcessor();
		}
		virtual void TearDown() override
		{
			delete paymentTester;
		}

	};

	// tests
	TEST_F(PaymentProcessorTest, createTransaction)
	{

	}

	TEST_F(PaymentProcessorTest, verifyTransaction)
	{

	}
}

