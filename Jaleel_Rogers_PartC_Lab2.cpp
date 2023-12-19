/***************************************************************************
 * Title:               Lab 2 Part C
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/17/2022 @ 12:30 PM
 * Modification date:   10/18/2022 @ 7:40 PM
 * Description:         Write a program that plays the popular scissor, rock, paper game. (A scissor can cut a
                        paper, a rock can knock a scissor, and a paper can wrap a rock.) The program randomly
                        generates a number 0, 1, or 2 representing scissor, rock, or paper. The program prompts
                        the user to enter a number 0, 1, or 2 and displays a message indicating whether the user
                        or the computer wins, loses, or draws.
 **************************************************************************/
#include <iostream>
#include <ctime> //For random
#include <cstdlib> // For random

// The variables
int scissor = 0;
int rock = 1;
int paper = 2;

int computerChoice() // Responsible for providing randomization to the whole program
{
srand(time(0)); // Random number

int num = rand () % 3 + 1; // My range

if (num == 0) return scissor; // 0 is scissor
if (num == 1) return rock; // 1 is rock
if (num == 2) return paper; // 2 is paper
}

int userChoice() // Holds the prompt and input
{
int choice;

std::cout << "scissor (0), rock (1), paper(2):";

while (!(std::cin >> choice) || (choice < 0 || choice > 2)) // Used for in case user input is greater or less than 0
{
std::cout << "Must be a number between positive 0 to 2"<<std::endl;
}
return choice;

}
// Created every possible combination
void matchUp (int user, int computer) // Will not return anything since its void | Decision maker for computer
{
if (user == 0 && computer == 0) // If computer chose scissor
{
std::cout << "Computer is scissor. You are scissor. Draw." << std::endl;
}
else if (user == 0 && computer == 1)
{
std::cout << "Computer is rock. You are scissor. You lost." << std::endl;
}
else if (user == 0 && computer == 2)
{
std::cout << "Computer is paper. You are scissor. You win." << std::endl;
}
else if (user == 1 && computer == 0) // If computer chose rock
{
std::cout << "Computer is scissor. You are rock. You won." << std::endl;
}
else if (user == 1 && computer == 1)
{
std::cout << "Computer is rock. You are rock. Draw." << std::endl;
}
else if (user == 1 && computer == 2)
{
std::cout << "Computer is paper. You are rock. You lost." << std::endl;
}
else if (user == 2 && computer == 0) // If computer chose paper
{
std::cout << "Computer is scissor. You are paper. You lost." << std::endl;
}
else if (user == 2 && computer == 1)
{
std::cout << "Computer is rock. You are paper. You won." << std::endl;
}

else // Made draw the else statement to conclude if-else statements
{
std::cout << "Computer is paper. You are paper. Draw." << std::endl;
}
}

int main() // Contains the primary functions in the program for execution
{
//User's choice
int user;
//Computer's choice
int computer;
user = userChoice(); // Shows prompt and allows for input

matchUp(user, computer); // Gives the result

return 0;
}