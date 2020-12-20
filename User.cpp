#include "User.h"

User::User()		//default constructor
{
	receipt = new Receipt(identifier);
	this->name = nullptr;
	this->surname = nullptr;
	this->setLogin(nullptr);
	this->setHashPassword(nullptr);
	this->salt = nullptr;
}

User::User(const char* login)		//constructor
{
	try
	{
		srand(time(NULL));
		receipt = new Receipt(identifier);
		ifstream in(usersFile);
		User temp;
		if (in.is_open())
		{
			while (!in.eof())
			{
				temp.read(in);
				if (temp.identifier == defaultNumber)
				{
					temp.identifier = 0;
					for (int i = 0; i < 8; i++)
					{
						temp.identifier += static_cast<int>(pow(10, i)) * (rand() % 10);
					}
				}
				if (equal(temp.getLogin(), login))
				{
					this->setLogin(temp.getLogin());
					this->setHashPassword(temp.getHashPassword());
					this->setName(temp.getName());
					this->setSurname(temp.getSurname());
					this->age = temp.age;
					copyString(temp.salt, this->salt);
					this->role = temp.role;
					this->identifier = temp.identifier;
				}
				users.push_back(temp);
			}
			in.close();
		}
		else
		{
			throw exception("file did not open");
		}
		in.open(productsFile);
		Product product;
		if (in.is_open())
		{
			while (!in.eof())
			{
				product.read(in);
				products.push_back(product);
			}
			in.close();
		}
		else
		{
			throw exception("file did not open");
		}
		in.open(receiptsFile);
		Receipt tempReceipt;
		if (in.is_open())
		{
			bool find = false;
			while (!in.eof())
			{
				tempReceipt.read(in);
				find = false;
				for (List<User>::Iterator it = users.begin(); it != users.end() && find == false; ++it)
				{
					if (tempReceipt.identificator == (*it).identifier)
					{
						(*it).receipts.push_back(tempReceipt);
						find = true;
					}
				}
			}
			find = false;
			for (List<User>::Iterator it = users.begin(); it != users.end() && find == false; ++it)
			{
				if (equal((*it).getLogin(), this->getLogin()))
				{
					this->receipts = (*it).receipts;
					find = true;
				}
			}
			in.close();
		}
		else
		{
			throw exception("file did not open");
		}
	}
	catch (exception& ex)
	{
		ex.~exception();
	}
}

User::User(User& user)		//copy constructor
{
	this->setLogin(user.getLogin());
	this->setHashPassword(user.getHashPassword());
	copyString(user.salt, this->salt);
	this->role = user.role;
	copyString(user.name, this->name);
	copyString(user.surname, this->surname);
	this->identifier = user.identifier;
	this->age = user.age;
	this->receipts = user.receipts;
	this->users = user.users;
	this->products = user.products;
	this->receipt = new Receipt(identifier);
	*this->receipt = *user.receipt;
}

User& User::operator=(User& user)		//operator = overload
{
	this->setLogin(user.getLogin());
	this->setHashPassword(user.getHashPassword());
	copyString(user.salt, this->salt);
	this->role = user.role;
	copyString(user.name, this->name);
	copyString(user.surname, this->surname);
	this->identifier = user.identifier;
	this->age = user.age;
	this->receipts = user.receipts;
	this->users = user.users;
	this->products = user.products;
	if (this->receipt != nullptr)
	{
		delete this->receipt;
	}
	this->receipt = new Receipt(identifier);
	*this->receipt = *user.receipt;
	return *this;
}

User::~User()		//destructor
{
	delete receipt;
	receipts.clear();
	users.clear();
	products.clear();
	delete[]this->surname;
	delete[]this->name;
}

ostream& User::showProducts(ostream& os)		//show products to os
{
	for (int i = 0; i < products.getSize(); i++)
	{
		showProduct(products[i], os);
	}
	return os;
}

void User::sortProductsByName()		//sort product by name
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (compareString(products[i].getName(), products[j].getName()) < 0)
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

void User::sortProductsByCountry()		//sort product by country
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (compareString(products[i].getCountry(), products[j].getCountry()) < 0)
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

void User::sortProductsByPrice()		//sort product by price
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (products[i].getPrice() > products[j].getPrice())
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

void User::sortProductsByGroup()		//sort product by group
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (compareString(products[i].getGroup(), products[j].getGroup()) < 0)
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

void User::sortProductsByType()		//sort product by type
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (compareString(products[i].getType(), products[j].getType()) < 0)
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

void User::sortProductsByBarCode()		//sort product by barcode
{
	for (int i = 0; i < products.getSize() - 1; i++)
	{
		for (int j = i + 1; j < products.getSize(); j++)
		{
			if (products[i].getBarCode() > products[j].getBarCode())
			{
				swapElements(products[i], products[j]);
			}
		}
	}
}

Product& User::findProduct(const char* name)		//find product
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			return products[i];
		}
	}
}

char* User::getName()		//name getter
{
	return this->name;
}

char* User::getSurname()		//surname getter
{
	return this->surname;
}

int User::getAge()		//age getter
{
	return this->age;
}

User& User::getFullUserInformation()		//user(this) getter
{
	return *this;
}

int User::getIdentifier()		//identifier getter
{
	return this->identifier;
}

void User::setName(const char* newName)		//name setter
{
	copyString(newName, this->name);
}

void User::setSurname(const char* newSurname)		//surname setter
{
	copyString(newSurname, this->surname);
}

void User::setAge(const int newAge)		//age setter
{
	this->age = newAge;
}

void User::showReceipts(ostream& os)		//show receipts to os
{
	for (List<Receipt>::Iterator it = receipts.begin(); it != receipts.end(); ++it)
	{
		(*it).showReceipt(os);
	}
}

bool User::makeReceipt()		//make receipt
{
	if (receipt->products.getSize() <= 0)
	{
		return false;
	}
	receipt->setDate();
	receipts.push_back(*receipt);
	bool isFind = false;
	for (List<User>::Iterator it = users.begin(); it != users.end() && isFind == false; ++it)
	{
		if (equal((*it).getLogin(), this->getLogin()))
		{
			(*it).receipts = this->receipts;
		}
	}
	delete receipt;
	receipt = new Receipt();
	return true;
}

bool User::buyProduct(const char* name)		//buy product and send to receipt
{
	bool buy = false;
	for (int i = 0; i < products.getSize() && buy == false; i++)
	{
		if (equal(name, products[i].getName()))
		{
			receipt->pushProduct(products[i]);
			buy = true;
		}
	}
	return buy;
}

bool User::deleteBuyingProduct(const char* name)		//delete product from receipt
{
	bool deleteBuying = false;
	for (int i = 0; i < products.getSize() && deleteBuying == false; i++)
	{
		if (equal(name, products[i].getName()))
		{
			receipt->popProduct(name);
			deleteBuying = true;
		}
	}
	return deleteBuying;
}

bool User::saveReceiptInformation()			//save receipt information
{	
	if (!this->areUsersWithId())
	{
		this->saveUsersInformation();
	}
	ofstream out;
	out.open(receiptsFile);
	if (out.is_open())
	{
		for (List<User>::Iterator usIt = users.begin(); usIt != users.end(); ++usIt)
		{
			for (List<Receipt>::Iterator recIt = (*usIt).receipts.begin(); recIt != (*usIt).receipts.end(); ++recIt)
			{
				(*recIt).makeReceipt((*usIt).getIdentifier());
			}
		}
		out.close();
		return !out.fail();
	}
	else
	{
		throw exception("file did not open");
	}
}

bool User::saveUsersInformation()		//save user information
{
	ofstream out;
	out.open(usersFile);
	if (out.is_open())
	{
		for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
		{
			if (equal((*it).getLogin(), this->getLogin()))
			{
				this->write(out);
			}
			else
			{
				(*it).write(out);
			}
		}
		out.close();
		return !out.fail();
	}
	else
	{
		throw exception("file did not open");
	}
}

Vector<Product> User::getProductsVector()		//products getter
{
	return products;
}

List<Receipt> User::getReceiptsList()		//receipts getter
{
	return receipts;
}

Receipt* User::getReceiptPointer()		//receipt getter
{
	return receipt;
}

List<User> User::getUsersList()		//users getter
{
	return users;
}

bool User::write(ostream& os)		//write user to file
{
	os.seekp(0, ios::end);
	if (os.tellp() != 0)
	{
		os << endl;
	}
	os << convertSpaceToUnderline(this->getLogin())
		<< " " << this->identifier
		<< " " << this->role
		<< " " << convertSpaceToUnderline(this->getHashPassword())
		<< " " << convertSpaceToUnderline(this->getSalt())
		<< " " << convertSpaceToUnderline(this->name)
		<< " " << convertSpaceToUnderline(this->surname)
		<< " " << this->age;
	return !os.fail();
}

bool User::read(istream& is)		//read user from file
{
	string fileLogin, fileSalt, fileHashPassword, fileName, fileSurname;
	is >> fileLogin >> this->identifier >> this->role >> fileHashPassword
		>> fileSalt >> fileName >> fileSurname >> this->age;
	setLogin(fileLogin.c_str());
	setHashPassword(fileHashPassword.c_str());
	copyString(fileSalt.c_str(), this->salt);
	setLogin(convertUnderlineToSpace(this->getLogin()));
	setHashPassword(convertUnderlineToSpace(this->getHashPassword()));
	this->salt = convertUnderlineToSpace(this->salt);
	copyString(fileName.c_str(), this->name);
	copyString(fileSurname.c_str(), this->surname);
	this->name = convertUnderlineToSpace(this->name);
	this->surname = convertUnderlineToSpace(this->surname);
	return !is.fail();
}

void User::showProduct(Product& product, ostream& os)		//show one product to os
{
	os << "Name: " << product.getName() << endl
		<< "Price: " << product.getPrice() << endl
		<< "Country: " << product.getCountry() << endl
		<< "Group: " << product.getGroup() << endl
		<< "Individual ability: " << product.getIndividualAbility() << endl
		<< "BarCode: " << product.getBarCode() << endl << endl;
}

bool User::areUsersWithId()		//checks if users get id in file
{
	ifstream in;
	in.open(usersFile);
	string temp;
	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> temp;
			in >> temp;
			if (temp == "-1")
			{
				return false;
			}
			getline(in, temp);
		}
	}
	return true;
}