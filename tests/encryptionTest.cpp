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
		std::string inputString;
		int * encryptArray

		virtual void SetUp()
		{
			inputString = "Now, let's switch hats, Imagine that we've just managed to pluck the message ZOBG";
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
		encryptArray = new int[inputString.length()];
		encryptArray = encrypt->encryptData(inputString);
		ASSERT_NE(encryptArray[0], 78);
		//ASSERT_NE(encrypt->encryptData("Now, let's switch hats, Imagine that we've just managed to pluck the message ZOBG"), "Now, let's switch hats, Imagine that we've just managed to pluck the message ZOBG");

	}

	TEST_F(EncryptionTest, decryptData)
	{
		encryptArray = new int[inputString.length()];
		encryptArray = encrypt->encryptData(inputString);
		int qKey = encrypt->qKey;
		ASSERT_EQ(encrypt->decryptData(encryptArray, qKey));
	}

}

