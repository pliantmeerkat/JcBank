/*
 * encryptionTest.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#include "gtest/gtest.h"
#include "encryption.h"

namespace EncryptionTesting
{
	class EncryptionTest: public ::testing::Test
	{
	protected:
		Encryption * encrypt;

		virtual void SetUp()
		{

		}
	};

	TEST_F(EncryptionTest, generatePrimeInt)
	{
		int randInt =encrypt->generatePrimeInt();
		ASSERT_TRUE(encrypt->isNumberPrime(randInt));
	}

	TEST_F(EncryptionTest, generateEncryptionKeys)
	{
		encrypt->generateEncryptionKeys();
		int rKey = encrypt->rKey;
	}

	TEST_F(EncryptionTest, encryptData)
	{
		ASSERT_NE(encrypt->encryptData("Hello World"), "Hello World");
	}

	TEST_F(EncryptionTest, decryptData)
	{

	}

}

