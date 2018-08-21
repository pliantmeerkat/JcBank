/*
 * BankAccount.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include <bankAccount.h>

BankAccount::BankAccount(std::string holderName)
{
	this->balance = 0; // will later point to db
	this->holderName = holderName;
	this->accountId = 111111; // will later use a database for this
}




