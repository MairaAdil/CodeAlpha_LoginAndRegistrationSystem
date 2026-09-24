#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void wait()
{
	Sleep(700);
}

void successSound()
{
	Beep(800, 150);
	Beep(1000, 200);
}

void errorSound()
{
	Beep(400, 300);
}

bool validUsername(string username)
{
	if (username.length() == 0)
	{
		return false;
	}

	for (int i = 0; i < username.length(); i++)
	{
		if (!isalnum(username[i]) && username[i] != '_')
		{
			return false;
		}
	}

	return true;
}

bool validPassword(string password)
{
	if (password.length() < 6)
	{
		return false;
	}

	return true;
}

bool usernameExists(string username)
{
	ifstream file("users.txt");

	string savedUsername;
	string savedPassword;

	while (file >> savedUsername >> savedPassword)
	{
		if (savedUsername == username)
		{
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}

void registration()
{
	string username;
	string password;

	system("cls");

	setColor(11);
	cout << "\n========================================\n";
	cout << "             REGISTRATION\n";
	cout << "========================================\n";
	setColor(7);

	while (true)
	{
		setColor(14);
		cout << "\nEnter username: ";
		setColor(7);

		getline(cin >> ws, username);

		if (!validUsername(username))
		{
			setColor(12);
			cout << "\nInvalid username!\n";
			cout << "Spaces and special characters are not allowed.\n";
			cout << "Use only letters, numbers and underscore (_).\n";
			setColor(7);

			errorSound();
			continue;
		}

		if (usernameExists(username))
		{
			setColor(12);
			cout << "\nUsername already exists!\n";
			cout << "Please enter another username.\n";
			setColor(7);

			errorSound();
			continue;
		}

		break;
	}

	while (true)
	{
		setColor(14);
		cout << "Enter password: ";
		setColor(7);

		getline(cin >> ws, password);

		if (!validPassword(password))
		{
			setColor(12);
			cout << "\nPassword must contain at least 6 characters.\n";
			setColor(7);

			errorSound();
			continue;
		}

		break;
	}

	ofstream file("users.txt", ios::app);

	if (!file)
	{
		setColor(12);
		cout << "\nFile error!\n";
		setColor(7);

		errorSound();
		wait();
		return;
	}

	file << username << " " << password << endl;

	file.close();

	successSound();

	setColor(10);
	cout << "\nRegistration successful!\n";
	setColor(7);

	wait();
}

void login()
{
	string username;
	string password;

	string savedUsername;
	string savedPassword;

	system("cls");

	setColor(11);
	cout << "\n========================================\n";
	cout << "                 LOGIN\n";
	cout << "========================================\n";
	setColor(7);

	while (true)
	{
		setColor(14);
		cout << "\nEnter username: ";
		setColor(7);

		getline(cin >> ws, username);

		setColor(14);
		cout << "Enter password: ";
		setColor(7);

		getline(cin >> ws, password);

		ifstream file("users.txt");

		if (!file)
		{
			setColor(12);
			cout << "\nNo users are registered yet!\n";
			setColor(7);

			errorSound();
			wait();

			return;
		}

		bool found = false;

		while (file >> savedUsername >> savedPassword)
		{
			if (savedUsername == username &&
				savedPassword == password)
			{
				found = true;
				break;
			}
		}

		file.close();

		if (found)
		{
			successSound();

			setColor(10);
			cout << "\nLogin successful!\n";
			cout << "Welcome, " << username << "!\n";
			setColor(7);

			wait();
			return;
		}

		setColor(12);
		cout << "\nInvalid username or password!\n";
		cout << "Please try again.\n";
		setColor(7);

		errorSound();
		wait();
	}
}

int main()
{
	int choice;

	while (true)
	{
		system("cls");

		setColor(11);
		cout << "\n========================================\n";
		cout << "       LOGIN & REGISTRATION SYSTEM\n";
		cout << "========================================\n";
		setColor(7);

		setColor(10);
		cout << "\n1. Register\n";

		setColor(14);
		cout << "2. Login\n";

		setColor(12);
		cout << "3. Exit\n";

		setColor(7);
		cout << "\nEnter choice: ";

		cin >> choice;

		if (cin.fail())
		{
			cin.clear();

			string invalidInput;
			cin >> invalidInput;

			setColor(12);
			cout << "\nInvalid input! Enter 1, 2 or 3.\n";
			setColor(7);

			errorSound();
			wait();

			continue;
		}

		if (choice == 1)
		{
			registration();
		}
		else if (choice == 2)
		{
			login();
		}
		else if (choice == 3)
		{
			setColor(10);
			cout << "\nProgram ended.\n";
			setColor(7);

			successSound();
			wait();

			break;
		}
		else
		{
			setColor(12);
			cout << "\nInvalid choice! Enter 1, 2 or 3.\n";
			setColor(7);

			errorSound();
			wait();
		}
	}

	return 0;
}