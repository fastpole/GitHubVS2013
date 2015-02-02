#include <string>
#include <sstream>
#include "Player.h"

using namespace std;

Player::Player()
{
	firstName = "";
	lastName = "";
	birthYear = 0;
	matchDates = NULL;
	numberOfMatches = 0;
}
Player::Player(string firstName, string lastName, int birthYear)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->birthYear = birthYear;
}
Player::~Player()
{
	delete[] matchDates;
}

string Player::toString()
{
	string birthYearAsString;
	ostringstream convert;
	convert << birthYear;
	birthYearAsString = convert.str();
	string s = firstName + " " + lastName + "\n" + birthYearAsString;
	if (numberOfMatches == 0)
	{
		s += "\nThere is no match dates for this player";
	}
	else
	{
		for (int i = 0; i < numberOfMatches; i++)
		{
			s += "\n" + matchDates[i];
		}
	}
	return s + "\n";
}

void Player::addMatchDate(string date)
{
	string *temp = matchDates;
	matchDates = new string[numberOfMatches + 1];
	for (int i = 0; i < numberOfMatches - 1; i++)
	{
		matchDates[i] = temp[i];
	}
	numberOfMatches++;
	matchDates[numberOfMatches] = date;
	delete[] temp;
}