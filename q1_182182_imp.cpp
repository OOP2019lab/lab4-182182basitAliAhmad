#include "CricketTeam.h"

CricketTeam::CricketTeam() // default constructor
{
	memberNames = nullptr;
	noOfMembers = 11;
	teamName = nullptr;
	for (int i = 0; i < 10; i++)
		scoreInLast10Matches[i] = -1;
	rank = 0;
	captain = "null";
}

CricketTeam::CricketTeam(string teamName, int noOfMembers) // 2 parameter constuctor
{
	int size = strlen(teamName.c_str());
	CricketTeam::teamName = new char[size];
	strcpy_s(CricketTeam::teamName,size,teamName.c_str());

	CricketTeam::noOfMembers = noOfMembers;

}

CricketTeam::CricketTeam(string fileName) // filing constructor
{
	ifstream fin;
	fin.open(fileName);
	if(fin)
	{
		string temp;
		getline(fin,temp,':'); // ignoring until ':'

		getline(fin,temp,'\n'); // input until '\n'
		teamName = new char[sizeof(temp)];
		strcpy_s(teamName,sizeof(temp),temp.c_str()); // copying from string to char array

		getline(fin,temp,':');
		fin >> noOfMembers;
		
		memberNames = new string[noOfMembers];
		fin.ignore();
		for (int i = 0; i < noOfMembers; i++)
			getline(fin,memberNames[i],'\n');
	
		getline(fin,temp,':');
		fin >> rank;

		getline(fin,temp,':');
		getline(fin,captain,'\n');

		getline(fin,temp,':');
		for (int i = 0; i < 10; i++)
			fin >> scoreInLast10Matches[i];

		fin.close();
	}
	else
		cout << "file not found!" << endl;
}


// following 5 are setter functions
void CricketTeam::setCaptain(string temp)
{
	captain = temp;
}

void CricketTeam::setRank(int temp)
{
	rank = temp;
}

void CricketTeam::setTeamName(string temp)
{
	int size = strlen(temp.c_str());
	size++;
	teamName = new char[size];

	strcpy_s(teamName,size,temp.c_str());
}

void CricketTeam::setNoOfMembers(int temp)
{
	noOfMembers = temp;
}

void CricketTeam::allocateMemory(int var) // allocates memory and creates array against memberNames
{
	memberNames = new string[var];
	for (int i = 0; i < var; i++)
		memberNames[i] = "yo";
}

// following 4 functions are getter functions
string CricketTeam::getCaptain()
{
	return captain;
}

int CricketTeam::getRank()
{
	return rank;
}

string CricketTeam::getTeamName()
{
	return (string)teamName;
}

int CricketTeam::getNoOfMembers()
{
	return noOfMembers;
}

void CricketTeam::inputTeamMember(string name) // sunction to store player name in the array
{
	int i;
	for (i = 0; i < noOfMembers; i++)
	{
		if (memberNames[i] == "yo")
		{
			memberNames[i] = name;
			i = 2*noOfMembers;
		}
	}

	if (i == noOfMembers)
		cout << "404! There is no place for new member" << endl;

}

void CricketTeam::inputScore(int score) // function to store latest scores of a team in an array
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (scoreInLast10Matches[i] == -1)
		{
			scoreInLast10Matches[i] = score;
			i = 10;
		}
		
	}
	if (i == 10)
	{
		for (i = 0; i < 9; i++)
			scoreInLast10Matches[i] = scoreInLast10Matches[i+1];

		scoreInLast10Matches[i] = score;
	}


}

float CricketTeam::averageOf10Matches() // function calculates the average of the scores of latest matches
{
	float sum = 0;
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (scoreInLast10Matches[i] != -1)
		{
			sum += scoreInLast10Matches[i];
			count++;
		}
	}
	return sum/(float)count;
}

void CricketTeam::latestScore() // printing latest score of the team with team name and captain name
{
	for (int i = 9; i >= 0; )
	{
		if(scoreInLast10Matches[i] == -1)
			i--;
		else
		{
			cout << "Team name: " << teamName << endl;
			cout << "Captain name: " << captain << endl;
			cout << "Latest score: " << scoreInLast10Matches[i] << endl;
		} 
	}
}

void CricketTeam::printTeam() // prints whole parameters of the team
{
	cout << "Team name: " << teamName << endl;
	cout << "Captain name: " << captain << endl;
	cout << "Total members: " << noOfMembers << endl;
	cout << "Rank: " << rank << endl;
	for (int i = 0; i < noOfMembers; i++)
		cout << "Player # " << i+1 << " : " << memberNames[i] << endl;
	cout << "Scores in most recent matches are :" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (scoreInLast10Matches[i] != -1)
			cout << scoreInLast10Matches[i] << " ";
	}
	cout << endl;
}

bool CricketTeam::teamComparison(CricketTeam sam) // compares two teams and return true or false
{
	float avg1 = averageOf10Matches();
	float avg2 = sam.averageOf10Matches();
	if (avg1 > avg2)
		return true;
	return false;
}

CricketTeam::~CricketTeam() // destructor to deallocate the heap memory.
{
	delete[]memberNames;
	memberNames = nullptr;

	delete[]teamName;
	teamName = nullptr;
}
