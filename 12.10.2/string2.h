#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class String
{
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& s);
	~String();
	int length() const { return len; }

	String& operator=(const String& s);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	friend bool operator<(const String& s1, const String& s2);
	friend bool operator>(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	friend String operator+(const String& s1, const String& s2);

	void stringup();
	void stringlow();
	int has(char c);

	static int HowMany();
};