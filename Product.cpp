#include "Product.h"

Product::Product(const char* name, double price, const char* group,
	const char* type, const char* individualAbility, const char* country, int barCode)		//constructor
{
	copyString(name, this->name);
	this->price = price;
	copyString(group, this->group);
	copyString(type, this->type);
	copyString(individualAbility, this->individualAbility);
	copyString(country, this->country);
	this->barCode = barCode;
}

Product::Product()		//default constructor
{
	this->name = nullptr;
	this->group = nullptr;
	this->type = nullptr;
	this->individualAbility = nullptr;
	this->country = nullptr;
}


Product::Product(const Product& product)		//copy constructor
{
	copyString(product.name, this->name);
	this->price = product.price;
	copyString(product.group, this->group);
	copyString(product.type, this->type);
	copyString(product.individualAbility, this->individualAbility);
	copyString(product.country, this->country);
	this->barCode = product.barCode;
}

Product& Product::operator=(const Product& product)		//operator = overload
{
	copyString(product.name, this->name);
	this->price = product.price;
	copyString(product.group, this->group);
	copyString(product.type, this->type);
	copyString(product.individualAbility, this->individualAbility);
	copyString(product.country, this->country);
	this->barCode = product.barCode;
	return *this;
}

Product::~Product()			//destructor
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	if (this->group != nullptr)
	{
		delete[]this->group;
	}
	if (this->type != nullptr)
	{
		delete[]this->type;
	}
	if (this->individualAbility != nullptr)
	{
		delete[]this->individualAbility;
	}
	if (this->country != nullptr)
	{
		delete[]this->country;
	}
}

char* Product::getName()		//name getter
{
	return this->name;
}

double Product::getPrice()		//price getter
{
	return this->price;
}

char* Product::getGroup()		//group getter
{
	return this->group;
}

char* Product::getIndividualAbility()		//individual ability getter
{
	return this->individualAbility;
}

char* Product::getType()		//type getter
{
	return this->type;
}

char* Product::getCountry()		//country getter
{
	return this->country;
}

int Product::getBarCode()		//barCode getter
{
	return this->barCode;
}

void Product::setName(const char* newName)		//name setter
{
	copyString(newName, this->name);
}

void Product::setPrice(const double newPrice)		//price setter
{
	this->price = newPrice;
}

void Product::setGroup(const char* newGroup)		//group setter
{
	copyString(newGroup, this->group);
}

void Product::setType(const char* newType)		//type setter
{
	copyString(newType, this->type);
}

void Product::setIndividualAbility(const char* newIndividualAbility)		//individual ability setter
{
	copyString(newIndividualAbility, this->individualAbility);
}

void Product::setCountry(const char* newCountry)		//country setter
{
	copyString(newCountry, this->country);
}

void Product::setBarCode(const int newBarCode)		//barCode setter
{
	this->barCode = newBarCode;
}

bool Product::write(ostream& os)		//write product to file
{
	os.seekp(0, ios::end);
	if (os.tellp() != 0)
	{
		os << endl;
	}
	os << convertSpaceToUnderline(this->name)
		<< " " << this->price
		<< " " << convertSpaceToUnderline(this->group)
		<< " " << convertSpaceToUnderline(this->type)
		<< " " << convertSpaceToUnderline(this->individualAbility)
		<< " " << convertSpaceToUnderline(this->country)
		<< " " << this->barCode;
	return !os.fail();
}

bool Product::read(istream& is)		//read product from file
{
	string fileName, fileGroup, fileType, fileIndividualAbility, fileCountry;
	is >> fileName >> this->price >> fileGroup >> fileType
		>> fileIndividualAbility >> fileCountry >> this->barCode;
	copyString(fileName.c_str(), this->name);
	copyString(fileGroup.c_str(), this->group);
	copyString(fileType.c_str(), this->type);
	copyString(fileIndividualAbility.c_str(), this->individualAbility);
	copyString(fileCountry.c_str(), this->country);
	this->name = convertUnderlineToSpace(this->name);
	this->group = convertUnderlineToSpace(this->group);
	this->type = convertUnderlineToSpace(this->type);
	this->individualAbility = convertUnderlineToSpace(this->individualAbility);
	this->country = convertUnderlineToSpace(this->country);
	return !is.fail();
}