#include "String.h"
#include <iostream>

String::String() :length{ 0 }
{
	string = new char [1];
	string[0] = '\0';
}

String::String( int inputi):length{inputi}
{
	string = new char[inputi+1];
	for(int i =0; i<length;++i)
	{
		string[i] = '\0';
	}
	
}

String::String(const char* inputl)
{
	const char* temp = inputl;
	int size{ 0 };
	while (*temp != '\0') 
	{
		temp++;
		size++;
	}
	string = new char[size+1];
	length = size;
	for (size = 0; size < length; ++size)
	{
		string[size] = inputl[size];
	}
	string[size] = '\0';
}

String::String(const String& right)
{
	length=right.Getlength();
	string = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		string[i] = right[i];
	}
	string[length] = '\0';
}
String::~String()
{
	delete[] string;
	string = nullptr;
	length = 0;
}

String String::operator+(const String& right)
{
	int tempLength = length + right.Getlength();
	String result(tempLength);
	int index = 0;
	for (int i = 0; i < length; ++i,++index)
	{
		result[index] = string[i];
	}
	for (int i = 0; i < right.length; ++i,++index)
	{
		result[index] = right.string[i];
	}
	result[tempLength] = '\0';
	return result;
}
void String::operator+=(const String& right)
{
	String result = *this + right;
	*this = result;
}
String& String::operator=(const String& right)
{
	if (this == &right)
	{
		return *this;
	}
	delete[] string;
	length = right.Getlength();
	string = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		string[i] = right[i];
	}
	string[length] = '\0';
	return *this;
}
char& String::operator[](int index)
{
	return (index > length) ? string[length] : string[index];
}

char String::operator[](int index)const
{
	return (index > length) ? string[length] : string[index];
}

std::ostream& operator<<(std::ostream& os, const String string)
{
	os << string.string;
	return os;
}
