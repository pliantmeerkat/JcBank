/*
 * encryption.h
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_

#include "stadfx.h"
#include <random>

class Encryption
{
public:
	// varaibles
	static const int MAXIMUM_INT_SIZE = 1000000; // maximum size of keys etc
	static const int MINIMUM_INT_SIZE = 10000; // minimum size for keys etc
	const int rKey;

	static bool isNumberPrime(int number);

	//key generation
	static int generatePrimeInt();
	static void generateEncryptionKeys();

	// main methods

	static std::string encryptData(std::string data);
	static std::string decryptData(std::string encryptedData);

};



#endif /* ENCRYPTION_H_ */
