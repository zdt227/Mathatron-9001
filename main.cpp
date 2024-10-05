#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

string player_name;
string scorestring = "score";
int game_start;
int randomnumberA;
int randomnumberB;
int answer = 0;
int score = 0;
int answer_streak = 0;
int difficulty = 1;

fstream HighScores;

void question_sequence_addition(int randomnumberA, int randomnumberB);
void question_sequence_subtraction(int randomnumberA, int randomnumberB);
void question_sequence_multiplication(int randomnumberA, int randomnumberB);
void question_sequence_division(int randomnumberA, int randomnumberB);

int main()
{
	cout << "Welcome to Mathatron 9001!" << endl;
	cout << "Would you like to play..."
	<< "\nAddition - 1\nSubtraction - 2\nMultiplictation - 3\nDivision - 4\nView High scores - 5" << endl;
	cout << "Make your choice: ";
	cin >> game_start;
	
	switch (game_start)
	{
		case 1:
		{
			cout << "Enter your name: ";
			cin.ignore(1000, '\n');
			getline(cin, player_name);
			cout << "You've selected addition. " << endl;
			cout << "Select Difficulty. Easy - 1 Hard - 2: ";
			cin >> difficulty;
			question_sequence_addition(randomnumberA, randomnumberB);
			fstream HighScores;
			HighScores.open("HIGH_SCORES.DAT", ios::app);
			{	
				HighScores << player_name << endl;
				HighScores << score << endl;
			}
			HighScores.close();
			break;
		}
		case 2:
		{
			cout << "Enter your name: ";
			cin.ignore(1000, '\n');
			getline(cin, player_name);
			cout << "You've selected subtraction. " << endl;
			cout << "Select Difficulty. Easy - 1 Hard - 2: ";
			cin >> difficulty;
			question_sequence_subtraction(randomnumberA, randomnumberB);
			fstream HighScores;
			HighScores.open("HIGH_SCORES.DAT", ios::app);
			{
				HighScores << player_name << endl;
				HighScores << score << endl;
			}
			HighScores.close();
			break;
		}
		case 3:
		{
			cout << "Enter your name: ";
			cin.ignore(1000, '\n');
			getline(cin, player_name);
			cout << "You've selected multiplication. " << endl;
			cout << "Select Difficulty. Easy - 1 Hard - 2: ";
			cin >> difficulty;
			question_sequence_multiplication(randomnumberA, randomnumberB);
			fstream HighScores;
			HighScores.open("HIGH_SCORES.DAT", ios::app);
			{
				HighScores << player_name << endl;
				HighScores << score << endl;
			}
			HighScores.close();
			break;
		}
		case 4:
		{
			cout << "Enter your name: ";
			cin.ignore(1000, '\n');
			getline(cin, player_name);
			cout << "You've selected division. " << endl;
			cout << "Select Difficulty. Easy - 1 Hard - 2: ";
			cin >> difficulty;
			question_sequence_division(randomnumberA, randomnumberB);
			fstream HighScores;
			HighScores.open("HIGH_SCORES.DAT", ios::app);
			{
				HighScores << player_name << endl;
				HighScores << score << endl;
			}
			HighScores.close();
			break;
		}
		case 5:
		{
			cout << "High Scores:" << endl;
			fstream HighScores;
			HighScores.open("HIGH_SCORES.DAT", ios::in);
			do
			{
				HighScores >> player_name;
				HighScores >> score;
				if(!HighScores.fail())
				{
					cout << player_name << endl;
					cout << scorestring << ':' << score << endl;
				}
			} 
			while (!HighScores.fail());
			break;
		}	
	}
}

void question_sequence_addition(int randomnumberA, int randomnumberB)
{
	int realanswer = 0;
	int useranswer;
	do
	{
		srand((unsigned)time(0));
		randomnumberA = (rand() % 10) + 1;
		randomnumberA = randomnumberA * difficulty;
		srand((unsigned)time(0));
		randomnumberB = (rand() % 20) + 1;
		randomnumberB = randomnumberB * difficulty;
		realanswer = randomnumberA + randomnumberB;
		cout << "What is " << randomnumberA << '+' << randomnumberB << "? ";
		cin >> useranswer;
		answer_streak++;
		score = answer_streak * 500;
	} while (realanswer == useranswer);
	{
		if (answer_streak == 1)
		{
			answer_streak--;
			score = 0;
		}
		cout << "The correct answer was " << realanswer << '.';
		cout << " Good job, you got " << answer_streak << " answers right for a score of " << score << '.' << endl;
	}
}

void question_sequence_subtraction(int randomnumberA, int randomnumberB)
{
	int realanswer = 0;
	int useranswer;
	do
	{
		srand((unsigned)time(0));
		randomnumberA = (rand() % 20) + 10;
		randomnumberA = randomnumberA * difficulty;
		srand((unsigned)time(0));
		randomnumberB = (rand() % 10) + 1;
		randomnumberB = randomnumberB * difficulty;
		realanswer = randomnumberA - randomnumberB;
		cout << "What is " << randomnumberA << '-' << randomnumberB << "? ";
		cin >> useranswer;
		answer_streak++;
		score = answer_streak * 550;
	} while (realanswer == useranswer);
	{
		if (answer_streak == 1)
		{
			answer_streak--;
			score = 0;
		}
		cout << "The correct answer was " << realanswer << '.';
		cout << " Good job, you got " << answer_streak << " answers right for a score of " << score << '.' << endl;
	}
}

void question_sequence_multiplication(int randomnumberA, int randomnumberB)
{
	int realanswer = 0;
	int useranswer;
	do
	{
		srand((unsigned)time(0));
		randomnumberA = (rand() % 10) + 1;
		randomnumberA = randomnumberA * difficulty;
		srand((unsigned)time(0));
		randomnumberB = (rand() % 10) + 1;
		randomnumberB = randomnumberB * difficulty;
		realanswer = randomnumberA * randomnumberB;
		cout << "What is " << randomnumberA << '*' << randomnumberB << "? ";
		cin >> useranswer;
		answer_streak++;
		score = answer_streak * 600;
	} while (realanswer == useranswer);
	{
		if (answer_streak == 1)
		{
			answer_streak--;
			score = 0;
		}
		cout << "The correct answer was " << realanswer << '.';
		cout << " Good job, you got " << answer_streak << " answers right for a score of " << score << '.' << endl;
	}
}

void question_sequence_division(int randomnumberA, int randomnumberB)
{
	{
		int realanswer = 0;
		int useranswer;
		do
		{
			srand((unsigned)time(0));
			randomnumberA = (rand() % 10) + 5;
			randomnumberA = randomnumberA * 4;
			randomnumberA = randomnumberA * difficulty;
			srand((unsigned)time(0));
			randomnumberB = (rand() % 2) + 2;
			if (randomnumberB == 3)
			{
				randomnumberB = randomnumberB - 1;
			}
			realanswer = randomnumberA / randomnumberB;
			cout << "What is " << randomnumberA << '/' << randomnumberB << "? ";
			cin >> useranswer;
			answer_streak++;
			score = answer_streak * 650;
		} while (realanswer == useranswer);
		{
			if (answer_streak == 1)
			{
				answer_streak--;
				score = 0;
			}
			cout << "The correct answer was " << realanswer << '.';
			cout << " Good job, you got " << answer_streak << " answers right for a score of " << score << '.' << endl;
		}
	}
}

