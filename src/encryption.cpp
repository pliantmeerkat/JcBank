/*
 * encryption.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#include "encryption.h"
#include <iostream>

int Encryption::rKey = 0;
int Encryption::pKey = 0;
int Encryption::qKey = 0;

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

bool Encryption::isRelativePrime(unsigned int num, unsigned int numCompare)
{
	if(num < 0 || numCompare < 0)
	{
		throw new std::invalid_argument("At least one negative integer");
	}

	for(; ;)
	{
		if(!(num %= numCompare)) return numCompare == 1;
		if(!(numCompare %= num)) return num == 1;
	}
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
	return r;

}

void Encryption::generateEncryptionKeys()
{
	int u = Encryption::generatePrimeInt();
	int v = Encryption::generatePrimeInt();
	int phiR = (u-1) *(v-1);

	// generate p key
	for(int i = 0; i < rKey; i ++)
	{
		if(Encryption::isRelativePrime(i, rKey))
		{
			pKey = i;
			break;
		}
		if(pKey == 0 || pKey == rKey)
		{
			throw new std::invalid_argument("pKey is 0 or Rkey");
		}
	}

	// generate r key formula pkey * qKey = i * rkey + 1

	std::cout<<phiR<<std::endl;
	rKey = u * v;
}

std::string Encryption::encryptData(std::string data)
{
	return data;
}

std::string Encryption::decryptData(std::string data)
{

}
