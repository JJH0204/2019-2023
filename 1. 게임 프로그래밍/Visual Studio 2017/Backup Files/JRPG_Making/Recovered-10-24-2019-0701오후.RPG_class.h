#pragma once

class char_
{
	string name;
	int power;
	int cost;
public:
	char_(string* name, int& power, int& const);
};

class player : public char_
{
public:
	player(): char_()
	{

	}
};

class RPG
{
	player user;
public:
	void gamesetup(void);
	void gamemaster(void);
};