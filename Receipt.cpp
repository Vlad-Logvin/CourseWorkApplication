#include "Receipt.h"


Receipt::Receipt(int identificator, int year, int month, int day, int hour, int minute, int second)		//constructor
{
	this->identificator = identificator;
	this->numberOfProducts = 0;
	this->summaryPrice = 0.0;
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

Receipt::Receipt(const Receipt& receipt)		//copy constructor
{
	this->identificator = receipt.identificator;
	this->summaryPrice = receipt.summaryPrice;
	this->numberOfProducts = receipt.numberOfProducts;
	this->year = receipt.year;
	this->month = receipt.month;
	this->day = receipt.day;
	this->hour = receipt.hour;
	this->minute = receipt.minute;
	this->second = receipt.second;
	this->products = receipt.products;
}

Receipt& Receipt::operator=(const Receipt& receipt)		//operator = overload
{
	this->identificator = receipt.identificator;
	this->summaryPrice = receipt.summaryPrice;
	this->numberOfProducts = receipt.numberOfProducts;
	this->year = receipt.year;
	this->month = receipt.month;
	this->day = receipt.day;
	this->hour = receipt.hour;
	this->minute = receipt.minute;
	this->second = receipt.second;
	this->products = receipt.products;
	return *this;
}

Receipt::~Receipt()		//destructor
{
	products.clear();
}

ostream& Receipt::showReceipt(ostream& os)		//show receipts to os
{
	for (Product product : products)
	{
		os << "Name: " << product.getName() << endl
			<< "Price: " << product.getPrice() << endl
			<< "Country: " << product.getCountry() << endl
			<< "Group: " << product.getGroup() << endl
			<< "Individual ability: " << product.getIndividualAbility() << endl
			<< "BarCode: " << product.getBarCode() << endl << endl;
	}
	this->setDate();
	os << this->hour << ":" << this->minute << ":" << this->second << " "
		<< this->day << "." << this->month << "." << this->year << endl << endl;
	return os;
}

bool Receipt::makeReceipt(int identificator)		//make a receipt
{
	if (products.getSize() > 0)
	{
		this->identificator = identificator;
		ofstream out(receiptsFile, ios::app);
		if (out.is_open())
		{
			this->write(out);
			return true;
		}
	}
	return false;
}

void Receipt::sortByName()		//sort products by name
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if (compareString((*it1).getName(), (*it2).getName()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Receipt::sortByCountry()		//sort products by country
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if (compareString((*it1).getCountry(), (*it2).getCountry()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Receipt::sortByPrice()		//sort products by price
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if ((*it1).getPrice() > (*it2).getPrice())
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Receipt::sortByGroup()		//sort products by group
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if (compareString((*it1).getGroup(), (*it2).getGroup()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Receipt::sortByType()		//sort products by type
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if (compareString((*it1).getType(), (*it2).getType()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Receipt::sortByBarCode()		//sort products by barcode
{
	int i = 0;
	for (List<Product>::Iterator it1 = products.begin(); i < products.getSize() - 1; i++, ++it1)
	{
		for (List<Product>::Iterator it2 = it1 + 1; it2 != products.end(); ++it2)
		{
			if ((*it1).getBarCode() > (*it2).getBarCode())
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

Product& Receipt::findProduct(const char* findName)		//find product
{
	for (List<Product>::Iterator it = products.begin(); it != products.end(); ++it)
	{
		if (compareString((*it).getName(), findName) == EQUAL)
		{
			return (*it);
		}
	}
}

void Receipt::pushProduct(const Product& product)		//push product to products
{
	products.push_back(product);
}

void Receipt::popProduct(const char* productName)		//pop product from products
{
	int counter = 0;
	for (List<Product>::Iterator it = products.begin(); it != products.end(); counter++, ++it)
	{
		if (equal((*it).getName(), productName))
		{
			products.removeAt(counter);
			break;
		}
	}
}

double Receipt::getSummaryPrice()		//get summary price
{
	summaryPrice = 0.0;
	for (Product product : products)
	{
		this->summaryPrice += product.getPrice();
	}
	return this->summaryPrice;
}

int Receipt::getNumberOfProducts()		//number of products getter
{
	return numberOfProducts;
}

List<Product> Receipt::getProductsList()		//product list getter
{
	return products;
}

bool Receipt::read(istream& is)		//read receipt from file
{
	int numberOfProducts = 0;
	is >> this->identificator
		>> numberOfProducts
		>> this->summaryPrice
		>> this->year
		>> this->month
		>> this->day
		>> this->hour
		>> this->minute
		>> this->second;
	Product temp;
	products.clear();
	for (int i = 0; i < numberOfProducts; i++)
	{
		bool isRead = temp.read(is);
		if (isRead == true)
		{
			products.push_back(temp);
		}
	}
	return !is.fail();
}

bool Receipt::write(ostream& os)		//write receipt to file
{
	os.seekp(0, ios::end);
	if (os.tellp() != 0)
	{
		os << endl;
	}
	os << this->identificator
		<< " " << this->products.getSize()
		<< " " << this->getSummaryPrice()
		<< " " << this->year
		<< " " << this->month
		<< " " << this->day
		<< " " << this->hour
		<< " " << this->minute
		<< " " << this->second;
	for (List<Product>::Iterator it = products.begin(); it != products.end(); ++it)
	{
		(*it).write(os);
	}
	return !os.fail();
}