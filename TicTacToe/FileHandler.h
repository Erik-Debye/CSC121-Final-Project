#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Define class
class  FileHandler {
public:
	FileHandler() {
		//insertpairs into Map when class initialized
		records.insert(pair<string, int>("Games", 0));
		records.insert(pair<string, int>("Player", 0));
		records.insert(pair<string, int>("Computer", 0));
		records.insert(pair<string, int>("Ties", 0));
	}

	//methods
	void setRecord(string str, int value) {
		records.at(str) = value;
	}
	int getRecord(string str) {
		return records.at(str);
	}

	void fileMoves(string player, string num, vector<string> square) {
		//Assign player to the correct title dependant on letter being switched for number in ConvertToXO().
		if (player == "X") {
			player = "Player";
		}
		else {
			player = "Computer";
		}

		//open file to append
		fstream file("gamePlays.txt", ios::app);

		//check if file opened
		if (!file) {
			cerr << "\n\tError opening file";
			exit(EXIT_FAILURE);
		}

		//write play to file
		file << "\n\t" << player << " chose " << num << "!";
		file << "\n\tCurrent State of Squares:";

		//create accum to track index
		int i = 0;
		for (string item : square) {
			//aligns square
			if (i == 3 || i == 6) {
				file << "\n\t\t\t\t       ";
			}
			//prints item
			file << " " << item;
			i++;
		}

		//close file
		file.close();
	}

	void fileOutcome(string outcome) {
		//open file to append
		fstream file("gamePlays.txt", ios::app);

		//check if file opened
		if (!file) {
			cerr << "\n\tError opening file";
			exit(EXIT_FAILURE);
		}

		file << "\n" << outcome << "\n\n";

		//close file
		file.close();
	}



	void fileSummary() {
		//opening file for writing
		fstream writing("TTTWins.txt", ios::out);

		//check if file is open 
		if (!writing) {
			cerr << "\n\tError opening file.";
			exit(EXIT_FAILURE);
		}

		//write data into file
		writing << "Games played: " << getRecord("Games") << "\n";
		writing << "Player Wins: " << getRecord("Player") << "\n";
		writing << "Player Losses: " << (getRecord("Games") - getRecord("Player") - getRecord("Ties")) << "\n";
		writing << "Computer Wins: " << getRecord("Computer") << "\n";
		writing << "Computer Losses: " << (getRecord("Games") - getRecord("Computer") - getRecord("Ties")) << "\n";
		writing << "Ties: " << getRecord("Ties") << "\n";

		//close file
		writing.close();
	}

	void getSummary() const {
		//create empty string (used to store file lines)
		string fileLn{ "" };

		//open file for reading
		fstream fileData("TTTWins.txt", ios::in);
		//check if file opened
		if (!fileData) {
			cerr << "Error opening file.";
			exit(EXIT_FAILURE);
		}
		//print title
		cout << "\n\n\tGames Summary\n\n";
		//print each line in file by line - getline() checks for eof && '\n' - source: https://www.cplusplus.com/reference/string/string/getline/
		while (getline(fileData, fileLn)) {
			cout << "\t" << fileLn << "\n";
		}
	}



private:
	//define a Map (key-value pair list structure)
	//source: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
	map<string, int> records;
};
