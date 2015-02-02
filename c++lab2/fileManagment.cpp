#include <string>
#include <sstream>
#include <fstream>
#include "Player.h"


using namespace std;

Player* getPlayers(string fileName, int *numberOfPlayers)
{
	ifstream inData;
	Player *players = NULL;
	inData.open(fileName.c_str());
	if (inData.is_open())
	{
		string converter;
		string firstName;
		string lastName;
		int birthYear;
		int numberOfMatches;
		string matchDate;
		getline(inData, converter);
		*numberOfPlayers = atoi(converter.c_str());
		players = new Player[*numberOfPlayers];

		for (int i = 0; i < *numberOfPlayers; i++)
		{
			getline(inData, firstName);
			getline(inData, lastName);
			getline(inData, converter);//birthyear
			birthYear = atoi(converter.c_str());
			players[i] = Player(firstName, lastName, birthYear);
			getline(inData, converter);//number of matches
			numberOfMatches = atoi(converter.c_str());
			for (int i = 0; i < numberOfMatches; i++)
			{
				getline(inData, matchDate);
				players[i].addMatchDate(matchDate);
			}
		}
	}
	inData.close();
	return players;
}

void writePlayers(string fileName, )
ofstream outData;
