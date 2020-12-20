#pragma once
#include "D:\Влад БГУИР\КПрог Лабораторные работы\List\List.h"
#include "Product.h"
#include "Date.h"
#include "User.h"


class Receipt : public Date
{
public:
	Receipt(int identificator = defaultNumber,						//	constructor
		int year = defaultNumber,									//
		int month = defaultNumber,									//
		int day = defaultNumber,									//
		int hour = defaultNumber,									//
		int minute = defaultNumber,									//
		int second = defaultNumber);								//

	Receipt(const Receipt& receipt);								//	copy constructor
	Receipt& operator=(const Receipt& receipt);						//	operator = overload

	~Receipt();														//	destructor

	ostream& showReceipt(ostream& os);								//	methods for using receipt

																	//	sort products by:
	void sortByName();												//	name,
	void sortByCountry();											//	country,
	void sortByPrice();												//	price,
	void sortByGroup();												//	group,
	void sortByType();												//	type,
	void sortByBarCode();											//	barcode.

	Product& findProduct(const char* findName);						//	find product in list products

	void pushProduct(const Product& product);						//	add product to products list
	void popProduct(const char* productName);						//	remove products from products list

	double getSummaryPrice();										//	working with price
	int getNumberOfProducts();										//	product number getter
	List<Product> getProductsList();								//	products list getter

	friend class User;												//	making User class frindly for making Receipts method acceptable
private:
	List<Product> products;											//	product list for a filling the receipt
	double summaryPrice;											//	summary price
	int identificator;												//	identificator
	int numberOfProducts;											//	numberOfProducts

	bool read(istream& is);											//	read from file to this(Receipt)
	bool write(ostream& os);										//	write to this(Receipt) from file
	bool makeReceipt(int identificator);							//	make Receipt
};