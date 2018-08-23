/*
 * BankAccount.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include "stadfx.h"

class BankAccount
{
public:
	BankAccount(std::string holderName, float balance);
	float balance;
	int accountId;
	// transaction history
	std::string holderName;
};



#endif /* BANKACCOUNT_H_ */
