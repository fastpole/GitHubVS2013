#ifndef PLAYER_H
#define PLAYER_H



class Player
{
public:
	string firstName;
	string lastName;
	int birthYear;
	string *matchDates;
	Player();
	Player(string firstName, string lastName, int birthYear);
	~Player();
	string toString();
	void addMatchDate(string date);
	
private:
	int numberOfMatches;
};
#endif
