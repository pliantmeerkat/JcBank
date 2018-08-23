/*
 * BankAccount.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "bankAccount.h"

BankAccount::BankAccount(std::string holderName, float balance)
{
	this->balance = balance; // will later point to db
	this->holderName = holderName;
	this->accountId = 111111; // will later use a database for this
	// account transactions etc..
	// creation date?
}




