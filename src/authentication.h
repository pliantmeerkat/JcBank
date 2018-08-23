/*
 * authentication.h
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#ifndef AUTHENTICATION_H_
#define AUTHENTICATION_H_

#include <string>
#include "bankAccount.h"

template <typename DatabaseProcessor>

class Authentication
{
public:
	static bool validAccount(int accountId)
	{
		try {
			databaseProcessor.getAccount(accountId);
		} catch(std::invalid_argument * e) {
			return false;
		}
		return true;
	}
	static bool validAmount(float paymentAmount)
	{
		if(paymentAmount > 99999)
		{
			return false;
		}
		return true;
	}
	static bool payerHasFunds(int accountId, float paymentAmount)
	{
		try {
			BankAccount * account = databaseProcessor.getAccount(accountId);
			if(account->balance - paymentAmount < -500)
			{
				return false;
			}

		} catch(std::invalid_argument * e) {
			throw e; // shouldn't happen
		}
		return true;
	}

	static DatabaseProcessor databaseProcessor;

};



#endif /* AUTHENTICATION_H_ */
