# JcBank

## Overview

Jc Bank is an attempt at modeling banking procedures, such as transactions, acounts, database queries and data security. it is not indended to be accurate, simply to relipcate the primary user interactions within a computer program. 

## Installation

To install this library microsofts c++ library must be installed on your machine, in addition a c++ compiler.

## Testing

This program utilises the [Google Test](https://github.com/google/googletest) library, and already includes the nescesarry neader files in the `external/gtest` directory. to run the tests simply build and run the program, and you should have an output like ths:

```
	[ RUN      ] AuthenticationTest.validAccount
	[       OK ] AuthenticationTest.validAccount (0 ms)
	[ RUN      ] AuthenticationTest.validAmount
	[       OK ] AuthenticationTest.validAmount (0 ms)
	[ RUN      ] AuthenticationTest.payerHasFunds
	[       OK ] AuthenticationTest.payerHasFunds (0 ms)
	[ RUN      ] AuthenticationTest.validAccountFail
	[       OK ] AuthenticationTest.validAccountFail (0 ms)
	[ RUN      ] AuthenticationTest.validAmountFail
	[       OK ] AuthenticationTest.validAmountFail (0 ms)
	[ RUN      ] AuthenticationTest.payerHasFundsFail
	[       OK ] AuthenticationTest.payerHasFundsFail (0 ms)
	[----------] 6 tests from AuthenticationTest (0 ms total)
```

## Progam Features

Within this library i have attempted to create the following features:
	
* Account simulation: Users can create an account, capable of storing the user's balance, processing 	transactions and recording any transactions that occur.
* Transaction simulation: All payments are represented by transactions objects, allowing for detailed recoring of all processed transactions and their relevent infomation
* Client authentication: simulation of account creation, amount validation and funds verifications during transactions.
* Database implementatation: all records are stored in a *postgres* database, allowing for easy data retrieval and storage.
* Data security: all stored data is encrypted using a simple implementation of the [RSA Algorithm](https://simple.wikipedia.org/wiki/RSA_algorithm).
	
## Contributing 

This is a still a major wip, so any feedback or contributions are welcome, simply message me/ make a pull request if you wish to contribute.

## Credits

 	- [Brian Raiter's article](http://www.muppetlabs.com/~breadbox/txt/rsa.html) for help writing the encryption class.
