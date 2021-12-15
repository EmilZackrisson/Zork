#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void start(int& keys, int& moves, bool inv[10]);
void printStat(int& keys, int& moves);
void room1(int& keys, int& moves, bool inv[10]);
void room2(int& keys, int& moves, bool inv[10]);
void room3(int& keys, int& moves, bool inv[10]);
void room4(int& keys, int& moves, bool inv[10]);
void room5(int& keys, int& moves, bool inv[10]);
void room6(int& keys, int& moves, bool inv[10]);
void roomBoss(int& keys, int& moves, bool inv[10]);

int main()
{
	setlocale(LC_ALL, "");
	bool inv[10];
	int keys = 0, moves = 0;
	printStat(keys, moves);
	cout << "A monster has locked you in an abandoned house. You need to kill the monster to escape." << endl << ">";
	start(keys, moves, inv);
}

void start(int& keys, int& moves, bool inv[10])
{
	string input;

	getline(cin, input);

	if (input == "read letter") {
		cout << "Zork is a text based adventure game." << endl << "Instructions:" << endl << "You type what you wanna do in the game, ex \"open right door\", \"look\", \"help\"";
		moves++;
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "look")
	{
		cout << "You are in the hallway. There is a letter in front of you. There is a door in front of you, to your right, to your left and behind you.";
		moves++;
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "open door")
	{
		cout << "Open what door???";
		moves++;
		printStat(keys, moves);
		start(keys, moves, inv);
	}
	else if (input == "open forward door")
	{
		system("CLS");
		moves++;
		room1(keys, moves, inv);
	}
	else if (input == "open right door")
	{
		system("CLS");
		moves++;
		room2(keys, moves, inv);
	}
	else if (input == "help")
	{
		cout << "look, read letter, open forward door, open right door" << endl;
		start(keys, moves, inv);
	}
	else
	{
		cout << "Hmmmm. I didn't understand that..." << endl;
		start(keys, moves, inv);
	}
}

void printStat(int& keys, int& moves)
{
	cout << endl << "Keys: " << keys << " Moves: " << moves << endl;
}

void room1(int& keys, int& moves, bool inv[10])
{
	printStat(keys, moves);
	cout << "There is a door.." << endl << "> ";
	string input;
	getline(cin, input);
	if (input == "open door")
	{
		if (inv[0] == true)
		{
			system("CLS");
			cout << "This is a boss room, are you sure you want to go in???" << endl;
			string input;
			getline(cin, input);
			if (input == "yes")
			{
				moves++;
				system("CLS");
				roomBoss(keys, moves, inv);
			}
			else
			{
				system("CLS");
				moves++;
				room1(keys, moves, inv);
			}
		}
		else
		{
			cout << "The door is locked... You need to find a key.";
			moves++;
			printStat(keys, moves);
			start(keys, moves, inv);
		}
	}
	else if (input == "back")
	{
		moves++;
		system("CLS");
		start(keys, moves, inv);

	}
	else if (input == "help")
	{
		cout << "back, open door";
		room1(keys, moves, inv);
	}
	else
	{
		cout << "Hmmm.. I didn't understand that..";
		room1(keys, moves, inv);
	}
}

void room2(int& keys, int& moves, bool inv[10])
{

	moves++;
	printStat(keys, moves);
	string input;

	cout << "You found a old man in the room." << endl;
	getline(cin, input);
	if (input == "look")
	{
		cout << "It's a old man in the room. There is a door to your right." << endl;
		moves++;
		room2(keys, moves, inv);
	}
	else if (input == "help")
	{
		cout << "look, back, open right door, talk to old man" << endl;
		moves++;
		room2(keys, moves, inv);
	}
	else if (input == "open right door")
	{
		system("CLS");
		moves++;
		room6(keys, moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		moves++;
		start(keys, moves, inv);
	}
	else if (input == "talk to old man")
	{

		cout << "Hello there, I have a riddle for you." << endl;
		cout << "If you get it right, you get a key" << endl;
		cout << "Are you ready?" << endl;
		getline(cin, input);
		if (input == "yes")
		{
			cout << "The more of this there is, the less you see. What is it?" << endl;
			getline(cin, input);
			if (input == "darkness")
			{
				moves++;
				cout << "Good.. Good. That's right. Remember that, you will need it later." << endl;
				room2(keys, moves, inv);
			}
			else
			{
				moves++;
				cout << "That was not the right answer, try again some other time." << endl;
				room2(keys, moves, inv)
			}
		}
		else
		{
			moves++;
			room2(keys, moves, inv);
		}
	}
	else
	{
		cout << "Hmm... I didn't understand.";
		room2(keys, moves, inv);
	}
}

void room3(int& keys, int& moves, bool inv[10])
{
}

void room4(int& keys, int& moves, bool inv[10])
{
	printStat
}

void room5(int& keys, int& moves, bool inv[10])
{
}

void room6(int& keys, int& moves, bool inv[10])
{
}

void roomBoss(int& keys, int& moves, bool inv[10])
{
}