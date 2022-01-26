#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <shellapi.h>
#include <time.h> 
using namespace std;

void start(int& keys, int& moves, bool inv[10]);
void printStat(int& keys, int& moves);
void room1(int& keys, int& moves, bool inv[10]);
void room2(int& keys, int& moves, bool inv[10]);
void room3(int& keys, int& moves, bool inv[10]);
void room4(int& keys, int& moves, bool inv[10]);
void goblinGame(int& keys, int& moves, bool inv[10]);
void room5(int& keys, int& moves, bool inv[10]);
void room6(int& keys, int& moves, bool inv[10]);
void roomBoss(int& keys, int& moves, bool inv[10]);
void printHealth(int& bossHealth, int& playerHealth);
void bossHit(int& bossHealth, int& playerHealth);
void bossSwing(int& bossHealth, int& playerHealth);
void escape();
void gameover();
void print(string text);


int main()
{
	setlocale(LC_ALL, "");
	bool inv[10];
	int keys = 0, moves = 0;
	

	//Allows dev to jump to room and get the right keys
	int devRoomTest = 0; // 0 As standard
	if (devRoomTest == 0) // Start room
	{
		print("Where am I?");
		Sleep(100);
		print("I think I am in a hallway.");
		Sleep(100);
		print("It's dark and I hear an echo from my breath, I hope it's mine anyway.");
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
	if (devRoomTest == 6) // Room 6 and get the first key
	{
		keys = 1;
		room6(keys, moves, inv);
	}
	if (devRoomTest == 7) {
		keys == 2;
		roomBoss(keys, moves, inv);
	}
	if (devRoomTest == 8) {
		print("Hello World!");
	}
	//else
	//{
		//cout << "devRoomTest invalid value";
	//}
	
}

void start(int& keys, int& moves, bool inv[10])
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
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "look")
	{
		print("I am in a dark hallway. There is a letter on the floor. There is a door forward, to the right, left and behind.");
		printStat(keys, moves);
		start(keys, moves, inv);

	}
	else if (input == "open door")
	{
		print("Open what door?");
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
	else if (input == "open door behind") //Room 3
	{
		system("CLS");
		room3(keys, moves, inv);
	}
	else if (input == "help")
	{
		print("look, read letter, open forward door, open right door, open left door, open door behind");
		start(keys, moves, inv);
	}
	else
	{
		print("Hmmmm. I didn't understand that...");
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
	print("There is a door");
	string input;
	getline(cin, input);
	if (input == "open door")
	{
		if (keys == 2)
		{
			system("CLS");
			print("There is a sign on the door.");
			print("Dragon Room");
			print("That sounds scary, should I go in anyway?");
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
			print("The door is locked...");
			printStat(keys, moves);
			room1(keys, moves, inv);
			
		}
	}
	else if (input == "back")
	{
		system("CLS");
		start(keys, moves, inv);

	}
	else if (input == "help")
	{
		print("back, open door");
		room1(keys, moves, inv);
	}
	else
	{
		print("Hmmm.. I didn't understand that..");
		room1(keys, moves, inv);
	}
}

void room2(int& keys, int& moves, bool inv[10])
{
	//Old man riddle
	moves++;
	printStat(keys, moves);
	string input;

	print("It's a old man sitting in the room.");
	getline(cin, input);
	if (input == "look")
	{
		print("It's a old man in the room. There is a door to the right.");
		moves++;
		room2(keys, moves, inv);
	}
	else if (input == "help")
	{
		print("look, back, open right door, talk to old man");
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
		print("\"Hello there, I have a riddle for you.\"");
		print("\"If you get it right, you get a key\"");
		print("\"Are you ready?\"");
		getline(cin, input);
		if (input == "yes")
		{
			print("\"The more of this there is, the less you see. What is it?\"");
			getline(cin, input);
			if (input == "darkness")
			{
				
				print("\"Good.. Good. That's right. Remember that, you will need it later.\"");
				room2(keys, moves, inv);
			}
			else
			{
				print("\"That was not the right answer, try again some other time.\"");
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
		print("\"Hmm.. I didn't understand that.\"");
	}
}

void room3(int& keys, int& moves, bool inv[10])
{
	//A middle room to room 4 and 6
	moves++;
	printStat(keys, moves);
	string input;

	print("I am in a dark room with three doors.");
	getline(cin, input);
	if (input == "look")
	{
		print("There is a door in front of me.");
		print("There is a door to the right.");
		print("There is a door behind me.");
		room3(keys, moves, inv);
	}
	if (input == "help")
	{
		print("look, open right door, open forward door, back");
		room3(keys, moves, inv);
	}
	if (input=="open right door")
	{
		//To room 5. Needs key from room 4 (goblin).
		if (keys == 1)
		{
			system("CLS");
			room5(keys, moves, inv);
		}
		else
		{
			print("The door is locked. I need to find the key.");
			room3(keys, moves, inv);
		}
	}
	if (input == "open forward door")
	{
		system("CLS");
		room6(keys, moves, inv);
	}
	if (input == "back")
	{
		system("CLS");
		start(keys, moves, inv);
	}
	else
	{
		print("I didn't understand that..");
		room3(keys, moves, inv);
	}
}

void room4(int& keys, int& moves, bool inv[10])
{
	//Goblinroom
	moves++;
	printStat(keys, moves);
	string input;
	print("There is a goblin here.");
	getline(cin, input);
	if (input=="talk to goblin")
	{
		if (keys==1)
		{
			print("\"You alreade beat me. GO AWAY!\"");
			_getch(); // Wait for keypress from user, gives error but thats normal.
			system("CLS");
			room4(keys, moves, inv);
		}
		moves++;
		print("\"Greetings. I expect you are looking for a key, is that right?\"");
		getline(cin, input);
		if (input=="yes")
		{
			print("\"You and I will play a little game. If you roll a higher than me, you get the key. But if i get the higher number, I win and you don't get the key.\"");
			print("\"Are you ready ?\"");
			getline(cin, input);
			if (input=="yes")
			{
				system("CLS");
				goblinGame(keys, moves, inv);
			}
			else
			{
				print("\"Then come back when you are ready to be beaten.\"");
				room4(keys, moves, inv);
			}
		}
		else
		{
			print("\"Bye then.\"");
			room4(keys, moves, inv);
		}
	}
	if (input == "help")
	{
		print("talk to goblin, back");
		room4(keys, moves, inv);
	}
	if (input == "back")
	{
		system("CLS");
		start(keys, moves, inv);
	}

}

void goblinGame(int& keys, int& moves, bool inv[10])
{
	//Game against goblin
	moves++;
	printStat(keys, moves);
	string input;

	srand(time(NULL));
	int playerRand = rand()%6+1;
	srand(time(NULL) + 10);
	int goblinRand = rand()%6+1;

	print("Roll dice?");
	getline(cin, input);
	if (input=="yes")
	{
		if (playerRand>goblinRand)
		{
			string print_text;
			keys = 1;

			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);

			print(print_text);
			print("YOU WON!");

			print("\"I see.. You won.. I promised to give you the key, so here you have it.. NOW LEAVE!!!\"");
			print("Leave?");
			getline(cin, input);
			if (input=="yes")
			{
				room4(keys, moves, inv);
			}
			else
			{
				print("You got kicked out.");
				_getch;
				room4(keys, moves, inv);
			}
		}
		if (playerRand<goblinRand)
		{
			string print_text;
			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);
			print(print_text);
			print("You lost.");

			print("\"HAHA! I WON! YOU DON'T GET THE KEY! BETTER LUCK NEXT TIME! NOT!!\"");
			print("Try again?");
			getline(cin, input);
			if (input=="yes")
			{
				system("CLS");
				goblinGame(keys, moves, inv);
			}
			else
			{
				room4(keys, moves, inv);
			}
		}
		if (playerRand==goblinRand)
		{
			string print_text;
			print_text = "I rolled a " + to_string(playerRand) + " and the goblin rolled a " + to_string(goblinRand);
			print(print_text);
			print("It's a tie.");
			print("Try again?");
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(keys, moves, inv);
			}
			else
			{
				room4(keys, moves, inv);
			}
		}
		else
		{
			cout << "Error. Oh no! My game! It's broken!" << endl;
			getline(cin, input);
			if (input == "yes")
			{
				system("CLS");
				goblinGame(keys, moves, inv);
			}
			else
			{
				room4(keys, moves, inv);
			}
		}
	}
	else
	{	
		system("CLS");
		room4(keys, moves, inv);
	}

}

void room5(int& keys, int& moves, bool inv[10])
{
	//King with blue torch
	moves++;
	printStat(keys, moves);
	string input;

	print("I am in a big empty room with a painting on the wall.");
	getline(cin, input);
	if (input=="look")
	{
		print("There is a painting on the wall.");
		room5(keys, moves, inv);
	}
	if (input == "help")
	{
		print("look, look at painting, back");
		room5(keys, moves, inv);
	}
	if (input == "look at painting")
	{
		print("There is a king with a blue torch.");
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
	moves++;
	printStat(keys, moves);
	string input;
	print("There is a chest.");
	getline(cin, input);
	if (input == "look")
	{
		print("There is a chest. There is a door to the left.");
		room6(keys, moves, inv);
	}
	if (input == "help")
	{
		print("open chest, back");
		room6(keys, moves, inv);
	}
	if (input == "open left door")
	{
		room2(keys, moves, inv);
	}
	if (input == "back")
	{
		system("CLS");
		room3(keys, moves, inv);
	}
	if (input == "open chest")
	{
		if (keys==1)
		{
			print("What was the color of the torch?");
			getline(cin, input);
			if (input == "blue")
			{
				print("What was the answer to the old mans riddle?");
				getline(cin, input);
				if (input == "darkness")
				{
					print("Thats right, you got a key and a sword.");
					inv[1] = true;
					keys++;
					room6(keys, moves, inv);
				}
				else
				{
					print("That was not right, go back to the man and remember the answer next time.");
					_getch;
					system("CLS");
					room6(keys, moves, inv);
				}

				
			}
			else
			{
				print("That's the wrong answer...");
				room6(keys, moves, inv);
			}

		}
		else
		{
			print("You need a key");
			room6(keys, moves, inv);
		}
	}
	else
	{
		print("Hmm. I didn't understand.");
		room6(keys, moves, inv);
	}
}

void roomBoss(int& keys, int& moves, bool inv[10])
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
		start(keys, moves, inv);
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
	getline(cin, input);
	if (input == "yes")
	{
		print("You hit the dragon.");
		bossHealth = bossHealth - 30;

		if (bossHealth <= 0)
		{
			escape();
		}
		if (playerHealth <= 0) {
			gameover();
		}

		
	}
	else
	{

	}

}

void bossSwing(int& bossHealth, int& playerHealth)
{
	string input;
	print("The Dragon swings it tails and tries to hit you. Jump!");
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