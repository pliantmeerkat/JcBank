/*
 * transaction.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "stadfx.h"

struct Transaction
{
public:
	Transaction(int paymentId, int payeeId, int payerId,
				std::string date, float amount, std::string notes);

//protected:
	// header variables
	int paymentId;
	int payeeId;
	int payerId;
	std::string transactionDate;

	// body variables
	float paymentAmount;
	std::string paymentNotes;
};



#endif /* TRANSACTION_H_ */
