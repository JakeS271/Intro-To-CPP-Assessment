#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	sLength = 1;
	chars = new char[sLength];
	chars[0] = '\0';
}
MyString::MyString(const char* string)
{
	sLength = Length(string);
	chars = new char[sLength + 1];

	for (int i = 0; i < sLength; i++)
	{
		chars[i] = string[i];
	}
	chars[sLength] = '\0';
}
MyString::~MyString()
{
	delete[] chars;
}

char MyString::operator [](int i)
{
	return chars[i];
}
/*char MyString::operator =(MyString& rhs)
{
	for (int i = 1; i < Length(chars); i++)
	{
		chars[i] = rhs.chars[i];
	}
}	 //FIX!*/

int MyString::Length(const char* string)
{
	int counter = 0;

	while (string[counter] != '\0')
	{
		counter++;
	}

	return counter;
}
int MyString::Length()
{
	int counter = 0;

	while (chars[counter] != '\0')
	{
		counter++;
	}

	return counter;
}
int MyString::Compare(const MyString& rhs)
{
	for (int i = 0; i < Length(); i++)
	{
		if (chars[i] != rhs.chars[i])
		{
			if (chars[i] > rhs.chars[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}
void MyString::Append(const MyString& rhs)
{
	int newLength = Length() + Length(rhs.chars) + 1;
	char* temp = new char[newLength + 1];
	
	for (int i = 0; i < Length(); i++)
	{
		temp[i] = chars[i];
	}

	int index = 0;
	for (int i = Length(); i < newLength; i++)
	{
		temp[i] = rhs.chars[index];
		index++;
	}

	temp[newLength] = '\0';
	delete[] chars;
	chars = temp;
	sLength = newLength;
}
void MyString::Prepend(const MyString& rhs)
{
	int newLength = Length() + Length(rhs.chars) + 1;
	char* temp = new char[newLength + 1];

	for (int i = 0; i < Length(rhs.chars); i++)
	{
		temp[i] = rhs.chars[i];
	}

	int index = 0;
	for (int i = Length(rhs.chars); i < newLength; i++)
	{
		temp[i] = chars[index];
		index++;
	}

	temp[newLength] = '\0';
	delete[] chars;
	chars = temp;
	sLength = newLength;
}
void MyString::Uppercase()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (chars[i] >= 'a' && chars[i] <= 'z')
		{
			chars[i] = ((chars[i] + 'A') - 'a');
		}
	}
}
void MyString::Lowercase()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (chars[i] >= 'A' && chars[i] <= 'Z')
		{
			chars[i] = ((chars[i] + 'a') - 'A');
		}
	}
}
int MyString::Find(char c[])
{
	int index = 0, i = 0, position = -1;
	bool found = false;
	while (i < getSize() && found == false)
	{
		if (chars[i] == c[index])
		{
			while (c[index] != '\0')
			{
				if (!(chars[i + index] == c[index]))
				{
					index = 0;
					found = false;
					break;
				}
				else
				{
					position = i;
					index++;
					found = true;
				}
			}
		}
	}
	return position;
}
int MyString::Find(char c[], int i)
{
	return 0;
}

int MyString::getSize()
{
	return sLength;
}
void MyString::print()
{
	for (int i = 0; i < sLength; i++)
	{
		std::cout << chars[i];
	}
	std::cout << "\n";
}