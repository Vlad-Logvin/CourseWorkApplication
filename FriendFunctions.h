#pragma once

#include <iostream>

using namespace System;
using namespace Runtime::InteropServices;

#define LESS -1														//	values for comparing
#define EQUAL 0														//	
#define MORE 1														//

#define USER 0														//	users roles
#define ADMIN 1														//
#define CREATOR 2													//

extern const char* undefined;										//	underfined for default variables in classes for char*
extern const int defaultNumber;										//	default number for default variables in classes for int and double
extern const char* lettersTip;
extern const char* numbersTip;
extern const char* lettersAndNumbersTip;
extern const char* lettersAndNumbersAndSpaceTip;
extern const char* doubleNumbersTip;
extern const char* lettersAndSpaceTip;

void copyString(const char* str1, char*& str2);						//	copy str1 to str2
bool equal(const char* str1, const char* str2);						//	is str1 == str2
int compareString(const char* str1, const char* str2);				//	returns LESS EQUAL or MORE depending on comparing str1 and str2
char* convertSpaceToUnderline(char* str);							//	converts space into underline for file
char* convertUnderlineToSpace(char* str);							//	converts underline into space for file
void MarshalString(String^ s, std::string& outputstring);
bool isCorrectNumberInput(System::Windows::Forms::KeyPressEventArgs^ e);
bool isCorrectLettersInput(System::Windows::Forms::KeyPressEventArgs^ e);
bool isCorrectLettersAndNumbersInput(System::Windows::Forms::KeyPressEventArgs^ e);
bool isCorrectLettersAndNumbersAndSpaceInput(System::Windows::Forms::KeyPressEventArgs^ e);
bool isCorrectDoubleNumberInput(System::Windows::Forms::KeyPressEventArgs^ e);
bool isCorrectLettersAndSpaceInput(System::Windows::Forms::KeyPressEventArgs^ e);

template <typename T>
void swapElements(T& t1, T& t2) {
	T swap = t1;
	t1 = t2;
	t2 = swap;
}
