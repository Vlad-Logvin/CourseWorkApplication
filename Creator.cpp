#include "Creator.h"

bool Creator::changeRole(const char* login, const int newRole)		//role setter
{
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it)
	{
		if (equal(login, (*it).getLogin()))
		{
			if ((*it).role == CREATOR)
			{
				return false;
			}
			(*it).role = newRole;
			return true;
		}
	}
	return false;
}