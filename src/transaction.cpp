/*
 * transaction.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#include "transaction.h"

Transaction::Transaction(int paymentId, int payeeId, int payerId,
						 std::string date, float amount, std::string notes)
{
	this->paymentId = paymentId;
	this->payeeId = payeeId;
	this->payerId = payerId;
	this->transactionDate = date;
	this->paymentAmount = amount;
	this->paymentNotes = notes;
}

