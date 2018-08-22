/*
 * paymentProcessor.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef PAYMENTPROCESSOR_H_
#define PAYMENTPROCESSOR_H_

#include "stadfx.h"


template <typename Transaction, class Authentication>

class PaymentProcessor
{

public:

	static Transaction * createTransaction(int paymentId, int payeeId, int payerId,
								  std::string date, float amount, std::string notes)
	{
		Transaction * transaction = new Transaction(paymentId, payeeId, payerId, date, amount, notes);

		try {
			verifyTransaction(transaction);
		} catch(std::exception &e){
			throw e;
		}

		return transaction;
	}
//todo crreate private
	static void verifyTransaction(Transaction * transaction)
	{
		// will be private later as called by payment proc

	}

private:
	Transaction transaction;
	Authentication authentication;
};


#endif /* PAYMENTPROCESSOR_H_ */
