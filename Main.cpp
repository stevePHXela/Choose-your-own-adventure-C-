#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int level;
string message = "Enter (S) to start or enter (Q) to exit?: ";
string situation;
std::array<string, 2> Options;
bool gameOver = false;

struct Keys
{
	static const char QUIT = 'q';
	static const char START = 's';
	static const char CHOICE_A = 'a';
	static const char CHOICE_B = 'b';
};

void Draw()
{
	system("cls");

	cout << "###########################################" << endl;
	cout << "Welcome to, choose your own adventure game!" << endl;
	cout << "###########################################" << endl;

	if (level > 0)
	{
		cout << endl;
		cout << situation << endl;
		cout << Options[0] << endl;
		cout << Options[1] << endl;
		cout << endl;
	}
	
	cout << message;
}

char getUserInput()
{
	char userInput;
	cin >> userInput;
	userInput = (char)std::tolower(userInput);

	if (userInput == Keys::QUIT)
	{
		exit(EXIT_SUCCESS);
	}
	else if (userInput == Keys::START && level == NULL)
	{
		level = 1;
	}

	return userInput;
}

void Logic()
{
	char userChoice = getUserInput();

	if (level == 1)
	{
		message = "Enter a choices or enter (Q) to exit?: ";
		situation = "They are here. their vision is based on movement, they give chase.";
		Options[0] = "A. Give in!";
		Options[1] = "B. Run!";
		level++;
	}

	if (level == 2)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			message = "They show you no mercy. The pain is indescribable.";
			gameOver = true;
		}
		else if (userChoice == Keys::CHOICE_B)
		{
			level++;
			situation = "They are fast, too fast. They are catching up.";
			Options[0] = "A. Turn and fight!";
			Options[1] = "B. Hide!";
		}
	}
	else if (level == 3)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			message = "You fool! They quickly overpower you. Your end is neither swift nor dignified. Your mangled corpse serves as a warning to others.";
			gameOver = true;
		}
		else if (userChoice == Keys::CHOICE_B)
		{
			level++;
			situation = "There is a pile of rubble you can squeeze under. A metal object glints faintly.";
			Options[0] = "A. Examine!";
			Options[1] = "B. Stay hidden!";
		}
	}
	else if (level == 4)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			message = " All that glisters is not gold. The detonation rips you in half. They feast on your remains.";
			gameOver = true;
		}
		else if (userChoice == Keys::CHOICE_B)
		{
			level++;
			situation = "Your heart beats loudly, you are sure they will hear. An hour passes.";
			Options[0] = "A. Wait!";
			Options[1] = "B. Look around!";
		}
	}
	else if (level == 5)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			level++;
			situation = "Suddenly you jerk awake! How much time has passed? It is night.";
			Options[0] = "A. Leave!";
			Options[1] = "B. Stay hidden!";
		}
		else if (userChoice == Keys::CHOICE_B)
		{			
			message = "You stepped into a trap, They cut you in a parts, The pain is indescribable.";
			gameOver = true;
		}
	}
	else if (level == 6)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			level++;
			situation = "They have gone. Slowly, you creep out. Blood is smeared on the streets. You are tired.";
			Options[0] = "A. Scream for help!";
			Options[1] = "B. Keep moving!";
		}
		else if (userChoice == Keys::CHOICE_B)
		{			
			message = "The night is bitterly cold. In the morning, they find your frozen body. They snap your fingers off for fun.";
			gameOver = true;
		}
	}
	else if (level == 7)
	{
		if (userChoice == Keys::CHOICE_A)
		{
			message = "They heard you. Its foul breath fills you with corruption. You deserve this. You truly do for your wicked life.";
			gameOver = true;
		}
		else if (userChoice == Keys::CHOICE_B)
		{			
			message = "Congratulations!!! You found a way out of the island!";
			gameOver = true;
		}
	}
}

void Run()
{
	while (true)
	{
		if (gameOver)
			exit(EXIT_SUCCESS);

		Draw();
		Logic();

		cout << ">>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\"" << message << "\"" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>" << endl;
	}
}

int main()
{
	Run();
}