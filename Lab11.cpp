/*
* File: Lab11.cpp
* Author : Braylon Rieman
* Date : 11 / 14 / 2024
*
* Description : Lab 11 Jet plane
*
*/

#include <iostream>
#include <string>
using namespace std;

//constants
const int ROWS = 14;
const int COLUMNS = 5;

//function prototypes
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

int main(void)
{
	//variables
	char array[COLUMNS][ROWS];
	char inputChar;
	int inputInt;
	int row;
	int column;
	
	//fill array
	for (int row = 1; row < ROWS; row++)
	{
		for (int column = 1; column < COLUMNS; column++)
		{
			if (row == 13 && (column == 1 || column == 2))
				array[column][row] = ' ';
			else
				array[column][row] = (char)(69 - column);
		}
	}

	while (true)
	{
		//output array
		for (int column = 1; column < COLUMNS; column++)
		{
			displaySeatColumn(array, column);
			cout << endl;
		}
		cout << endl;

		//input
		while (true)
		{
			cout << "Enter a seat or Q to quit: ";
			cin >> inputInt >> inputChar;
			if (cin.fail())
				return(0);

			//checks if input is valid
			row = findRowIndex(inputInt);
			column = findSeatIndex(inputChar);
			if (row == -1 || column == -1 || array[5 - column][row] == 'X')
				cout << "Invalid seat.  Please try again.\n";
			else if(row == 13 && column == 4)
				cout << "Invalid seat.  Please try again.\n";
			else if (row == 13 && column == 3)
				cout << "Invalid seat.  Please try again.\n";
			else
				break;
		}

		//sets the seat to X
		array[5 - column][row] = 'X';
		cout << endl;
	}
}

int findRowIndex(int thisRow)
{
	if (thisRow >= 1 && thisRow < ROWS)
		return(thisRow);
	else
		return(-1);
}

int findSeatIndex(char thisSeat)
{
	int column = thisSeat - 64;
	if (column >= 1 && column < COLUMNS)
		return(column);
	else
		return(-1);
}

void displaySeatColumn(char seats[][ROWS], int column)
{
	//output array
	for (int row = 1; row < ROWS; row++)
	{
		cout << seats[column][row] << " ";
		if (column == 2 && row == 13)
		{
			cout << endl << endl;
			for (int row = 1; row < ROWS; row++)
			{
				if (row < 10)
					cout << "  ";
				else
					cout << 1 << " ";
			}
			cout << endl;
			for (int row = 1; row < ROWS; row++)
			{
				if (row < 10)
					cout << row << " ";
				else
					cout << row - 10 << " ";
			}
			cout << endl;
		}
	}
}
