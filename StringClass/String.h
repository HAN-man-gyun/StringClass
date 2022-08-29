#pragma once
#include <iostream>
class String
{
	char* string;
	int length;
public:
	String();
	String(int inputi);
	String(const char* inputl);
	String(const String& string);
	int Getlength() const { return length; }
	const char* GetString()const { return string; }
	~String();
	String operator+(const String& right);
	String& operator=(const String& right);
	void operator+=(const String& right);
	char& operator[](int index);
	char operator[](int index)const;
	friend std::ostream& operator << (std::ostream& os, const String string);
};

