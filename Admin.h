#pragma once
#include "User.h"

class Admin : public User
{
public:
	Admin(const char* login) : User(login) {}													//	constructor
	Admin(Admin& admin) : User(admin) {}														//	copy constructor

	bool deleteProduct(const char* name);														//	delete Product from products
	bool addProduct(Product& product);															//	add Product to products

																								//	edit product:
	bool editProductCountry(const char* name, const char* newCountry);							//	country,
	bool editProductPrice(const char* name, double newPrice);									//	price,
	bool editProductType(const char* name, const char* newType);								//	type,
	bool editProductIndividualAbility(const char* name, const char* newIndividualAbility);		//	individual ability,
	bool editProductGroup(const char* name, const char* newGroup);								//	group,
	bool editProductBarCode(const char* name, int newBarCode);									//	barcode,
	bool editProductName(const char* name, const char* newName);								//	name.

	bool addAccount(User& user);																//	delete User from users
	bool deleteAccount(const char* login);														//	add User to users

																								//	edit user:
	bool editUserLogin(const char* login, const char* newLogin);								//	login,
	bool editUserPassword(const char* login, const char* newPassword);							//	password,
	bool editUserName(const char* login, const char* newName);									//	name,
	bool editUserSurname(const char* login, const char* newSurname);							//	surname,
	bool editUserAge(const char* login, const int newAge);										//	age.

																								//	sort users by:
	void sortUsersByLogin();																	//	login,
	void sortUsersByName();																		//	name,
	void sortUsersBySurname();																	//	surname,
	void sortUsersByAge();																		//	age.

	User& findUser(const char* login);															//	find user in users

	bool saveProductsToFile();																	//	save products to file
};