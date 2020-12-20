#pragma once

#include "D:\Влад БГУИР\КПрог Лабораторные работы\List\List.h"
#include "D:\Влад БГУИР\КПрог Лабораторные работы\Vector\Vector.h"
#include "Product.h"
#include "Receipt.h"
#include "Authorization.h"

class Receipt;

class User : public Authorization
{
public:
	User();														//	default constructor
	User(const char* login);									//	constructor

	User(User& user);											//	copy constructor
	User& operator=(User& user);								//	operator = overload

	~User();													//	destructor

	ostream& showProducts(ostream& os);							//	show products to os

																//	sort products by:
	void sortProductsByName();									//	name,
	void sortProductsByCountry();								//	country,
	void sortProductsByPrice();									//	price,
	void sortProductsByGroup();									//	group,
	void sortProductsByType();									//	type,
	void sortProductsByBarCode();								//	barcode.

	Product& findProduct(const char* name);						//	find product in products vector

	char* getName();											//	user information getters
	char* getSurname();											//	
	int getAge();												//	
	User& getFullUserInformation();								//
	int getIdentifier();										//

	void setName(const char* newName);							//	user information setters
	void setSurname(const char* newSurname);					//	
	void setAge(const int newAge);								//	

	void showReceipts(ostream& os);								//	show receipts to os
	bool makeReceipt();											//	make receipt from (Receipt* receipt)

	bool buyProduct(const char* name);							//	add product to receipt
	bool deleteBuyingProduct(const char* name);					//	remove product from receipt

	bool saveReceiptInformation();								//	save receipt information to file
	bool saveUsersInformation();								//	save user information to file

	Vector<Product> getProductsVector();						//	products vector getter
	List<Receipt> getReceiptsList();							//	receipts list getter
	Receipt* getReceiptPointer();								//	receipt pointer getter
	List<User> getUsersList();									//	users list getter

	friend class Creator;										//	make class Creator friendle for giving access for role

protected:
	Vector<Product> products;									//	products vector
	List<Receipt> receipts;										//	receipts list
	Receipt* receipt;											//	receipt pointer
	List<User> users;											//	users list
	bool write(ostream& os);									//	write this(User) to file
	bool read(istream& is);										//	read from file to this(User)

private:
	int identifier;												//	user id
	int age;													//	user age
	char* name;													//	user name
	char* surname;												//	user surname

	void showProduct(Product& product, ostream& os);			//	method that outputs information about a single product
	bool areUsersWithId();										//	are all identificators in users file
};