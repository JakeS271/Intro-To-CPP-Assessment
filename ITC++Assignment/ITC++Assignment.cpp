#include <iostream>
#include "MyString.h"
#include <fstream>
#include <string>
#include "Game.h"

double TestOutcome(bool outcome, double successCount, double testCounter, char* c);

int main()
{
	MyString string1("Jake");
	MyString string2("Jack");
	char name[]{ "Sam" };
	std::string line[256];
	double testCount = 1, successCount = 0;
	bool outcome;

	std::fstream TestFile;

	outcome = (string1.Length() == 4);
	successCount = TestOutcome(outcome, successCount, testCount, "\tLength\t\t ");

	testCount++;
	outcome = (string1[0] == 'J');
	successCount = TestOutcome(outcome, successCount, testCount, "\tAccess Char\t ");

	testCount++;
	outcome = (string1.Compare(string1) == 0);
	successCount = TestOutcome(outcome, successCount, testCount, "\tCompare\t\t ");

	testCount++;
	string1.Append(string2);
	outcome = (string1.Length() == 8);
	successCount = TestOutcome(outcome, successCount, testCount, "\tAppend\t\t ");

	testCount++;
	string1.Prepend(string2);
	outcome = (string1.Length() == 12);
	successCount = TestOutcome(outcome, successCount, testCount, "\tPrepend\t\t ");

	testCount++;
	char* newChar = string1.toChar();
	outcome = (newChar[0] == string1[0]);
	successCount = TestOutcome(outcome, successCount, testCount, "\tToChar\t\t ");

	testCount++;
	string1.Uppercase();
	outcome = (string1[0] >= 'A' && string1[0] <= 'Z');
	successCount = TestOutcome(outcome, successCount, testCount, "\tUppercase\t ");

	testCount++;
	string1.Lowercase();
	outcome = (string1[0] >= 'a' && string1[0] <= 'z');
	successCount = TestOutcome(outcome, successCount, testCount, "\tLowercase\t ");

	testCount++;
	int index = string1.Find("jake");
	outcome = (index == 4);
	successCount = TestOutcome(outcome, successCount, testCount, "\tFind\t\t ");

	testCount++;
	index = string1.Find("jack", 4);
	outcome = (index == 8);
	successCount = TestOutcome(outcome, successCount, testCount, "\tFind Index\t ");

	testCount++;
	int pos = string1.Find("jack", 3), l = string1.Length();
	string1.Replace(name, pos, l);
	outcome = (string1[pos] == name[0]);
	successCount = TestOutcome(outcome, successCount, testCount, "\tReplace\t\t ");

	testCount++;
	MyString string3 = name;
	outcome = (string3[0] == name[0]);
	successCount = TestOutcome(outcome, successCount, testCount, "\tSet String\t ");

	TestFile.open("TestFile.txt", std::ios::app);

	if (TestFile.is_open() == true)
	{
		double successPercent = (successCount / testCount) * 100;
		std::cout << "\nSuccessful " << successPercent << "%\n\n";
		TestFile << "\nSuccessful " << successPercent << "%\n\n";
		TestFile.close();
	}
	else
	{
		std::cout << "Error! Cannot write to file.\n";
		TestFile.close();
	}
	
	/*delete[] &string1;
	delete[] &string2;
	delete[] &newChar;*/

	system("PAUSE");
	Game game;
	game.start();
    return 0;
}

double TestOutcome(bool outcome, double successCount, double testCount, char* c)
{
	std::fstream TestFile;
	
	TestFile.open("TestFile.txt", std::ios::app);

	if (TestFile.is_open() == true)
	{
		std::cout << "Test " << testCount << c;
		TestFile << "Test " << testCount << c;
		if (outcome == true)
		{
			std::cout << "Successful\n";
			TestFile << "Successful\n";
			successCount++;
			return successCount;
		}
		else
		{
			std::cout << "Failed\n";
			TestFile << "Failed\n";
		}
		TestFile.close();
		return successCount;
	}
	else
	{
		std::cout << "Error! Cannot write to file.\n";
		return 0;
	}
	return 0;
}
