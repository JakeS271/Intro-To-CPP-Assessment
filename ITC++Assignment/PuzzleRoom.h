#pragma once
#include "lockRoom.h"
class puzzleRoom : public lockRoom
{
public:
	puzzleRoom();
	~puzzleRoom();

	void puzzleAnswer(MyString& command);
	void setAnswer(MyString answer, MyString item, MyString output);
	void Update(MyString& command);

protected:

	struct passwordItem
	{
		MyString password;
		MyString item;
		MyString output;

		passwordItem(MyString p, MyString i, MyString o) : password(p), item(i), output(o) {}
	};
	std::vector<passwordItem> pItems;
};

