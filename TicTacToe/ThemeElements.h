#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

//Define class
class Themes {
public:
	//use default constructor

	//methods
	//Title
	void header(void) {
		cout << "\n\n\tErik Debye \\ 03.05.2022\n";
		cout << "\tTicTacToe\n";
	}
	//theme colors
	void theme() {
		system("Color B5");
	}

private:
	//define private variables w/ defaults as needed

};