#include <iostream>
#include "MyString.h"
#include <fstream>

void writeToFile();

int main()
{
	MyString string1("Jake");
	MyString string2("Jack");
	char name[]{ "Sam" };
	int testCount = 1, successCount = 0;
	std::fstream TestFile;

	TestFile.open("TestFile.txt", std::ios::out, std::ios::app);

	if (TestFile.is_open() == true)
	{
		std::cout << "Test " << testCount << "\tLength\t\t ";
		TestFile << "Test " << testCount << "\tLength\t\t ";
		if (string1.Length() == 4)
		{
			std::cout << "Successful\n";
			TestFile << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
			TestFile << "Failed\n";
		}

		testCount++;
		std::cout << "Test " << testCount << "\tAccess Char\t ";
		if (string1[0] == 'J')
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		std::cout << "Test " << testCount << "\tCompare\t\t ";
		if (string1.Compare(string1) == 0)
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		std::cout << "Test " << testCount << "\tAppend\t\t ";
		string1.Append(string2);
		if (string1.Length() == 8)
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		std::cout << "Test " << testCount << "\tPrepend\t\t ";
		string1.Prepend(string2);
		if (string1.Length() == 12)
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		std::cout << "Test " << testCount << "\tToChar\t\t ";
		char* newChar = string1.toChar();
		if (newChar[0] == string1[0])
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		string1.Uppercase();
		std::cout << "Test " << testCount << "\tUppercase\t ";
		if (string1[0] >= 'A' && string1[0] <= 'Z')
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		string1.Lowercase();
		std::cout << "Test " << testCount << "\tLowercase\t ";
		if (string1[0] >= 'a' && string1[0] <= 'z')
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		int index = string1.Find("jake");
		std::cout << "Test " << testCount << "\tFind\t\t ";
		if (index == 4)
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		index = string1.Find("jack", 4);
		std::cout << "Test " << testCount << "\tFind Index\t ";
		if (index == 8)
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		int pos = string1.Find("jack", 3), l = string1.Length();
		string1.Replace(name, pos, l);
		std::cout << "Test " << testCount << "\tReplace\t\t ";
		if (string1[pos] == name[0])
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		testCount++;
		MyString string3 = name;
		std::cout << "Test " << testCount << "\tSet String\t ";
		if (string3[0] == name[0])
		{
			std::cout << "Successful\n";
			successCount++;
		}
		else
		{
			std::cout << "Failed\n";
		}

		std::cout << "\nSucessful " << (successCount / testCount) * 100 << "%\n";
	}
	else
	{
		std::cout << "Error! Cannot write to file.\n";
	}
	

	
	

	system("PAUSE");
    return 0;
}

void writeToFile()
{
	std::fstream TestFile;

	TestFile.open("TestFile.txt", std::ios::out, std::ios::app);

	if (TestFile.is_open())
	{
		//TestFile << 
	}
	else
	{
		std::cout << "Error! Cannot write to file.\n";
	}
}
