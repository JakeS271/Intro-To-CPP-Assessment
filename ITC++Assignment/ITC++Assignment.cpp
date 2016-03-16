#include <iostream>
#include "MyString.h"
//DO COPY CONSTRUCTOR!
//Do equals operator for converting from MyString to char array.
int main()
{
	MyString string1("Jake");
	MyString string2("Jack");
	char char1[30];
	string1.print();

	//MyString string3 = string1;
	//std::cout << string3[0] << std::endl;

	std::cout << string1.Length() << "\n";
	std::cout << string1.Compare(string2) << "\n";
	std::cout << string2.Compare(string1) << "\n";
	std::cout << string1.Compare(string1) << "\n";

	string1.Append(string2);
	string1.print();

	string1.Prepend(string2);
	string1.print();

	string1.Uppercase();
	string1.print();

	string1.Lowercase();
	string1.print();

	std::cout << string1.Find("jake") << std::endl;
	std::cout << string1.Find("jess") << std::endl;


	//char1 = string1;

	system("PAUSE");
    return 0;
}

