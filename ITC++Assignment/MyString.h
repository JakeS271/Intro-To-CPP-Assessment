#pragma once
class MyString
{
private:
	char* m_chars;
	int m_sLength = 0;

public:
	MyString();
	MyString(const char* string);
	~MyString();

	char operator [](int i);
	void operator =(MyString& rhs);	
	void operator =(char* rhs);

	int Length(const char* string);
	int Length();
	int Compare(const MyString& rhs);
	void Append(const MyString& rhs);
	void Prepend(const MyString& rhs);
	void Uppercase();
	void Lowercase();
	int Find(char c[]);
	int Find(char c[], int i);
	void Replace(char subString[], int pos, int length);
	char* toChar();

	int getSize();
	void print();
};

