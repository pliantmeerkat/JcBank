/*
 * paymentProcessor.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef PAYMENTPROCESSOR_H_
#define PAYMENTPROCESSOR_H_

#include "stadfx.h"


template <typename Transaction, class DatabaseProcessor, class Authentication>

class PaymentProcessor
{

public:

	static Transaction * createTransaction(int paymentId, int payeeId, int payerId,
								  std::string date, float amount, std::string notes)
	{
		Transaction * transaction = new Transaction(paymentId, payeeId, payerId, date, amount, notes);

		try {
			verifyTransaction(transaction);
		} catch(std::invalid_argument &e){
			throw e;
		}

		return transaction;
	}
//todo crreate private
	static void verifyTransaction(Transaction * transaction)
	{
		// will be private later as called by payment proc
		if(!authentication.validAccount(transaction->payeeId))
		{
			throw new std::invalid_argument("Bad Payee Id");
		}
		else if(!authentication.validAccount(transaction->payerId))
		{
			throw new std::invalid_argument("Bad Payer Id");
		}
		else if(!authentication.validAmount(transaction->paymentAmount))
		{
			throw new std::invalid_argument("Invalid Amount");
		}
		else if(!authentication.payerHasFunds(transaction->payerId, transaction->paymentAmount))
		{
			throw new std::invalid_argument("Insufficient Funds");
		}
	}

//private:
	Transaction transaction;
	static Authentication authentication;
};


#endif /* PAYMENTPROCESSOR_H_ */


