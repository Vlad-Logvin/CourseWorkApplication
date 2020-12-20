#include "Admin.h"


bool Admin::deleteProduct(const char* name)				//delete Product from products
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(products[i].getName(), name))
		{
			products.emplace(i);
			return true;
		}
	}
	return false;
}

bool Admin::addProduct(Product& product)				//add Product to products
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(product.getName(), products[i].getName()))
		{
			return false;
		}
	}
	products.push_back(product);
	return true;
}

bool Admin::editProductCountry(const char* name, const char* newCountry)		//edit product country
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setCountry(newCountry);
			return true;
		}
	}
	return false;
}

bool Admin::editProductPrice(const char* name, double newPrice)		//edit product price
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setPrice(newPrice);
			return true;
		}
	}
	return false;
}

bool Admin::editProductType(const char* name, const char* newType)		//edit product type
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setType(newType);
			return true;
		}
	}
	return false;
}

bool Admin::editProductIndividualAbility(const char* name, const char* newIndividualAbility)		//edit product individual ability
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setIndividualAbility(newIndividualAbility);
			return true;
		}
	}
	return false;
}

bool Admin::editProductGroup(const char* name, const char* newGroup)		//edit product group
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setGroup(newGroup);
			return true;
		}
	}
	return false;
}

bool Admin::editProductBarCode(const char* name, int newBarCode)		//edit product barcode
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setBarCode(newBarCode);
			return true;
		}
	}
	return false;
}

bool Admin::editProductName(const char* name, const char* newName)		//edit product name
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(newName, products[i].getName()))
		{
			return false;
		}
	}
	for (int i = 0; i < products.getSize(); i++)
	{
		if (equal(name, products[i].getName()))
		{
			products[i].setName(newName);
			return true;
		}
	}
	return false;
}

bool Admin::addAccount(User& user)		//add User to users
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal((*it).getLogin(), user.getLogin()))
		{
			return false;
		}
	}
	users.push_back(user);
	return true;
}

bool Admin::deleteAccount(const char* login)		//delete User from users
{
	int counter = 0;
	for (List<User>::Iterator it = users.begin(); it != users.end(); counter++, ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			if ((*it).getRole() > this->role)
			{
				return false;
			}
			users.removeAt(counter);
			return true;
		}
	}
	return false;
}

bool Admin::editUserLogin(const char* login, const char* newLogin)		//edit User login
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(newLogin, (*it).getLogin()))
		{
			return false;
		}
	}
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			(*it).setLogin(newLogin);
			return true;
		}
	}
	return false;
}

bool Admin::editUserPassword(const char* login, const char* newPassword)		//edit user password
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			(*it).setPassword(newPassword);
			return true;
		}
	}
	return false;
}

bool Admin::editUserName(const char* login, const char* newName)		//edit user name
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			(*it).setName(newName);
			return true;
		}
	}
	return false;
}

bool Admin::editUserSurname(const char* login, const char* newSurname)		//edit user surname
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			(*it).setSurname(newSurname);
			return true;
		}
	}
	return false;
}

bool Admin::editUserAge(const char* login, const int newAge)		//edit user age
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			(*it).setAge(newAge);
			return true;
		}
	}
	return false;
}

void Admin::sortUsersByLogin()		//sort users by login
{
	int i = 0;
	for (List<User>::Iterator it1 = users.begin(); i < users.getSize() - 1; i++, ++it1)
	{
		for (List<User>::Iterator it2 = it1 + 1; it2 != users.end(); ++it2)
		{
			if (compareString((*it1).getLogin(), (*it2).getLogin()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Admin::sortUsersByName()		//sort users by name
{
	int i = 0;
	for (List<User>::Iterator it1 = users.begin(); i < users.getSize() - 1; i++, ++it1)
	{
		for (List<User>::Iterator it2 = it1 + 1; it2 != users.end(); ++it2)
		{
			if (compareString((*it1).getName(), (*it2).getName()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Admin::sortUsersBySurname()		//sort users by surname
{
	int i = 0;
	for (List<User>::Iterator it1 = users.begin(); i < users.getSize() - 1; i++, ++it1)
	{
		for (List<User>::Iterator it2 = it1 + 1; it2 != users.end(); ++it2)
		{
			if (compareString((*it1).getSurname(), (*it2).getSurname()) < 0)
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

void Admin::sortUsersByAge()		//sort users by age
{
	int i = 0;
	for (List<User>::Iterator it1 = users.begin(); i < users.getSize() - 1; i++, ++it1)
	{
		for (List<User>::Iterator it2 = it1 + 1; it2 != users.end(); ++it2)
		{
			if ((*it1).getAge() > (*it2).getAge())
			{
				swapElements(*it1, *it2);
			}
		}
	}
}

User& Admin::findUser(const char* login)		//find user in users
{
	for (List<User>::Iterator user = users.begin(); user != users.end(); ++user)
	{
		if (equal(login, (*user).getLogin()))
		{
			return (*user);
		}
	}
}

bool Admin::saveProductsToFile()		//save products to file
{
	ofstream out;
	out.open(productsFile);
	if (out.is_open())
	{
		for (int i = 0; i < products.getSize(); i++)
		{
			products[i].write(out);
		}
		out.close();
		return !out.fail();
	}
	else
	{
		throw exception("file did not open");
	}
}