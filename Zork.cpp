#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void start(int& keys, int& moves, bool inventory[100]);
void printStat(int& keys, int& moves);
void room1(int& keys, int& moves, bool inventory[100]);
void room2(int& keys, int& moves, bool inventory[100]);
void room3(int& keys, int& moves, bool inventory[100]);
void room4(int& keys, int& moves, bool inventory[100]);
void room5(int& keys, int& moves, bool inventory[100]);
void room6(int& keys, int& moves, bool inventory[100]);
void roomBoss(int& keys, int& moves, bool inventory[100]);

int main()
{
    setlocale(LC_ALL, "");
    bool inventory[100];
    int keys = 0, moves = 0;
    printStat(keys, moves);
    cout << "A monster has locked you in an abandoned house. You need to kill the monster to escape." << endl;
    start(keys, moves, inventory);
}

void start(int& keys, int& moves, bool inventory[100])
{
    string input;
    
    getline(cin, input);

    if (input == "read letter") {
        cout << "Zork is a text based adventure game." << endl << "Instructions:" << endl << "You type what you wanna do in the game, ex \"turn south\"or \"look\"";
        moves++;
        printStat(keys, moves);
        start(keys, moves, inventory);
        
    }
    else if (input == "look")
    {
        cout << "You are in the hallway. There is a letter in front of you. There is a door in front of you, to your right, to your left and behind you.";
        moves++;
        printStat(keys, moves);
        start(keys, moves, inventory);
        
    }
    else if (input == "open door")
    {
        cout << "Open what door???";
        moves++;
        printStat(keys, moves);
        start(keys, moves, inventory);
    }
    else if (input == "open forward door")
    {
        cout << "The door is locked... You need to find a key.";
        if (inventory[0]==true)
        {
            system("CLS");
            room1(keys, moves, inventory);
        }
        else
        {
            cout << "The door is locked... You need to find a key.";
            moves++;
            printStat(keys, moves);
            start(keys, moves, inventory);
        }
    }
    else if (input == "open right door")
    {
        system("CLS");
        room2(keys, moves, inventory);
    }
    else
    {
        cout << "Hmmmm. I didn't understand that..." << endl;
        start(keys, moves, inventory);
    }
}

void printStat(int& keys, int& moves)
{
    cout << endl << "Keys: " << keys << " Moves: " << moves << endl;
}

void room1(int& keys, int& moves, bool inventory[100])
{

}

void room2(int& keys, int& moves, bool inventory[100])
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
        room2(keys, moves, inventory);
    }
    else if (input == "help")
    {
        cout << "look, open door behind, open door right, talk to old man" << endl;
        moves++;
        room2(keys, moves, inventory);
    }
    else if (input == "open door right")
    {
        system("CLS");
        moves++;
        room6(keys, moves, inventory);
    }
    else if (input == "open door behind")
    {
        system("CLS");
        moves++;
        start(keys, moves, inventory);
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
                room2(keys, moves, inventory);
            }
        }
        else
        {
            moves++;
            room2(keys, moves, inventory);
        }
    }
    else
    {
        cout << "Hmm... I didn't understand.";
        room2(keys, moves, inventory);
    }
}

void room3(int& keys, int& moves, bool inventory[100])
{
}

void room4(int& keys, int& moves, bool inventory[100])
{
}

void room5(int& keys, int& moves, bool inventory[100])
{
}

void room6(int& keys, int& moves, bool inventory[100])
{
}

void roomBoss(int& keys, int& moves, bool inventory[100])
{
}
