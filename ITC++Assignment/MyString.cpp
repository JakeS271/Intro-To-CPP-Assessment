#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	m_sLength = 256;
	m_chars = new char[m_sLength];
	m_chars[0] = '\0';
}
MyString::MyString(const char* string)
{
	m_sLength = Length(string);
	m_chars = new char[m_sLength + 1];

	for (int i = 0; i < m_sLength; i++)
	{
		m_chars[i] = string[i];
	}
	m_chars[m_sLength] = '\0';
}

MyString::MyString(const MyString& string) : MyString(string.m_chars)
{

}

MyString::~MyString()
{
}

char MyString::operator [](int i)
{
	return m_chars[i];
}
void MyString::operator =(MyString& rhs)
{
	int l = Length(rhs.m_chars);
	for (int i = 0; i < l; i++)
	{
		m_chars[i] = rhs.m_chars[i];
	}
	m_chars[l] = '\0';
}	
void MyString::operator =(char* rhs)
{
	int l = Length(rhs);
	for (int i = 0; i < l; i++)
	{
		m_chars[i] = rhs[i];
	}
	m_chars[l] = '\0';
}

bool MyString::operator ==(MyString& rhs)
{
	int l = Length();
	for (int i = 0; i < l; i++)
	{
		if (m_chars[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

bool MyString::operator ==(char* rhs)
{
	int l = Length(rhs);
	for (int i = 0; i < l; i++)
	{
		if (m_chars[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
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

	while (m_chars[counter] != '\0')
	{
		counter++;
	}

	return counter;
}
int MyString::Compare(const MyString& rhs)
{
	for (int i = 0; i < Length(); i++)
	{
		if (m_chars[i] != rhs.m_chars[i])
		{
			if (m_chars[i] > rhs.m_chars[i])
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
	int newLength = Length() + Length(rhs.m_chars) + 1;
	char* temp = new char[newLength + 1];
	
	for (int i = 0; i < Length(); i++)
	{
		temp[i] = m_chars[i];
	}

	int index = 0;
	for (int i = Length(); i < newLength; i++)
	{
		temp[i] = rhs.m_chars[index];
		index++;
	}

	temp[newLength] = '\0';
	delete[] m_chars;
	m_chars = temp;
	m_sLength = newLength;
}
void MyString::Prepend(const MyString& rhs)
{
	int newLength = Length() + Length(rhs.m_chars) + 1;
	char* temp = new char[newLength + 1];

	for (int i = 0; i < Length(rhs.m_chars); i++)
	{
		temp[i] = rhs.m_chars[i];
	}

	int index = 0;
	for (int i = Length(rhs.m_chars); i < newLength; i++)
	{
		temp[i] = m_chars[index];
		index++;
	}

	temp[newLength] = '\0';
	delete[] m_chars;
	m_chars = temp;
	m_sLength = newLength;
}
void MyString::Uppercase()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (m_chars[i] >= 'a' && m_chars[i] <= 'z')
		{
			m_chars[i] = ((m_chars[i] + 'A') - 'a');
		}
	}
}
void MyString::Lowercase()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (m_chars[i] >= 'A' && m_chars[i] <= 'Z')
		{
			m_chars[i] = ((m_chars[i] + 'a') - 'A');
		}
	}
}
int MyString::Find(char c[])
{
	int index = 0, i = 0, position = -1;
	bool found = false;
	while (i < getSize() && found == false)
	{
		if (m_chars[i] == c[index])
		{
			while (c[index] != '\0')
			{
				if (!(m_chars[i + index] == c[index]))
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
int MyString::Find(MyString& string)
{
	int index = 0, i = 0, position = -1;
	bool found = false;
	while (i < getSize() && found == false)
	{
		if (m_chars[i] == string[index])
		{
			while (string[index] != '\0')
			{
				if (!(m_chars[i + index] == string[index]))
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
		if (m_chars[i] == c[index])
		{
			while (c[index] != '\0')
			{
				if (!(m_chars[i + index] == c[index]))
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
		temp[i] = m_chars[i];
	}
	int length2 = (pos + Length(subString));
	for (int i = pos; i < length2; i++)
	{
		temp[i] = subString[index];
		index++;
	}
	i = length2;
	while(m_chars[i] < totalLength)
	{
		temp[i] = m_chars[i];
		i++;
	}

	temp[totalLength] = '\0';
	delete[] m_chars;
	m_chars = temp;
	m_sLength = length2;

}
char* MyString::toChar()
{
	int l = Length(m_chars);
	char* newChar = new char[l];
	
	for (int i = 0; i < l; i++)
	{
		newChar[i] = m_chars[i];
	}
	newChar[l] = '\0';
	return newChar;
}

int MyString::getSize()
{
	return m_sLength;
}
void MyString::print()
{
	for (int i = 0; i < Length(); i++)
	{
		std::cout << m_chars[i];
	}
	std::cout << "\n";
}