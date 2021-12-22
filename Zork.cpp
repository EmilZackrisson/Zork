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
	cout << "A monster has locked you in an abandoned house. You need to kill the monster to escape." << endl;
	start(keys, moves, inv);

	//Allows dev to jump to room
	int devRoomTest = 6;
	if (devRoomTest == 0) // Start room
	{
		start(keys, moves, inv);
	}
	if (devRoomTest == 1) // Room 1
	{
		room1(keys, moves, inv);
	}
	if (devRoomTest == 2) // Room 2
	{
		room2(keys, moves, inv);
	}
	if (devRoomTest == 3) // Room 3
	{
		room3(keys, moves, inv);
	}
	if (devRoomTest == 4) // Room 4
	{
		room4(keys, moves, inv);
	}
	if (devRoomTest == 5) // Room 5
	{
		room5(keys, moves, inv);
	}
	if (devRoomTest == 6) // Room 6
	{
		room6(keys, moves, inv);
	}
	else
	{
		cout << "devRoomTest invalid value";
	}
	
}

void start(int& keys, int& moves, bool inv[10])
{
	string input;
	moves++;
	cout<<"You're in the hallway." <<endl << ">";
	getline(cin, input);

	if (input == "read letter") {
		cout << "Zork is a text based adventure game." << endl << "Instructions:" << endl << "You type what you wanna do in the game, ex \"open right door\", \"look\", \"help\"";
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "look")
	{
		cout << "You are in the hallway. There is a letter in front of you. There is a door in front of you, to your right, to your left and behind you.";
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "open door")
	{
		cout << "Open what door???";
		printStat(keys, moves);
		start(keys, moves, inv);
	}
	else if (input == "open forward door") // Room 1 (Room to boss)
	{
		system("CLS");
		room1(keys, moves, inv);
	}
	else if (input == "open left door") // Room 4 (Goblin room)
	{
		system("CLS");
		room4(keys, moves, inv);
	}
	else if (input == "open right door") //Room 2 (Riddle room)
	{
		system("CLS");
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

void printStat(int& keys, int& moves) //Prints out the stats
{
	cout << endl << "Keys: " << keys << " Moves: " << moves << endl;
}

void room1(int& keys, int& moves, bool inv[10])
{
	moves++;
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
				system("CLS");
				roomBoss(keys, moves, inv);
			}
			else
			{
				system("CLS");
				room1(keys, moves, inv);
			}
		}
		else
		{
			cout << "The door is locked... You need to find a key.";
			printStat(keys, moves);
			start(keys, moves, inv);
		}
	}
	else if (input == "back")
	{
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
	//Old man riddle
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
		room2(keys, moves, inv);
	}
	else if (input == "open right door")
	{
		system("CLS");
		room6(keys, moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
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
				
				cout << "Good.. Good. That's right. Remember that, you will need it later." << endl;
				room2(keys, moves, inv);
			}
			else
			{
				
				cout << "That was not the right answer, try again some other time." << endl;
				room2(keys, moves, inv);
			}
		}
		else
		{
			
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
	//A middle room to room 4 and 6
	moves++;
	printStat(keys, moves);
	string input;

	cout << "You are in a empty room with three doors." << endl;
	getline(cin, input);
	if (input == "look")
	{
		cout << "There is a door in front of you. \n There is a door to your right. \n There is a door behind you.\n";
		room3(keys, moves, inv);
	}
	if (input == "help")
	{
		cout << "look, open door right, open door forward, open door back" << endl;
		room3(keys, moves, inv);
	}
	if (input=="open door right")
	{
		//To room 5. Needs key from room 4.
		if (keys == 1)
		{
			system("CLS");
			room5(keys, moves, inv);
		}
		else
		{
			cout << "It's locked, you need to find the key." << endl;
			room3(keys, moves, inv);
		}
	}
	if (input == "open door forward")
	{
		system("CLS");
		room6(keys, moves, inv);
	}
}

void room4(int& keys, int& moves, bool inv[10])
{
	//Game against goblin
}

void room5(int& keys, int& moves, bool inv[10])
{
	//King with blue torch
	moves++;
	printStat(keys, moves);
	string input;

	cout << "You are in a empty room with a painting on the wall." << endl;
	getline(cin, input);
	if (input=="look")
	{
		cout << "There is a painting on the wall." << endl;
		room5(keys, moves, inv);
	}
	if (input == "help")
	{
		cout << "look, look at painting, back" << endl;
		room5(keys, moves, inv);
	}
	if (input == "look at painting")
	{
		cout << "There is a king with a blue torch." << endl;
		room5(keys, moves, inv);
	}
	if (input == "back")
	{
		system("CLS");
		room3(keys, moves, inv);
	}
}

void room6(int& keys, int& moves, bool inv[10])
{
	//A chest with key from room 4 and the answer from room 2 and the color of torch

}

void roomBoss(int& keys, int& moves, bool inv[10])
{
	//Boss room
}