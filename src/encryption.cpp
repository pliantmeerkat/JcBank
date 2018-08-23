/*
 * encryption.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#include "encryption.h"
#include <iostream>

bool Encryption::isNumberPrime(int number)
	{
		for(int i = 2; i <= number / 2; i++)
		{
			if(number % i == 0)
			{
				return false;
			}
		}
		return true;
	}

int Encryption::generatePrimeInt()
{

	int r =  rand() % (MAXIMUM_INT_SIZE - MINIMUM_INT_SIZE) + MINIMUM_INT_SIZE;
	while(true)
	{
		if(Encryption::isNumberPrime(r))
		{
			break;
		}
		r = r / 2;
	}
	std::cout<<r<<std::endl;
	return r;

}

void Encryption::generateEncryptionKeys()
{
	// generate two prime numbers
}

std::string Encryption::encryptData(std::string data)
{
	return data;
}

std::string Encryption::decryptData(std::string data)
{

}
