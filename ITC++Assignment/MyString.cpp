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
}

char MyString::operator [](int i)
{
	return chars[i];
}
void MyString::operator =(MyString& rhs)
{
	int l = Length(chars);
	for (int i = 0; i < l; i++)
	{
		chars[i] = rhs.chars[i];
	}
	chars[l] = '\0';
}	
void MyString::operator =(char* rhs)
{
	int l = Length(rhs);
	for (int i = 0; i < l; i++)
	{
		chars[i] = rhs[i];
	}
	chars[l] = '\0';
}

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
					position = -1;
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
		i++;
	}
	return position;
}
int MyString::Find(char c[], int i)
{
	int index = 0, position = -1;
	bool found = false;
	while (i < getSize() && found == false)
	{
		if (chars[i] == c[index])
		{
			while (c[index] != '\0')
			{
				if (!(chars[i + index] == c[index]))
				{
					position = -1;
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
		i++;
	}
	return position;
}
void MyString::Replace(char subString[], int pos, int length)
{
	int i, index = 0;
	int totalLength = length + Length(subString);
	char* temp = new char[totalLength];
	
	for (int i = 0; i < pos; i++)
	{
		temp[i] = chars[i];
	}
	int length2 = (pos + Length(subString));
	for (int i = pos; i < length2; i++)
	{
		temp[i] = subString[index];
		index++;
	}
	i = length2;
	while(chars[i] < totalLength)
	{
		temp[i] = chars[i];
		i++;
	}

	temp[totalLength] = '\0';
	delete[] chars;
	chars = temp;
	sLength = length2;

}
char* MyString::toChar()
{
	int l = Length(chars);
	char* newChar = new char[l];
	
	for (int i = 0; i < l; i++)
	{
		newChar[i] = chars[i];
	}
	newChar[l] = '\0';
	return newChar;
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