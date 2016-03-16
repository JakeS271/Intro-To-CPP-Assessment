#pragma once
class MyString
{
private:
	char* chars;
	int sLength = 0;

public:
	MyString();
	MyString(const char* string);
	~MyString();

	char operator [](int i);
	//char operator =(MyString& rhs);	//FIX!

	int Length(const char* string);
	int Length();
	int Compare(const MyString& rhs);
	void Append(const MyString& rhs);
	void Prepend(const MyString& rhs);
	void Uppercase();
	void Lowercase();
	int Find(char c[]);
	int Find(char c[], int i);

	int getSize();
	void print();
};

