/*

	Made by Emil Zackrisson

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <shellapi.h>
#include <time.h> 
using namespace std;

void start(int& moves, bool inv[3]); // Default start point
void printStat(int& moves, bool inv[3]); // Prints Moves and keys
void room1(int& moves, bool inv[3]); // Room with door to boss
void room2(int& moves, bool inv[3]); // Old man riddle
void room3(int& moves, bool inv[3]); // Doors to room4 & 6
void room4(int& moves, bool inv[3]); // Goblin room
void goblinGame(int& moves, bool inv[3]); // Dice game against Goblin
void room5(int& moves, bool inv[3]); // Painting with king
void room6(int& moves, bool inv[3]); // Chest room
void roomBoss(int& moves, bool inv[3]); // Boss Room
void printHealth(int& bossHealth, int& playerHealth); //Prints health of player and boss
void bossHit(int& bossHealth, int& playerHealth); // Player hits boss
void bossSwing(int& bossHealth, int& playerHealth); // Boss tries to hit player
void escape(); // Escape boss room
void gameover(); // Gameover, player died
void print(string text); // Skriver bara ut text fränt


int main()
{
	setlocale(LC_ALL, "");
	bool inv[3];
	/*
	inv[0]: Needs to open chest in room 6. Players gets it from Goblin
	inv[1]: Needs to open boss door. Player gets it from Chest in room 6.
	inv[2]: Sword to fight boss. Player gets it from Chest in room 6.
	*/
	int moves = 0;


	//Allows dev to jump to room and get the right keys
	int devRoomTest = 0; // 0 As standard
	if (devRoomTest == 0) // Start room
	{
		print("Where am I?");
		Sleep(100);
		print("I think I am in a hallway.");
		Sleep(100);
		print("It's dark and I hear an echo from my breath, I hope it's mine anyway.");
		start(moves, inv);
	}
	else if (devRoomTest == 1) // Room 1
	{
		room1(moves, inv);
	}
	else if (devRoomTest == 2) // Room 2
	{
		room2(moves, inv);
	}
	else if (devRoomTest == 3) // Room 3
	{
		room3(moves, inv);
	}
	else if (devRoomTest == 4) // Room 4
	{
		room4(moves, inv);
	}
	else if (devRoomTest == 5) // Room 5
	{
		room5(moves, inv);
	}
	else if (devRoomTest == 6) // Room 6
	{
		inv[0] = true; // Gives dev chest key
		room6(moves, inv);
	}
	else if (devRoomTest == 7) {
		inv[1] = true; // Gives dev boss key
		roomBoss(moves, inv);
	}
	else if (devRoomTest == 8) {
		print("Hello World!");
	}
	else // If devRoomTest has an invald value
	{
		cout << "devRoomTest invalid value";
		cout << "Check the value and try again.";
	}

}

void start(int& moves, bool inv[3])
{
	string input;
	moves++;
	cout << ">";
	getline(cin, input);

	if (input == "read letter") {
		print("I pick up the letter and it says: ");
		print("Hello. You are locked in a house in a big, dark forest. I don't think you will be able to escape, but if you against all odds escape anyway, I will not stop you. Might be others who will tho.");
		print("How to play:");
		print("You type what you want to do, ex \"open right door\", \"look\", \"help\" ");
		printStat(moves, inv);
		start(moves, inv);

	}
	else if (input == "look")
	{
		print("I am in a dark hallway. There is a letter on the floor. There is a door forward, to the right, left and behind.");
		printStat(moves, inv);
		start(moves, inv);

	}
	else if (input == "open door")
	{
		print("Open what door?");
		printStat(moves, inv);
		start(moves, inv);
	}
	else if (input == "open forward door") // Room 1 (Room to boss)
	{
		system("CLS");
		room1(moves, inv);
	}
	else if (input == "open left door") // Room 4 (Goblin room)
	{
		system("CLS");
		room4(moves, inv);
	}
	else if (input == "open right door") //Room 2 (Riddle room)
	{
		system("CLS");
		room2(moves, inv);
	}
	else if (input == "open door behind") //Room 3
	{
		system("CLS");
		room3(moves, inv);
	}
	else if (input == "help")
	{
		print("look, read letter, open forward door, open right door, open left door, open door behind");
		start(moves, inv);
	}
	else
	{
		print("Hmmmm. I didn't understand that...");
		start(moves, inv);
	}
}

void printStat(int& moves, bool inv[3]) //Prints out the stats
{
	int keys = 0;
	for (int i = 0; i < 3; i++)
	{
		if (inv[i] == true)
		{
			keys++;
		}
	}
	cout << endl << "Keys: " << keys << " Moves: " << moves << endl;
}

void room1(int& moves, bool inv[3]) // Room with door to boss room
{
	moves++;
	printStat(moves, inv);
	print("There is a door");
	string input;
	cout << "> ";
	getline(cin, input);
	if (input == "open door")
	{
		if (inv[1] == true && inv[2] == true)
		{
			system("CLS");
			print("There is a sign on the door.");
			print("\"Dragon Room\"");
			print("That sounds scary, should I go in anyway?");
			string input;
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				roomBoss(moves, inv);
			}
			else
			{
				system("CLS");
				room1(moves, inv);
			}
		}
		else
		{
			print("The door is locked...");
			printStat(moves, inv);
			room1(moves, inv);

		}
	}
	else if (input == "back")
	{
		system("CLS");
		start(moves, inv);

	}
	else if (input == "help")
	{
		print("back, open door");
		room1(moves, inv);
	}
	else
	{
		print("Hmmm.. I didn't understand that..");
		room1(moves, inv);
	}
}

void room2(int& moves, bool inv[3])
{
	//Old man riddle
	moves++;
	printStat(moves, inv);
	string input;

	print("It's a old man sitting in the room.");
	cout << "> ";
	getline(cin, input);
	if (input == "look")
	{
		print("It's a old man in the room. There is a door to the right.");
		moves++;
		room2(moves, inv);
	}
	else if (input == "help")
	{
		print("look, back, open right door, talk to old man");
		room2(moves, inv);
	}
	else if (input == "open right door")
	{
		system("CLS");
		room6(moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		start(moves, inv);
	}
	else if (input == "talk to old man")
	{
		print("\"Hello there, I have a riddle for you.\"");
		print("\"If you get it right, you get a key\"");
		print("\"Are you ready?\"");
		cout << "> ";
		getline(cin, input);
		if (input == "yes")
		{
			print("\"The more of this there is, the less you see. What is it?\"");
			cout << "> ";
			getline(cin, input);
			if (input == "darkness")
			{

				print("\"Good.. Good. That's right. Remember that, you will need it later.\"");
				room2(moves, inv);
			}
			else
			{
				print("\"That was not the right answer, try again some other time.\"");
				room2(moves, inv);
			}
		}
		else
		{

			room2(moves, inv);
		}
	}
	else
	{
		print("\"Hmm.. I didn't understand that.\"");
	}
}

void room3(int& moves, bool inv[3])
{
	//A middle room to room 4 and 6
	moves++;
	printStat(moves, inv);
	string input;

	print("I am in a dark room with three doors.");
	cout << "> ";
	getline(cin, input);
	if (input == "look")
	{
		print("There is a door in front of me.");
		print("There is a door to the right.");
		print("There is a door behind me.");
		room3(moves, inv);
	}
	else if (input == "help")
	{
		print("look, open right door, open forward door, back");
		room3(moves, inv);
	}
	else if (input == "open right door")
	{
		//To room 5. Needs key from room 4 (goblin).
		if (inv[0] == true)
		{
			system("CLS");
			room5(moves, inv);
		}
		else
		{
			print("The door is locked. I need to find the key.");
			room3(moves, inv);
		}
	}
	else if (input == "open forward door")
	{
		system("CLS");
		room6(moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		start(moves, inv);
	}
	else
	{
		print("I didn't understand that..");
		room3(moves, inv);
	}
}

void room4(int& moves, bool inv[3])
{
	//Goblinroom
	moves++;
	printStat(moves, inv);
	string input;
	print("There is a goblin here.");
	cout << "> ";
	getline(cin, input);
	if (input == "talk to goblin")
	{
		if (inv[0] == true)
		{
			print("\"You alreade beat me. GO AWAY!\"");
			_getch(); // Wait for keypress from user, gives error but thats normal.
			system("CLS");
			room4(moves, inv);
		}
		moves++;
		print("\"Greetings. I expect you are looking for a key, is that right?\"");
		cout << "> ";
		getline(cin, input);
		if (input == "yes")
		{
			print("\"You and I will play a little game. If you roll a higher than me, you get the key. But if i get the higher number, I win and you don't get the key.\"");
			print("\"Are you ready ?\"");
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(moves, inv);
			}
			else
			{
				print("\"Then come back when you are ready to be beaten.\"");
				room4(moves, inv);
			}
		}
		else
		{
			print("\"Bye then.\"");
			room4(moves, inv);
		}
	}
	else if (input == "help")
	{
		print("talk to goblin, back");
		room4(moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		start(moves, inv);
	}
	else
	{
		print("I didn't understand that..");
		room4(moves, inv);
	}

}

void goblinGame(int& moves, bool inv[3])
{
	//Game against goblin
	moves++;
	printStat(moves, inv);
	string input;

	srand(time(NULL));
	int playerRand = rand() % 6 + 1;
	srand(time(NULL) + 10);
	int goblinRand = rand() % 6 + 1;

	print("Roll dice?");
	cout << "> ";
	getline(cin, input);
	if (input == "yes")
	{
		if (playerRand > goblinRand)
		{
			string print_text;
			inv[0] = true; // Gives player key to chest

			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);

			print(print_text);
			print("YOU WON!");

			print("\"I see.. You won.. I promised to give you the key, so here you have it.. NOW LEAVE!!!\"");
			print("Leave?");
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				room4(moves, inv);
			}
			else
			{
				print("You got kicked out.");
				_getch();
				room4(moves, inv);
			}
		}
		else if (playerRand < goblinRand)
		{
			string print_text;
			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);
			print(print_text);
			print("You lost.");

			print("\"HAHA! I WON! YOU DON'T GET THE KEY! BETTER LUCK NEXT TIME! NOT!!\"");
			print("Try again?");
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(moves, inv);
			}
			else
			{
				room4(moves, inv);
			}
		}
		else if (playerRand == goblinRand)
		{
			string print_text;
			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);
			print(print_text);
			print("It's a tie.");
			print("Try again?");
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(moves, inv);
			}
			else
			{
				room4(moves, inv);
			}
		}
		else
		{
			cout << "Error. Oh no! My game! It's broken!" << endl;
			cout << "> ";
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(moves, inv);
			}
			else
			{
				room4(moves, inv);
			}
		}
	}
	else
	{
		system("CLS");
		room4(moves, inv);
	}

}

void room5(int& moves, bool inv[3])
{
	//King with blue torch
	moves++;
	printStat(moves, inv);
	string input;

	print("I am in a big empty room with a painting on the wall.");
	cout << "> ";
	getline(cin, input);
	if (input == "look")
	{
		print("There is a painting on the wall.");
		room5(moves, inv);
	}
	else if (input == "help")
	{
		print("look, look at painting, back");
		room5(moves, inv);
	}
	else if (input == "look at painting")
	{
		print("There is a king with a blue torch.");
		room5(moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		room3(moves, inv);
	}
	else
	{
		print("I didn't understand that..");
		room5(moves, inv);
	}
}

void room6(int& moves, bool inv[3])
{
	//A chest with key from room 4 and the answer from room 2 and the color of torch
	moves++;
	printStat(moves, inv);
	string input;
	print("There is a chest.");
	cout << "> ";
	getline(cin, input);
	if (input == "look")
	{
		print("There is a chest. There is a door to the left.");
		room6(moves, inv);
	}
	else if (input == "help")
	{
		print("open chest, back");
		room6(moves, inv);
	}
	else if (input == "open left door")
	{
		room2(moves, inv);
	}
	else if (input == "back")
	{
		system("CLS");
		room3(moves, inv);
	}
	else if (input == "open chest")
	{
		if (inv[0] = true)
		{
			print("What was the color of the torch?");
			cout << "> ";
			getline(cin, input);
			if (input == "blue")
			{
				print("What was the answer to the old mans riddle?");
				cout << "> ";
				getline(cin, input);
				if (input == "darkness")
				{
					print("Thats right, you got a key and a sword.");
					inv[1] = true; // Gives key to boss room.
					inv[2] = true; // Gives player sword.
					room6(moves, inv);
				}
				else
				{
					print("That was not right, go back to the man and remember the answer next time.");
					_getch();
					system("CLS");
					room6(moves, inv);
				}


			}
			else
			{
				print("That's the wrong answer...");
				room6(moves, inv);
			}

		}
		else
		{
			print("You need a key");
			room6(moves, inv);
		}
	}
	else
	{
		print("Hmm. I didn't understand.");
		room6(moves, inv);
	}
}

void roomBoss(int& moves, bool inv[3])
{
	//Boss room
	moves++;
	int bossHealth = 100;
	int playerHealth = 100;
	string input, health;
	printHealth(bossHealth, playerHealth);
	print("I am in a room with a sleeping dragon.");
	print("Behind the dragon is a door.");
	print("I pull out my sword.");
	print("Should I hit the dragon?");
	cout << "> ";
	getline(cin, input);
	if (input == "yes")
	{
		while ((playerHealth > 0) || (bossHealth > 0))
		{
			bossSwing(bossHealth, playerHealth);
			if (playerHealth <= 0)
			{
				gameover();
			}
			Sleep(3000);
			system("CLS");
			printHealth(bossHealth, playerHealth);

			bossHit(bossHealth, playerHealth);
			if (bossHealth <= 0)
			{
				escape();
			}
			Sleep(3000);
			system("CLS");
			printHealth(bossHealth, playerHealth);


		}

		if (bossHealth <= 0)
		{
			print("I killed the dragon.");
		}
		if (playerHealth <= 0)
		{
			print("You died...");
		}

	}
	else
	{
		start(moves, inv);
	}

}

void printHealth(int& bossHealth, int& playerHealth)
{
	cout << "Your health= " << playerHealth << endl << "Dragon Health= " << bossHealth << endl << endl;
}

void bossHit(int& bossHealth, int& playerHealth)
{
	string input;
	print("Hit the dragon?");
	cout << "> ";
	getline(cin, input);
	if (input == "yes")
	{
		print("You hit the dragon.");
		bossHealth = bossHealth - 30;

		if (bossHealth <= 0) // Boss Killed
		{
			escape(); 
		}
		if (playerHealth <= 0) { // Player Died
			gameover();
		}


	}
	else
	{
		// Does nothing, just goes back to fight.
	}

}

void bossSwing(int& bossHealth, int& playerHealth)
{
	string input;
	print("The Dragon swings it tails and tries to hit you. Jump!");
	cout << "> ";
	getline(cin, input);
	if (input != "jump")
	{
		playerHealth = playerHealth - 40;
	}

}

void escape()
{
	string input;
	print("YOU KILLED THE DRAGON! TRY TO ESCAPE!");
	cout << "> ";
	getline(cin, input);
	if (input == "escape")
	{
		print("I escaped. You beat the game. Congratulations.");
		Sleep(5000);
		exit(0);
	}
}

void gameover()
{
	print("Game Over! You died.");
	exit(0);
}

void print(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
		Sleep(30);
	}
	cout << endl;
}

