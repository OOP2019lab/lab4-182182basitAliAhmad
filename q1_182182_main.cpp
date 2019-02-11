#include "CricketTeam.h"

void main()
{
	string filename = "Pakistan.txt", temp; // temp for taking input from console
	int num = 0; // as above
	CricketTeam Pakistan(filename);
	CricketTeam otherTeam;

	cout << "Enter name of your team ----> ";
	getline(cin,temp); // first storing in temporary variable.
	otherTeam.setTeamName(temp); // using setter to set values

	cout << "What is the rank of this team ----> ";
	cin >> num;
	otherTeam.setRank(num);

	cin.ignore();
	cout << "Enter name of team captain ----> ";
	getline(cin,temp);
	otherTeam.setCaptain(temp);

	cout << "How many members of this team (including captain) ----> ";
	cin >> num;
	otherTeam.setNoOfMembers(num);

	otherTeam.allocateMemory(otherTeam.getNoOfMembers()); // creating array of player's name.

	otherTeam.inputTeamMember(otherTeam.getCaptain()); // adding captain's name in player's list
	cin.ignore();
	for (int i = 1; temp != "null"; i++) // "null" is the delimiter to stop accepting values.
	{
		cout << "enter \"null\" to stop entering names:\t";
		cout << "Enter name of player : " << i + 1 << " ----> ";
		getline(cin,temp);
		if (temp != "null") // stoping code to store "null in the array"
			otherTeam.inputTeamMember(temp);
	}
		

	while (num != -1)
	{
		cout << "Enter \"-1\" to stop entering!\t";
		cout << "Enter score in latest matches ----> ";
		cin >> num;
		if(num != -1) // stoping code to store -1 in array
			otherTeam.inputScore(num);
	}

	cout << "The better team is as follow:" << endl << endl;
	if(Pakistan.teamComparison(otherTeam)) // comparison. true if Pakistan is better.
		Pakistan.printTeam();
	else
		otherTeam.printTeam();
}
