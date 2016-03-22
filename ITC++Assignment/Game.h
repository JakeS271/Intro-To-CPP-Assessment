#pragma once
class Game
{
public:
	Game();
	~Game();

	void start();
private:
	const int MAX_SIZE = 256;
	MyString intro ("\nWelcome to The Mansion.\nYou are trapped inside and must find a way out.\nWatch out though as you might not be as alone in there.");
};

