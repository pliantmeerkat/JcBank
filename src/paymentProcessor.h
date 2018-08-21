/*
 * paymentProcessor.h
 *
 *  Created on: 21 Aug 2018
 *      Author: jackbranch
 */

#ifndef PAYMENTPROCESSOR_H_
#define PAYMENTPROCESSOR_H_

#include "stadfx.h"

class PaymentProcessor
{
public:
	PaymentProcessor();
	void createTransaction();
	void verifyTransaction();
};


#endif /* PAYMENTPROCESSOR_H_ */
