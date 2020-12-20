#pragma once

#include "FriendFunctions.h"
#include <iostream>
#include <ctime>

using namespace std;

class Product
{
public:
	Product(const char* name,													//	constructor
		const double price = static_cast<double>(defaultNumber),				//
		const char* group = undefined,											//
		const char* type = undefined,											//
		const char* individualAbility = undefined,								//
		const char* country = undefined,										//
		const int barCode = defaultNumber);										//

	Product();																	//	default constructor

	Product(const Product& product);											//	copy constructor
	Product& operator=(const Product& product);									//	operator = overload

	~Product();																	//	destructor

	char* getName();															//	product information getters
	double getPrice();															//	
	char* getGroup();															//	
	char* getIndividualAbility();												//	
	char* getType();															//
	char* getCountry();															//
	int getBarCode();															//

	void setName(const char* newName);											//	product information setters
	void setPrice(const double newPrice);										//	
	void setGroup(const char* newGroup);										//	
	void setType(const char* newType);											//
	void setIndividualAbility(const char* newIndividualAbility);				//
	void setCountry(const char* newCountry);									//
	void setBarCode(const int newBarCode);										//

	bool write(ostream& os);													//	write this(Product) to file
	bool read(istream& is);														//	read from file to this(Product)

private:
	char* name;																	//	name
	double price;																//	price
	char* group;																//	group
	char* type;																	//	type
	char* individualAbility;													//	individual ability
	char* country;																//	country
	int barCode;																//	bar code
};