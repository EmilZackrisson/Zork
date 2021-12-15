// Zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void start(int& points, int& moves, string& direction, bool inventory[100]);
void newRoom(int& points, int& moves, string& direction);

int main()
{
    setlocale(LC_ALL, "");
    bool inventory[100];
    int points = 0, moves = 0;
    string direction = "north";
    start(points, moves, direction, inventory);

}

void start(int& points, int& moves, string& direction, bool inventory[100])
{
    string input;
    newRoom(points, moves, direction);
    cout << "A monster has locked you in an abandoned house. You need to kill the monster to escape." << endl << "There is a letter in front of you." << endl;
    getline(cin, input);
    if (input == "read letter") {
        newRoom(points, moves, direction);
        cout << "Zork is a text based adventure game." << endl << "Instructions:" << endl << "You type what you wanna do in the game, ex \"turn south\"or \"look\"";
        start(points, moves, direction, inventory);
    }
    else if (input == "look")
    {
        newRoom(points, moves, direction);
        cout << "You are in the hallway.";
        start(points, moves, direction, inventory);
    }
}

void printStat(int& points, int& moves, string& direction)
{
    cout << "Points: " << points << " Moves: " << moves << " Direction: " << direction << endl;
}
