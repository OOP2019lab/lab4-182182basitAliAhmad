#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class CricketTeam
{
	string* memberNames;
	int noOfMembers;
	char *teamName;
	int scoreInLast10Matches[10];
	int rank;
	string captain;

public:

	// following 3 are constructors
	CricketTeam();
	CricketTeam(string , int );
	CricketTeam(string );

	// setter functions
	void setCaptain(string );
	void setRank(int );
	void setTeamName(string );
	void setNoOfMembers(int );
	void allocateMemory(int );

	// getter functions
	string getCaptain();
	int getRank();
	string getTeamName();
	int getNoOfMembers();

	void inputTeamMember(string );
	void inputScore(int );
	float averageOf10Matches();
	void latestScore();
	void printTeam();
	bool teamComparison(CricketTeam );

	~CricketTeam(); // destructor
};
