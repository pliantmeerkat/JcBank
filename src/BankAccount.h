/*
 * BankAccount.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

class BankAccount
{
public:
	BankAccount(std::string holderName);
	int balance;
	std::string holderName;
};



#endif /* BANKACCOUNT_H_ */
