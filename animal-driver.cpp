#include "animal.h"
#include <iostream>
using namespace std;

void ShowMenu()
{
    cout << "\n \t \t ANIMAL DIRECTORY     " << endl;
    cout << "\n \t A \t Add animals to the list";
    cout << "\n \t S \t Show the list";
    cout << "\n \t ? \t Display this menu";
    cout << "\n \t E \t End program" << endl;
}

char GetAChar(const char* promptString)
{
    char response; 
    cout << "\nPlease enter the CAPITAL letter of the menu choice you would like to select: ";
    cin >> response;
    cin.get();
    
    return response;
}

bool Legal(char c) // Determine if a particular character, c, corresponds to a legal menu command
{
    return ((c == 'A') || (c == 'S') || (c == '?') || (c == 'E') || (c == 'D') || (c == 'C') || (c == 'P') || (c == 'W'));
}

char GetCommand() // Prompts the user for a menu command until a legal command character is entered
{
    char cmd = GetAChar("\n \n >"); // Get a command character
    
    while (!Legal(cmd)) // As long as it's not a legal command, display menu and try again
    {
        cout << "\nIllegal command, please try again..." << endl;
        ShowMenu();
        cmd = GetAChar("\n \n >");
    }

    return cmd;
}

int main()
{
    ShowMenu(); // Displays the menu
    char command;
    char animalChoice;
    AnimalList l; // Making an instance of a list

    do
    {
        command = GetCommand();
        
        switch (command)
        {
            case 'A':
                cout << "Please enter a character for your animal choice (D for dog, C for cat, P for pig, W for cow): ";
                cin >> animalChoice;
                l.Add(animalChoice);    break;
            case 'S': l.Show();         break;
            case '?': ShowMenu();       break;
            case 'E':                   break;
        }
    } while (command != 'E');
}