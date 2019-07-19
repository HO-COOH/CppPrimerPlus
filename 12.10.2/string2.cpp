#include <string.h>
#include "string2.h"

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	++num_strings;
}
String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	++num_strings;
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	++num_strings;
}
String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	++num_strings;
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& s1, const String& s2)
{
	return (strcmp(s1.str,s2.str)<0);
}

bool operator>(const String& s1, const String& s2)
{
	return s2 < s1;
}

bool operator==(const String& s1, const String& s2)
{
	return (strcmp(s1.str, s2.str)==0);
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		s = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String operator+(const String& s1, const String& s2)
{
	if((s1.len+s2.len)>String::CINLIM-2)
	return String();
	char temp[String::CINLIM];
	strcpy(temp, s1.str);
	strcat(temp, s2.str);
	return String(temp);
}

void String::stringup()
{
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
}

void String::stringlow()
{
	for (int i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
}

int String::has(char c)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == c)
			++count;
	}
	return count;
}