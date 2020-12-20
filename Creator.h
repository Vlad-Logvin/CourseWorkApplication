#pragma once
#include "Admin.h"

class Creator : public Admin
{
public:
	Creator(const char* login) : Admin(login) {}							//	constructor
	bool changeRole(const char* login, const int newRole);					//	change users role
};