// rVisRandom.cpp : do random stuff DISTRIBUTION 0

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <sstream>
#include <random>
#include <Windows.h>
#include <fstream>
#include <thread>

using namespace std;

unsigned __int64	whamHand(byte);				//Changes strings to numbers with stringstream
int			spawnThread();						//Spawn thread
int			rvUpdater();						//Updates the txt with given chars
int			cruise();							//Loop for the threads, repeats gooby() until finished is true. Saves chars to charbuffer[]
char		gooby();							//Creates random char with random device
string		getpassword(const string& prompt);	//Cheeeky little password field

unsigned __int64	cunt, xunt;	//CUNT = LENGTH XUNT = LINES
unsigned __int64	cuntC = 0;	//Counter
unsigned __int64	xuntC = 0;	//Counter

bool		finished = false;	//Is program finished? Stoppes the worker thread

char charbuffer[1000];			//Random generator writes chars to here, so rvUpdater can write them to file

ofstream	rvExit;

HANDLE cCFrame = GetStdHandle(STD_OUTPUT_HANDLE);

int main()//Yes it is before everything else
{
	string kunt;	//Don't mind my variable names, pls :P
	int noobCount = 0;
	DWORD stT;
	char proc = NULL;
	int dumb = 0;

	SetConsoleTitle(L"rVisRandom.exe");
	SetConsoleTextAttribute(cCFrame, 5);
	cout << "\n\t / / / / / / / /  \\ \\ \\ \\ \\ \\ \\ \\\n\t/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\tIIIIIIII--rVisRandom.exe--IIIIIIII\t v1.0 by Nairdan2\n\t\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\t Distribution 0\n\t \\ \\ \\ \\ \\ \\ \\ \\  / / / / / / / /\n";
	SetConsoleTextAttribute(cCFrame, 7);

	cunt = whamHand(0);

UCUNT://I just like goto;! :P

	if (noobCount == 0)kunt = getpassword("\n\t Please enter code:\t"); else { Beep(3000 + noobCount * 15, 500 * noobCount); noobCount++; kunt = getpassword("\n\t  Enter again, please:\t"); }//Be aware of ugly beep
	noobCount++;
	cout << "\n";

	if (kunt != "4322006")
		goto UCUNT;

	xunt = whamHand(2);

	cout << endl;

	SetConsoleTextAttribute(cCFrame, 4);
	cout << "\n\n\t This would generate ~" <<  (long double)(xunt*cunt)/ 1048576 << " MebiByte of data!\n\t Proceed? y/n\t";	//Prints out how much data will may be generated
	cin >> proc;																												//Only really useful if the data would be huge

again:
	if (proc != 'n' && proc != 'N' && proc != 'y' && proc != 'Y')
		goto dumb;
	else if (proc == 'n' || proc == 'N')
	{
		SetConsoleTextAttribute(cCFrame, 2);
		cout << "\n\n\t Program stopped! Any key to exit!";
		_getche();
		return 0;
	}
	else goto good;

dumb:
	if (dumb == 0)
	{
		cout << "\n\n\t Ok, to make it more clear: YES(y or Y) or NO(n or N)?\t"; dumb++;
	}
	else if (dumb == 1)
	{
		cout << "\n\n\t Are you stupid? YES OR NO!\t"; dumb++;
	}
	else
	{
		cout << "\n\n\t What the FUCK?! Is your IQ lower than 50?!\n\t This program will now shut down in 5 seconds.\n\t I kindly ask you to delete it.";
		Sleep(5000);
		return 0;
	}

	cin >> proc;
	goto again;

good:
	cout << "\n\t Generating may take some time...";
	SetConsoleTextAttribute(cCFrame, 7);

	stT = timeGetTime();

	rvExit.open("rVrandom.txt");
	rvExit << "Variables were " << cunt << " & " << xunt << "\n\n";
	rvExit.close();

	SetConsoleTextAttribute(cCFrame, 2);
	spawnThread();
	rvUpdater();
	SetConsoleTextAttribute(cCFrame, 7);

	rvExit.open("rVrandom.txt", ios::app);
	rvExit << "\n\t Generated with rVisRandom.exe v1.0 made by Nairdan2";
	rvExit.close();

	cout << "\n\n\t Took " << (timeGetTime() - stT)/1000 << "s!";

	cout << "\n\n\t Written to \"rVrandom.txt\"\n\n\t Any key to exit!\n\n\t ";

	Beep(2000, 500);
	Beep(800, 500);		//BEEEP when done!
	Beep(1500, 500);

	_getche();
	
    return 0;
}

unsigned __int64 whamHand(byte first)//Get numbers from input
{
	unsigned __int64 num = 0;

	for (;;)
	{	
		switch (first)
		{
		case 0:
			cout << "\n\t Please enter length:\t";  first = -1; break;
		case 1:
			cout << "\n\t Please enter code:\t";  first = -2; break;
		case 2:
			cout << "\n\t Please enter lines:\t";  first = -3; break;
		default:
			break;
		}

		string lonely;
		getline(cin, lonely);
		stringstream awesome(lonely);

		char ko = 0;
		if (!(awesome >> num).fail() && (awesome >> skipws >> ko).fail())
		{
			if ((first == -2 && num != 4322006) || num < 1 || num > 18446744073709551615)//4322006 gives error whenever input is 0 or negativ or bigger than max unsigned int32 size
				goto nope;
			return num;
		}

nope:
		cout << "\n\t  Enter again, please:\t";
		Beep(2500, 250);
	}
	return 0;
}

int rvUpdater()//prints the buffer to the file. Clears used buffer
{
	rvExit.open("rVrandom.txt", ios::app);

	while (true)
	{
		if (xuntC == xunt && !finished)
		{
			rvExit.close();
			finished = true;
			return 0;
		}

		for (__int16 i = 0; i < 1000; i++)
		{
			if (charbuffer[i] != NULL)
			{
				if (cuntC == cunt - 1)
				{
					rvExit << charbuffer[i] << endl << flush;
					cuntC = 0;
					xuntC++;
				}
				else
				{
					rvExit << charbuffer[i] << flush;
					cuntC++;
				}
				charbuffer[i] = NULL;
				break;
			}
		}
	}
	return 0;
}

int spawnThread()//Spawns a thread that generates the random numbers
{
	for (__int16 c = 0; c < 1000; c++)
	{
		charbuffer[c] = NULL;
	}

	thread rv(cruise);
	rv.detach();

	return 0;
}

int cruise()//While loop for above thread
{
	while (!finished)
	{
		for (__int16 u = 0; u < 1000; u++)
		{
			if(charbuffer[u] == NULL)//Get nearest null charbuffer position
				charbuffer[u] = gooby();//put random char in it
		}
	}
	return 0;
}

char gooby()//Uses random_device to generate chars
{
	int pluto = 0;

	random_device fortune;

	while (pluto < 48 || pluto > 122 || (pluto > 57 && pluto < 65) || (pluto > 90 && pluto < 97))
	{
		pluto = fortune()/10000000;
	}
	return pluto;
}

string getpassword(const string& prompt = "Enter password> ")//Just a password function, veery useful...
{
	string result;

	DWORD mode, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleMode(ih, &mode))
		throw runtime_error("getpassword: You must be connected to a console to use this program.\n");

	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
	char c;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL);
			result.push_back(c);
		}
	}

	SetConsoleMode(ih, mode);

	return result;
}