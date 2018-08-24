/*
 * encryption.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#include "encryption.h"
#include <math.h>
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

void Encryption::generatePKey(int totient)
{
	// key must be > 1 and coprime to totient
	for(int i = 10; i < rKey; i ++)
	{
		if(Encryption::isRelativePrime(i, totient))
		{
			pKey = i;
			break;
		}
	}
}

void Encryption::generateQKey(int totient)
{
	// qK * pK = 1 + k(totient)
	qKey = 0;
	int k = 1;
	qKey = (1 + (k *totient)) / pKey;

}

void Encryption::generateEncryptionKeys()
{
	int u = Encryption::generatePrimeInt();
	int v = Encryption::generatePrimeInt();
	rKey = u * v;
	int totient = (u-1)*(v-1);

	Encryption::generatePKey(totient);
	std::cout<<pKey<<std::endl;
	Encryption::generateQKey(totient);
	std::cout<<qKey<<std::endl;
}

int * Encryption::encryptData(std::string data)
{

	Encryption::generateEncryptionKeys();
	int * encryptedData = new int[data.length()];
	long n;
	int count = 0;
	// calculated by equation c = message^e % n
	for(char &c : data)
	{
		n = int(c);
		for(int i = 1; i < pKey; i ++)
		{
			n *= i;
			n %= rKey;
		}
		encryptedData[0] =n;
		count += 1;
	}
	//std::cout<<encryptedData<<std::endl;
	return encryptedData;
}

std::string Encryption::decryptData(int * data, int key)
{
	std::string decryptData = "";
	long n;
	for(int c : data)
	{
		n = int(c);
		for(int i = 1; i < qKey; i ++)
		{
			n *= qKey;
			n %= rKey;
		}
		decryptData += char(n);
	}

	return decryptData;
}
