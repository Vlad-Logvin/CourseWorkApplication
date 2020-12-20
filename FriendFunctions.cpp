#include "FriendFunctions.h"

const char* undefined = "undefined";		//default constant
const int defaultNumber = -1;				//default constant

//tips
const char* lettersTip = "The field can contain:\nletters from a to z;\nuppercase letters from A to Z;\nhyphen '-'.\n";
const char* numbersTip = "The field can contains:\nnumbers from 0 to 9.\n";
const char* lettersAndNumbersTip = "The field can contain:\nletters from a to z;\nuppercase letters from A to Z;\nhyphen '-';\nnumbers from 0 to 9.\n";
const char* lettersAndNumbersAndSpaceTip = "The field can contain:\nletters from a to z;\nuppercase letters from A to Z;\nhyphen '-';\nwhitespace ' ';\nnumbers from 0 to 9.\n";
const char* doubleNumbersTip = "The field can contains:\nnumbers from 0 to 9;\nfloating point ','.\n";
const char* lettersAndSpaceTip = "The field can contain:\nletters from a to z;\nuppercase letters from A to Z;\nhyphen '-';\nwhitespace ' '.\n";

void copyString(const char* str1, char*& str2)		//copy string 1 to string 2
{
	try
	{
		if (str1 == nullptr)
		{
			str2 = nullptr;
		}
		else
		{
			str2 = new char[strlen(str1) + 1];
			for (int i = 0; i < strlen(str1); i++)
			{
				str2[i] = str1[i];
			}
			str2[strlen(str1)] = '\0';
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}

bool equal(const char* str1, const char* str2)		//equal strings
{
	try
	{
		if (str1 == nullptr || str2 == nullptr)
		{
			return false;
		}
		if (strlen(str1) != strlen(str2))
		{
			return false;
		}
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				return false;
			}
		}
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
		return false;
	}
}

int compareString(const char* str1, const char* str2)		//equal strings
{
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] < str2[i])
		{
			return MORE;
		}
		else if (str1[i] > str2[i])
		{
			return LESS;
		}
	}
	if (strlen(str1) < strlen(str2))
	{
		return MORE;
	}
	if (strlen(str1) > strlen(str2))
	{
		return LESS;
	}
	return EQUAL;
}

char* convertSpaceToUnderline(char* str)		//method which make from ' ' -> '_'
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '_';
		}
	}
	return str;
}

char* convertUnderlineToSpace(char* str)		//method which make from '_' -> ' '
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '_')
		{
			str[i] = ' ';
		}
	}
	return str;
}

void MarshalString(String^ s, std::string& outputstring)		//method that convert String^ to string
{
	const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	outputstring = kPtoC;
	Marshal::FreeHGlobal(IntPtr((void*)kPtoC));
}

bool isCorrectNumberInput(System::Windows::Forms::KeyPressEventArgs^ e) {		//method for input
	if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
	{
		return true;
	}
	return false;
}

bool isCorrectLettersInput(System::Windows::Forms::KeyPressEventArgs^ e) {		//method for input
	if ((e->KeyChar < 'a' || e->KeyChar > 'z') &&
		(e->KeyChar < 'A' || e->KeyChar > 'Z') &&
		e->KeyChar != 8 &&
		e->KeyChar != '-')
	{
		return true;
	}
	return false;
}

bool isCorrectLettersAndNumbersInput(System::Windows::Forms::KeyPressEventArgs^ e) {		//method for input
	if ((e->KeyChar < '0' || e->KeyChar > '9') &&
		(e->KeyChar < 'a' || e->KeyChar > 'z') &&
		(e->KeyChar < 'A' || e->KeyChar > 'Z') &&
		e->KeyChar != 8 &&
		e->KeyChar != '-')
	{
		return true;
	}
	return false;
}

bool isCorrectLettersAndNumbersAndSpaceInput(System::Windows::Forms::KeyPressEventArgs^ e) {		//method for input
	if ((e->KeyChar < '0' || e->KeyChar > '9') &&
		(e->KeyChar < 'a' || e->KeyChar > 'z') &&
		(e->KeyChar < 'A' || e->KeyChar > 'Z') &&
		e->KeyChar != 8 &&
		e->KeyChar != '-' &&
		e->KeyChar != ' ' &&
		e->KeyChar != ',')
	{
		return true;
	}
	return false;
}

bool isCorrectDoubleNumberInput(System::Windows::Forms::KeyPressEventArgs^ e) {		//method for input
	if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8 && e->KeyChar != ',')
	{
		return true;
	}
	return false;
}

bool isCorrectLettersAndSpaceInput(System::Windows::Forms::KeyPressEventArgs^ e)		//method for input
{
	if ((e->KeyChar < 'a' || e->KeyChar > 'z') &&
		(e->KeyChar < 'A' || e->KeyChar > 'Z') &&
		e->KeyChar != 8 &&
		e->KeyChar != '-' &&
		e->KeyChar != ' ')
	{
		return true;
	}
	return false;
}
