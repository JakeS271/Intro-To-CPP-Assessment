#pragma once
class MyString
{
private:
	char* m_chars;
	int m_sLength = 0;

public:
	MyString();												//MyString constructor default. 
	MyString(const MyString& string);						//MyString copy constructor
	MyString(const char* string);							//MyString constructor with specific content.
	~MyString();											//MyString destructor.

	char operator [](int i);								//Overloads the [] operator to return a specific value in an array.
	void operator =(MyString& rhs);							//Overloads the = operator so that MyString can equal another MyString.
	void operator =(char* rhs);								//Overloads the = operator so that MyString can equal a char array.
	bool operator ==(MyString& rhs);						//Overloads the == operator so that MyString can be compared against a MyString.
	bool operator ==(char* rhs);							//Overloads the == operator so that MyString can be compared against a char array.


	int Length(const char* string);							//Returns length of MyString.
	int Length();											//Returns length of a char array.
	int Compare(const MyString& rhs);						//Compares one MyString with another MyString.
	void Append(const MyString& rhs);						//Appends a MyString to the end of another MyString.
	void Prepend(const MyString& rhs);						//Prepends a MyString to the beginning of another MyString.
	void Uppercase();										//Converts MyString to uppercase.
	void Lowercase();										//Converts MyString to lowercase.
	int Find(char c[]);										//Finds a substring.
	int Find(MyString& string);								//Finds a substring from a MyString.
	int Find(char c[], int i);								//Finds a substring from a certain index.
	void Replace(char subString[], int pos, int length);	//Replaces a substring with another string.
	char* toChar();											//Returns MyString as a char.

	int getSize();											//Returns size variable.
	void print();											//Prints MyString to console.
};

