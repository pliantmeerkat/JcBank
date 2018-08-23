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

	TEST_F(EncryptionTest, isNumberPrime)
	{
		ASSERT_TRUE(encrypt->isNumberPrime(7));
		ASSERT_FALSE(encrypt->isNumberPrime(10));
	}

	TEST_F(EncryptionTest, isRelativePrime)
	{
		ASSERT_TRUE(encrypt->isRelativePrime(12, 13));
		ASSERT_FALSE(encrypt->isRelativePrime(12, 20));
	}

	TEST_F(EncryptionTest, generatePrimeInt)
	{
		int randInt =encrypt->generatePrimeInt();
		ASSERT_TRUE(encrypt->isNumberPrime(randInt));
	}

	TEST_F(EncryptionTest, generateEncryptionKeys)
	{
		encrypt->generateEncryptionKeys();
		ASSERT_FALSE(encrypt->isNumberPrime(encrypt->rKey));
		ASSERT_TRUE(encrypt->isRelativePrime(encrypt->pKey, encrypt->rKey));
		ASSERT_TRUE(encrypt->isRelativePrime(encrypt->qKey, encrypt->rKey));
		ASSERT_TRUE(encrypt->isRelativePrime(encrypt->pKey, encrypt->qKey));
	}

	TEST_F(EncryptionTest, encryptData)
	{
		ASSERT_NE(encrypt->encryptData("Hello World"), "Hello World");
	}

	TEST_F(EncryptionTest, decryptData)
	{

	}

}

