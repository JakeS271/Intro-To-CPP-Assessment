#include <iostream>
#include "MyString.h"
//DO COPY CONSTRUCTOR!
int main()
{
	MyString string1("Jake");
	MyString string2("Jack");

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

	system("PAUSE");
    return 0;
}

