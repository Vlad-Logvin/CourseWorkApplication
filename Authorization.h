#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "FriendFunctions.h"
#include "Files.h"

using namespace std;

class Authorization
{
public:
	Authorization(const char* login, const char* password, int role = USER);		//	constructor

	Authorization(const Authorization& authorization);								//	copy constructor
	Authorization& operator= (const Authorization& authorization);					//	operator = overload

	~Authorization();																//	destructor 

	bool enter();																	//	authorization methods that provides
	bool registration(const char* name = undefined,									//	users access to system		
		const char* surname = undefined,											//
		int age = defaultNumber);													//				

	char* getLogin();																//	login getter
	char* getHashPassword();														//	hash password getter
	char* getSalt();																//	salt getter
	int getRole();																	//	role getter

	void setLogin(const char* newLogin);											//	login setter
	void setPassword(const char* newPassword);										//	password setter

private:
	bool isExist();																	//	checking for data existence

	char* login;																	//	login
	char* hashPassword;																//	hash password

	bool write(ostream& os,															//	methods for data input output
		const char* name = undefined,												//	in file
		const char* surname = undefined,											//
		int age = defaultNumber);													//
	bool read(istream& is);															//

	void makeHashPassword(const char* password);									//	method that makes hash password
	char* returnUnhashPassword();													//	method that unhashes password
	void makeSalt(const char* password);											//	method that makes salt

protected:
	char* salt;																		//	salt for making hash password
	int role;																		//	role
	Authorization();																//	default constructor
	void setHashPassword(const char* newHashPassword);								//	hash password setter
};
