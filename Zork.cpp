#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <shellapi.h>
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


int main()
{
	setlocale(LC_ALL, "");
	bool inv[10];
	int keys = 0, moves = 3;
	

	//Allows dev to jump to room and get the right keys
	int devRoomTest = 0; // 0 As standard
	if (devRoomTest == 0) // Start room
	{
		cout << "A monster has locked you in an abandoned house. You need to kill the monster to escape." << endl;
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
	//else
	//{
		//cout << "devRoomTest invalid value";
	//}
	
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
	else if (input == "open door behind") //Room 3
	{
		system("CLS");
		room3(keys, moves, inv);
	}
	else if (input == "help")
	{
		cout << "look, read letter, open forward door, open right door, open left door, open door behind" << endl;
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
		if (keys == 2)
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
		cout << "There is a door in front of you."<<endl<< "There is a door to your right." << endl << "There is a door behind you." << endl;
		room3(keys, moves, inv);
	}
	if (input == "help")
	{
		cout << "look, open door right, open door forward, open door back" << endl;
		room3(keys, moves, inv);
	}
	if (input=="open door right")
	{
		//To room 5. Needs key from room 4 (goblin).
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
	if (input == "back")
	{
		system("CLS");
		start(keys, moves, inv);
	}
	else
	{
		cout << "I didn't understand that.." << endl;
		room3(keys, moves, inv);
	}
}

void room4(int& keys, int& moves, bool inv[10])
{
	//Goblinroom
	moves++;
	printStat(keys, moves);
	string input;
	cout << "There is a goblin here." << endl;
	getline(cin, input);
	if (input=="talk to goblin")
	{
		if (keys==1)
		{
			cout << "You already beat me. GO AWAY!";
			_getch(); // Wait for keypress from user, gives error but thats normal.
			system("CLS");
			room4(keys, moves, inv);
		}
		moves++;
		cout << "Greetings. I expect you are looking for a key, is that right?";
		getline(cin, input);
		if (input=="yes")
		{
			cout << "You and I will play a little game. If you roll a higher than me, you get the key. But if i get the higher number, I win and you don't get the key." << endl << "Are you ready ? " << endl;
			getline(cin, input);
			if (input=="yes")
			{
				system("CLS");
				goblinGame(keys, moves, inv);
			}
			else
			{
				cout << "Then come back when you are ready to be beaten." << endl;
				room4(keys, moves, inv);
			}
		}
		else
		{
			cout << "Bye then.";
			room4(keys, moves, inv);
		}
	}
	if (input == "help")
	{
		cout << "talk to goblin, back";
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

	srand(moves);
	int playerRand = rand()%6+1;
	srand(moves + 10);
	int goblinRand = rand()%6+1;

	cout << "Roll dice?" << endl;
	getline(cin, input);
	if (input=="yes")
	{
		if (playerRand>goblinRand)
		{
			
			keys = 1;
			cout << "You rolled a " << playerRand << " and the goblin rolled a " << goblinRand << endl << "YOU WON!" << endl;
			cout << "I see.. You won.. I promised to give you the key, so here you have it.. NOW LEAVE!!!" << endl;
			cout << "Leave?" << endl; 
			getline(cin, input);
			if (input=="yes")
			{
				room4(keys, moves, inv);
			}
			else
			{
				room4(keys, moves, inv);
			}
		}
		if (playerRand<goblinRand)
		{
			cout << "You rolled a " << playerRand << " and the goblin rolled a " << goblinRand << endl << "You lost..." << endl;
			cout << "HAHA! I WON! YOU DON'T GET THE KEY! BETTER LUCK NEXT TIME! NOT!!" << endl;
			cout << "Try again?" << endl;
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
			cout << "You rolled a " << playerRand << " and the goblin rolled a " << goblinRand << endl << "It's a tie." << endl;
			cout << "Try again?" << endl;
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
	moves++;
	printStat(keys, moves);
	string input;
	cout << "There is a chest." << endl;
	getline(cin, input);
	if (input == "look")
	{
		cout << "There is a chest. There is a door to your left." << endl;
		room6(keys, moves, inv);
	}
	if (input == "help")
	{
		cout << "open chest, back";
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
			cout << "What was the color of the torch?" << endl;
			getline(cin, input);
			if (input == "blue")
			{
				cout << "What was the answer to the old mans riddle?" << endl;
				getline(cin, input);
				if (input == "darkness")
				{
					cout << "Thats right, you got a key and a sword.";
					inv[1] = true;
					keys++;
					room6(keys, moves, inv);
				}
				else
				{
					cout << "That was not right, go back to the man and remember the answer next time." << endl;
					Sleep(1000);
					system("CLS");
					room6(keys, moves, inv);
				}

				
			}
			else
			{
				cout << "Thats the wrong answer...";
				room6(keys, moves, inv);
			}

		}
		else
		{
			cout << "You need a key...";
			room6(keys, moves, inv);
		}
	}
	else
	{
		cout << "Hmm. I didn't understand." << endl;
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
	cout << "You are in a room with a sleeping dragon." << endl << "Behind the dragon is a door." << endl;
	cout << "You pull out your sword." << endl << "Hit the dragon?" << endl;
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
			cout << "You killed the dragon." << endl;
		}
		if (playerHealth <= 0)
		{
			cout << "You died...";
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
	cout << "Hit the dragon?";
	getline(cin, input);
	if (input == "yes")
	{
		cout << "You hit the dragon." << endl;
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
	cout << "The Dragon swings it tails and tries to hit you. Jump!" << endl;
	getline(cin, input);
	if (input != "jump")
	{
		playerHealth = playerHealth - 40;
	}
	
}

void escape()
{
	string input;
	cout << "YOU KILLED THE DRAGON! TRY TO ESCAPE!";
	getline(cin, input);
	if (input == "escape")
	{
		cout << "You escaped. You beat the game. Congratulations." << endl << endl;
		Sleep(5000);
		exit(0);
	}
}

void gameover()
{
	cout << "Game Over! You died.";
	exit(0);
}
