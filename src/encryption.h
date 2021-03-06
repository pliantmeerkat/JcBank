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
#include "infint.h"


class Encryption
{
public:
	// varaibles
	static const int MAXIMUM_INT_SIZE = 40; // maximum size of keys etc
	static const int MINIMUM_INT_SIZE = 30; // minimum size for keys etc
	static int rKey; // modulus
	static int pKey; // public key
	static int qKey; // private key

	static bool isNumberPrime(int number);
	static bool isRelativePrime(unsigned int num, unsigned int numCompare);

	//key generation
	static int generatePrimeInt();
	static void generateEncryptionKeys();

	// main methods

	static std::string encryptData(std::string data);
	static std::string decryptData(std::string encryptedData, int key);

private:
	static void generatePKey(int totient);
	static void generateQKey(int totient);
};



#endif /* ENCRYPTION_H_ */
