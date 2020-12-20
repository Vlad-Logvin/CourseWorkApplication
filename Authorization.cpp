#include "Authorization.h"

Authorization::Authorization()		//default constructor
{
	this->login = nullptr;
	this->hashPassword = nullptr;
	this->salt = nullptr;
	role = -1;
}

Authorization::Authorization(const char* login, const char* password, int role)		//constructor
{
	copyString(login, this->login);
	makeHashPassword(password);
	this->role = role;
}

Authorization::Authorization(const Authorization& authorization)		//copy constructor
{
	copyString(authorization.login, this->login);
	copyString(authorization.hashPassword, this->hashPassword);
	copyString(authorization.salt, this->salt);
	this->role = authorization.role;
}

Authorization& Authorization::operator=(const Authorization& authorization)		//operator = overload
{
	copyString(authorization.login, this->login);
	copyString(authorization.hashPassword, this->hashPassword);
	copyString(authorization.salt, this->salt);
	this->role = authorization.role;
	return *this;
}

Authorization::~Authorization()		//destructor
{
	if (this->login != nullptr)
	{
		delete[]this->login;
	}
	if (this->hashPassword != nullptr)
	{
		delete[]this->hashPassword;
	}
	if (this->salt != nullptr)
	{
		delete[]this->salt;
	}
}

bool Authorization::enter()		//enter to the system
{
	try
	{
		ifstream in;
		in.exceptions(ifstream::badbit | ifstream::failbit);
		in.open(usersFile);
		if (in.is_open())
		{
			Authorization temp;
			while (!in.eof())
			{
				bool isRead = temp.read(in);
				if (isRead == true && equal(this->login, temp.login))
				{
					if (equal(this->returnUnhashPassword(), temp.returnUnhashPassword()))
					{
						in.close();
						return true;
					}
				}
			}
			in.close();
			return false;
		}
		else
		{
			throw exception("File could not be open");
		}
	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}

bool Authorization::registration(const char* name, const char* surname, int age)		//user regiistration
{
	try
	{
		if (this->isExist())
		{
			return false;
		}
		ofstream out;
		out.exceptions(ofstream::failbit | ofstream::badbit);
		out.open(usersFile, ios::app);
		if (out.is_open())
		{
			bool isWrite = this->write(out, name, surname, age);
			out.close();
			return isWrite;
		}
		else
		{
			throw exception("File could not be open");
		}
	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}

char* Authorization::getLogin()		//login getter
{
	return login;
}

char* Authorization::getHashPassword()		//hash password getter
{
	return hashPassword;
}

char* Authorization::getSalt()		//salt getter
{
	return this->salt;
}

int Authorization::getRole()		//role getter
{
	return this->role;
}

void Authorization::setLogin(const char* newLogin)		//login setter
{
	copyString(newLogin, this->login);
}

void Authorization::setHashPassword(const char* newHashPassword)	//hash password setter
{
	copyString(newHashPassword, this->hashPassword);
}

void Authorization::setPassword(const char* newPassword)		//password setter
{
	makeHashPassword(newPassword);
}

bool Authorization::isExist()		//is account exist in database
{

	ifstream in;
	in.open(usersFile);
	if (in.is_open())
	{
		string temp;
		while (!in.eof())
		{
			in >> temp;
			if (equal(this->login, temp.c_str()))
			{
				in.close();
				return true;
			}
			getline(in, temp);
		}
		in.close();
		return false;
	}
	else
	{
		return false;
	}
}

bool Authorization::write(ostream& os, const char* name, const char* surname, int age)		//write object to file
{
	os.seekp(0, ios::end);
	if (os.tellp() != 0)
	{
		os << endl;
	}
	else
	{
		this->role = CREATOR;
	}
	char* tempName, * tempSurname;
	copyString(name, tempName);
	copyString(surname, tempSurname);
	os << convertSpaceToUnderline(this->login)
		<< " " << defaultNumber
		<< " " << this->role
		<< " " << convertSpaceToUnderline(this->hashPassword)
		<< " " << convertSpaceToUnderline(this->salt)
		<< " " << convertSpaceToUnderline(tempName)
		<< " " << convertSpaceToUnderline(tempSurname)
		<< " " << age;
	return !os.fail();
}

bool Authorization::read(istream& is)		//read object from file
{
	string fileLogin, fileSalt, fileHashPassword, temp;
	is >> fileLogin >> temp >> this->role >> fileHashPassword >> fileSalt;
	getline(is, temp);
	copyString(fileLogin.c_str(), this->login);
	copyString(fileHashPassword.c_str(), this->hashPassword);
	copyString(fileSalt.c_str(), this->salt);
	this->login = convertUnderlineToSpace(this->login);
	this->hashPassword = convertUnderlineToSpace(this->hashPassword);
	this->salt = convertUnderlineToSpace(this->salt);
	return !is.fail();
}

void Authorization::makeHashPassword(const char* password)		//method which make hash password
{
	makeSalt(password);
	this->hashPassword = new char[strlen(password) + 1];
	for (int i = 0; i < strlen(password); i++)
	{
		this->hashPassword[i] = (password[i] + this->salt[i]) / 2;
	}
	this->hashPassword[strlen(password)] = '\0';
}

char* Authorization::returnUnhashPassword()		//method which unhashes password
{
	char* password = new char[strlen(this->hashPassword) + 1];
	for (int i = 0; i < strlen(this->hashPassword); i++)
	{
		password[i] = 2 * this->hashPassword[i] - this->salt[i];
	}
	password[strlen(this->hashPassword)] = '\0';
	return password;
}

void Authorization::makeSalt(const char* password)		//method that makes salt
{
	this->salt = new char[strlen(password) + 1];
	srand(time(NULL));
	for (int i = 0; i < strlen(password); i++)
	{
		this->salt[i] = rand() % ('z' - 'a') + 'a';
		if (static_cast<int>(password[i] + salt[i]) % 2 == 1)
		{
			this->salt[i] += 1;
		}
	}
	this->salt[strlen(password)] = '\0';
}