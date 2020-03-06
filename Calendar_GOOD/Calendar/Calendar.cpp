// CAL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <sstream>
using namespace std;


void GetNewInfo(int &day, int &month, int &year);
int FindEaster(int year);
int FindDay(int day, int &month, int year);
string FindMonth(int month);
int FindRealMonth(int year);
void ShowCalendar(string monthstr, int year, int maxdays, int startday, int month, int day);
int FindTotalDays(int month, int year);

void GetNewInfo1(int &hday, int &hmonth, int &hyear);
int FindEaster1(int hyear);
int FindDay1(int hday, int &hmonth, int hyear);
string FindMonth1(int hmonth);
int FindRealMonth1(int hmonth);
void ShowCalendar1(string hmonthstr, int hyear, int hmaxdays, int hstartday, int hmonth, int hday);
int FindTotalDays1(int month, int year);

/*void GetNewInfo2(int &day, int &month, int &year);
int FindEaster2(int year);
int FindDay2(int day, int &month, int year);
string FindMonth2(int month);
int FindRealMonth2(int month);
void ShowCalendar2(string monthstr, int year, int maxdays, int startday, int month, int day);
int FindTotalDays2(int month, int year);

void GetNewInfo3(int &day, int &month, int &year);
int FindEaster3(int year);
int FindDay3(int day, int &month, int year);
string FindMonth3(int month);
int FindRealMonth3(int month);
void ShowCalendar3(string monthstr, int year, int maxdays, int startday, int month, int day);
int FindTotalDays3(int month, int year);*/

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	bool replay = false;
	char replayc;

	do {
		int k = 0;
		int m = 0;
		int d = 0;
		int c = 0;
		int f = 0;
		int fint = 0;
		int y = 0;
		int md = 0;
		int holiday = 0;
		int estdate = 0;
		int hk = 0;
		int hm = 0;
		int hd = 0;
		int hc = 0;
		int hf = 0;
		int hfint = 0;
		int hy = 0;
		int hmd = 0;
		int hholiday = 0;
		string monthname;
		string hmonthname;
		char ans = 'n';

		system("cls");
		k = 0;
		m = 0;
		y = 0;
		fint = 0;
		md = 0;

		GetNewInfo(k, m, y);
		fint = FindDay(k, m, y);
		holiday = FindEaster(y);
		monthname = FindMonth(m);
		md = FindTotalDays(m, y);
		estdate = FindRealMonth(y);
		ShowCalendar(monthname, y, md, fint, m, k);
		cout << endl;
		cout << "Easter falls on " << estdate << "/" << holiday << "/" << y << endl;

		system("pause");
		
		cout << "\n Would you like to run again? y/n: ";
		cin >> replayc;
		
		if (replayc == 'y') {
			replay = true;
		}
		else {
			replay = false;
		}

		k = 0;
		m = 0;
		y = 0;
		fint = 0;
		md = 0;
	} while (replay);


	return 0;
}

void GetNewInfo(int &day, int & month, int & year)
{
	string date1;
	char date[11];
	int k, m, y, c, d, hold;
	/*cout << "Enter Day of month";
	cin >> day;
	cout << "Enter month as in number";
	cin >> month;

	//cout << m;
	//cout << endl;

	cout << "Enter year";
	cin >> year;
	//c = y / 100;
	//cout << "c = " << c;
	//cout << endl;
	//d = y - (c * 100);
	//cout << "d = " << d;
	//cout << endl;*/

	cout << "What is the date? ";
	//cin >> date1;
	cin.get(date, 11);
	cin.ignore();
	system("cls");
	month = date[0] + date[1];

	hold = date[0];
	if (hold == 48) {

		if (month == 97) {
			month = 11;
		}
		if (month == 98) {
			month = 12;
		}
		if (month == 99) {
			month = 1;
		}
		if (month == 100) {
			month = 2;
		}
		if (month == 101) {
			month = 3;
		}
		if (month == 102) {
			month = 4;
		}
		if (month == 103) {
			month = 5;
		}
		if (month == 104) {
			month = 6;
		}
		if (month == 105) {
			month = 7;
		}
	}
	else {
		if (month == 97) {
			month = 8;
		}
		if (month == 98) {
			month = 9;
		}
		if (month == 99) {
			month = 10;
		}

	}


	year = (date[6] - 48) * 1000;
	year = year + ((date[7] - 48) * 100);
	year = year + ((date[8] - 48) * 10);
	year = year + ((date[9] - 48) * 1);

	c = year / 100;
	d = year - (c * 100);

	day = (date[3] - 48) * 10;
	day = day + (date[4] - 48);

}

int FindEaster(int year)
{
	int a, b, c, d, e, f, g, h, i, j, k, m, p, holiday, month;

	a = year % 19;
	b = year / 100;
	c = year % 100;
	d = b / 4;
	e = b % 4;
	f = (b + 8) / 25;
	g = (b - f + 1) / 3;
	h = ((19 * a) + b - d - g + 15) % 30;
	i = c / 4;
	j = c % 4;
	k = (32 + (2 * e) + (2 * i) - h - j) % 7;
	m = (a + (11 * h) + (22 * k)) / 451;
	month = (h + k - (7 * m) + 114) / 31;
	p = (h + k - (7 * m) + 114) % 31;
	holiday = p + 1;

	return holiday;
}

int FindDay(int day, int &month, int year)
{
	int fint, m, k, c, y;
	//month = month - 2;
	//if (month <= 0)
	//{
	//	month = month + 12;
	//}
	//y = 0;
	//m = 0;

	c = year / 100;
	day = year - (c * 100);
	fint = 1 + ((13 * month - 1) / 5) + day + (day / 4) + (c / 4) - 2 * c;
	fint = fint - 7 * (fint / 7);
	if (fint < 0) {
		fint = fint + 7;
	}

	return fint;
}

string FindMonth(int month)
{
	int m;
	//m = 0;
	string monthname;

	if (month == 11)
	{
		monthname = "January";
	}
	if (month == 12)
	{
		monthname = "February";
	}
	if (month == 1)
	{
		monthname = "March";
	}
	if (month == 2)
	{
		monthname = "April";
	}
	if (month == 3)
	{
		monthname = "May";
	}
	if (month == 4)
	{
		monthname = "June";
	}
	if (month == 5)
	{
		monthname = "July";
	}
	if (month == 6)
	{
		monthname = "August";
	}
	if (month == 7)
	{
		monthname = "September";
	}
	if (month == 8)
	{
		monthname = "October";
	}
	if (month == 9)
	{
		monthname = "November";
	}
	if (month == 10)
	{
		monthname = "December";
	}
	return monthname;
}

int FindRealMonth(int year)
{
	int a, b, c, d, e, f, g, h, i, j, k, m, p, month;

	a = year % 19;
	b = year / 100;
	c = year % 100;
	d = b / 4;
	e = b % 4;
	f = (b + 8) / 25;
	g = (b - f + 1) / 3;
	h = ((19 * a) + b - d - g + 15) % 30;
	i = c / 4;
	j = c % 4;
	k = (32 + (2 * e) + (2 * i) - h - j) % 7;
	m = (a + (11 * h) + (22 * k)) / 451;
	month = (h + k - (7 * m) + 114) / 31;
	return month;
}

void ShowCalendar(string monthstr, int year, int maxdays, int startday, int month, int day)
{

	int flag, fint, nd, y, mike, micah, george, cut;

	//mike = -1;
	//micah = -1;
	cout << setiosflags(ios::left || ios::showpoint) << setw(28) << monthstr;
	cout << endl;
	cout << setw(26) << year;
	cout << endl;
	cout << "   S      M      T      W      Th      F     S";
	cout << endl;

	nd = 0;
	//flag = 0;
	cout << "__________________________________________________\n";

	if (startday == 0) {
		startday = 1;
	}

	if (startday == 1) {
		startday = 0;
	}

	if (startday == 2) {
		startday = 1;
	}

	for (int i = 0; i < 42; i = i + 1) {


		if (i < startday) {
			cout << "|      ";


		}

		if (nd <= maxdays)
		{
			if (i > startday) {


				cout << "|";
				if (nd == day) {
					SetConsoleTextAttribute(console, 10);
				}
				cout << setw(6) << nd;
				nd = nd + 1;

			}




		}

		if (i == startday) {
			nd = 1;
			cout << "|";
			if (nd == day) {
				SetConsoleTextAttribute(console, 10);
			}
			cout << setw(6) << nd;
			nd = nd + 1;
		}



		if (nd > maxdays) {
			//george = mike + 7;
			if (i % 7 == 6) {
				cout << "|";
				break;
			}
			cout << "|      ";


		}

		if (i % 7 == 6 && i != 0)
		{
			SetConsoleTextAttribute(console, 15);
			mike = i;
			cout << "|";
			cout << endl;
			cout << "|      |      |      |      |      |      |      |\n";
			cout << "|      |      |      |      |      |      |      |\n";
			cout << "__________________________________________________\n";

		}

		//if (nd <= maxdays)
		//{
		///if (int(i) > startday) {
		//cout << "|" << setw(6) << nd;
		//if (fint > 0) {
		//if (nd % 7 == (7 - startday)) {
		// || nd == (8 - startday - 1)) 
		//if (mike != -1) {
		//mike = mike + 7;
		//}




		//}

		//flag = 1;
		//}
		//}

		//}cout << endl;

		SetConsoleTextAttribute(console, 15);

	}
	cout << "\n|      |      |      |      |      |      |      |\n";
	cout << "|      |      |      |      |      |      |      |\n";
	cout << "__________________________________________________\n";
	cout << "Legend: \n";

	if (month == 12)
	{

		cout << "Valentine's Day -- February 14\n";
		cout << "           @@@@@@           @@@@@@\n";
		cout << "         @@@@@@@@@@       @@@@@@@@@@\n";
		cout << "      @@@@@@@@@@@@@@   @@@@@@@@@@@@@@\n";
		cout << "    @@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@\n";
		cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "          @@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "            @@@@@@@@@@@@@@@@@@@\n";
		cout << "              @@@@@@@@@@@@@@@\n";
		cout << "                @@@@@@@@@@@\n";
		cout << "                  @@@@@@@\n";
		cout << "                    @@@\n";
		cout << "                     @\n";
	}
	if (month == 11)
	{
		cout << "New Years Day -- January 1st\n";
		cout << "		                         .''.\n";
		cout << "	       .''.             *''*    :_\/_:     .\n";
		cout << "	      :_\/_:   .    .:.*_\/_*   : /\ :  .'.:.'.\n";
		cout << "	  .''.: /\ : _\(/_  ':'* /\ *  : '..'.  -=:o:=-\n";
		cout << "	 :_\/_:'.:::. /)\*''*  .|.* '.\'/.'_\(/_'.':'.'\n";
		cout << "	 : /\ : :::::  '*_\/_* | |  -= o =- /)\    '  *\n";
		cout << "	  '..'  ':::'   * /\ * |'|  .'/.\'.  '._____\n";
		cout << "	      *        __*..* |  |     :      |.   |' .--- |\n";
		cout << "	       _*   .-'   '-. |  |     .--'|  ||   | _|    |\n";
		cout << "	    .-'|  _.|  |    ||   '-__  |   |  |    ||      |\n";
		cout << "	    |' | |.    |    ||       | |   |  |    ||      |\n";
		cout << "	 ___|  '-'     '    ""       '-'   '-.'    '`      |____\n";
		cout << "	  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
	if (month == 1)
	{
		cout << "St. Patricks Day -- March 17\n";
		cout << "	          .-.-.\n";
		cout << "	         (     )\n";
		cout << "	       .-.\ : /.-.\n";
		cout << "	      (   .`:`.   )\n";
		cout << "	       (   /|\   )\n";
		cout << "	        ` ` | ` `\n";

	}
	if (month == 2)
	{
		cout << "Easter --";
		cout << "			 / \\n";
		cout << "	        / _ \\n";
		cout << "	       | / \ |\n";
		cout << "	       ||   || _______\n";
		cout << "	       ||   || |\     \\n";
		cout << "	       ||   || ||\     \\n";
		cout << "	       ||   || || \    |\n";
		cout << "	       ||   || ||  \__/\n";
		cout << "	       ||   || ||   ||\n";
		cout << "	        \\_/ \_/ \_//\n";
		cout << "	       /   _     _   \\n";
		cout << "	      /               \\n";
		cout << "	      |    O     O    |\n";
		cout << "	      |   \  ___  /   |\n";
		cout << "	     /     \ \_/ /     \\n";
		cout << "	    /  -----  |  --\    \\n";
		cout << "	    |     \__/|\__/ \   |\n";
		cout << "	    \       |_|_|       /\n";
		cout << "	     \_____       _____/\n";
		cout << "	           \     /\n";
		cout << "	           |     |\n";

	}
	if (month == 3)
	{
		cout << "Memorial Day -- May 28\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  ::::::::::::::::::::;::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	}
	if (month == 4)
	{
		cout << "Flag Day -- June 14th\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  ::::::::::::::::::::;::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	}
	if (month == 5)//july
	{
		cout << "4th of July -- July 4\n";
		cout << "			   .-""""""""-.         \n";
		cout << "	         .'       __  \_        \n";
		cout << "	        /        /  \/  \        \n";
		cout << "	       |         \_0/\_0/______     \n";
		cout << "	       |:.          .'       oo`\    \n";
		cout << "	       |:.         /             \    \n";
		cout << "	       |' ;        |             |    \n";
		cout << "	       |:..   .     \_______     |     \n";
		cout << "	       |::.|'     ,  \,_____\   /        \n";
		cout << "	       |:::.; ' | .  '|  ====)_/===;===========;()    \n";
		cout << "	       |::; | | ; ; | |            # # # #::::::\n";
		cout << "	      /::::.|-| |_|-|, \           # # # #::::::\n";
		cout << "	     /'-=-'`  '-'   '--'\          # # # #::::::\n";
		cout << "	    /                    \         # # # #::::::\n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	           H A P P Y               # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	   F O U R T H  O F  J U L Y       # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
	}
	if (month == 6)
	{
		cout << " Eashan Vytla's Birthday MOST IMPORTANT DAY OF THE YEAR! -- August 3\n";
		cout << "		        ,   ,   ,   ,\n";
		cout << "           , |_,_|_,_|_,_| ,\n";
		cout << "       _,-=|;  |,  |,  |,  |;=-_\n";
		cout << "     .-_| , | , | , | , | , |  _-.\n";
		cout << "     |:  -|:._|___|___|__.|:=-  :|\n";
		cout << "     ||*:  :    .     .    :  |*||\n";
		cout << "     || |  | *  |  *  |  * |  | ||\n";
		cout << " _.-=|:*|  |    |     |    |  |*:|=-._\n";
		cout << "-    `._:  | *  |  *  |  * |  :_.'    -\n";
		cout << " =_      -=:.___:_____|___.: =-     _=\n";
		cout << "    - . _ __ ___  ___  ___ __ _ . -\n";
	}
	if (month == 7)
	{
		cout << " My Sister's Birthday -- September 29\n";
		cout << "		        ,   ,   ,   ,\n";
		cout << "           , |_,_|_,_|_,_| ,\n";
		cout << "       _,-=|;  |,  |,  |,  |;=-_\n";
		cout << "     .-_| , | , | , | , | , |  _-.\n";
		cout << "     |:  -|:._|___|___|__.|:=-  :|\n";
		cout << "     ||*:  :    .     .    :  |*||\n";
		cout << "     || |  | *  |  *  |  * |  | ||\n";
		cout << " _.-=|:*|  |    |     |    |  |*:|=-._\n";
		cout << "-    `._:  | *  |  *  |  * |  :_.'    -\n";
		cout << " =_      -=:.___:_____|___.: =-     _=\n";
		cout << "    - . _ __ ___  ___  ___ __ _ . -\n";

	}
	if (month == 8)
	{
		cout << "Halloween -- October 31st\n";
		cout << "		                           .-.\n";
		cout << "                   heehee      /aa \_\n";
		cout << "                             __\-  / )                 .-.\n";
		cout << "                   .-.      (__/    /        haha    _/oo \ \n";
		cout << "                 _/ ..\       /     \               ( \v  /__\n";
		cout << "                ( \  u/__    /       \__             \/   ___)\n";
		cout << "                 \    \__)   \_.-._._   )  .-.       /     \ \n";
		cout << "                 /     \             `-`  / ee\_    /       \_\n";
		cout << "              __/       \               __\  o/ )   \_.-.__   )\n";
		cout << "             (   _._.-._/     hoho     (___   \/           '-'\n";
		cout << "              '-'                        /     \ \n";
		cout << "                                       _/       \    teehee \n";
		cout << "                                      (   __.-._/ \n";
	}
	if (month == 9)
	{
		cout << "Thanksgiving Day -- November 22\n";
		cout << "               _,-- ^^ -.,_\n";
		cout << "         _.-""~^`~-.    .-~`^~""-._\n";
		cout << "     ,=`-._     .----.     _.- `  =,\n";
		cout << "    ;_        -. (0 )( 0) .-        _;\n";
		cout << "   .' `~ =,_    '.\ \/ /.'    _,= ~` `.\n";
		cout << "   ;_        -. _.-)  (-._ .-        _;\n";
		cout << "   : ^~ -.,___.'  (    )  `.___,.- ~^ ;\n";
		cout << "   :        _:     `--'     :_        :\n";
		cout << "    '._,-~ ` :':          :': ` ~-,_.'\n";
		cout << "       '.,_.-`.            .'`-._,.'\n";
		cout << "          :__.-`-.______.-'`-.__;\n";
		cout << "                 //    \\\n";
		cout << "               (((~    ~)))\n";

	}
	if (month == 10)
	{
		cout << "Christmas Day -- December 25\n";
		cout << " 	    | / \n";
		cout << " 	  -->*<-- \n";
		cout << " 	    /_| \n";
		cout << " 	   /_|_| \n";
		cout << " 	  /_/_/_| \n";
		cout << " 	  /_|_|_| \n";
		cout << "    /_/_/_/_| \n";
		cout << "    /_|_|_|_| \n";
		cout << "   /_/_/_/_/_| \n";
		cout << "   /_|_|_|_|_| \n";
		cout << "  /_/_/_/_/_/_| \n";
		cout << "  /_|_|_|_|_|_| \n";
		cout << " /_/_/_/_/_/_/_| \n";
		cout << " 	   [___] \n";
	}
}

int FindTotalDays(int month, int year)
{
	int md;
	int flag;
	md = 0;
	if (month == 11)
	{
		md = 31;
	}
	if (month == 12)
	{
		flag = 0;
		if (year % 400 == 0)
		{
			flag = 1;
		}
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				flag = 1;

			}

		}

		if (flag == 0)
		{
			md = 28;
		}
		else
		{
			md = 29;
		}
	}
	if (month == 1)
	{
		md = 31;
	}
	if (month == 2)
	{
		md = 30;
	}
	if (month == 3)
	{
		md = 31;
	}
	if (month == 4)
	{
		md = 30;
	}
	if (month == 5)//july
	{
		md = 31;
	}
	if (month == 6)
	{
		md = 31;
	}
	if (month == 7)
	{
		md = 30;
	}
	if (month == 8)
	{
		md = 31;
	}
	if (month == 9)
	{
		md = 30;
	}
	if (month == 10)
	{
		md = 31;
	}

	return md;
}

void GetNewInfo1(int &day, int & month, int & year)
{
	string date1;
	char date[11];
	int k, m, y, c, d, hold;
	/*cout << "Enter Day of month";
	cin >> day;
	cout << "Enter month as in number";
	cin >> month;

	//cout << m;
	//cout << endl;

	cout << "Enter year";
	cin >> year;
	//c = y / 100;
	//cout << "c = " << c;
	//cout << endl;
	//d = y - (c * 100);
	//cout << "d = " << d;
	//cout << endl;*/

	cout << "What is the date? ";
	//cin >> date1;
	cin.get(date, 11);
	cin.ignore();
	system("cls");
	month = date[0] + date[1];

	hold = date[0];
	if (hold == 48) {

		if (month == 97) {
			month = 11;
		}
		if (month == 98) {
			month = 12;
		}
		if (month == 99) {
			month = 1;
		}
		if (month == 100) {
			month = 2;
		}
		if (month == 101) {
			month = 3;
		}
		if (month == 102) {
			month = 4;
		}
		if (month == 103) {
			month = 5;
		}
		if (month == 104) {
			month = 6;
		}
		if (month == 105) {
			month = 7;
		}
	}
	else {
		if (month == 97) {
			month = 8;
		}
		if (month == 98) {
			month = 9;
		}
		if (month == 99) {
			month = 10;
		}

	}


	year = (date[6] - 48) * 1000;
	year = year + ((date[7] - 48) * 100);
	year = year + ((date[8] - 48) * 10);
	year = year + ((date[9] - 48) * 1);

	c = year / 100;
	d = year - (c * 100);

	day = (date[3] - 48) * 10;
	day = day + (date[4] - 48);

}

int FindEaster1(int year)
{
	int a, b, c, d, e, f, g, h, i, j, k, m, p, holiday, month;

	a = year % 19;
	b = year / 100;
	c = year % 100;
	d = b / 4;
	e = b % 4;
	f = (b + 8) / 25;
	g = (b - f + 1) / 3;
	h = ((19 * a) + b - d - g + 15) % 30;
	i = c / 4;
	j = c % 4;
	k = (32 + (2 * e) + (2 * i) - h - j) % 7;
	m = (a + (11 * h) + (22 * k)) / 451;
	month = (h + k - (7 * m) + 114) / 31;
	p = (h + k - (7 * m) + 114) % 31;
	holiday = p + 1;

	return holiday;
}

int FindDay1(int day, int &month, int year)
{
	int fint, m, k, c, y;
	//month = month - 2;
	//if (month <= 0)
	//{
	//	month = month + 12;
	//}
	//y = 0;
	//m = 0;

	c = year / 100;
	day = year - (c * 100);
	fint = 1 + ((13 * month - 1) / 5) + day + (day / 4) + (c / 4) - 2 * c;
	fint = fint - 7 * (fint / 7);
	if (fint < 0) {
		fint = fint + 7;
	}

	return fint;
}

string FindMonth1(int month)
{
	int m;
	//m = 0;
	string monthname;

	if (month == 11)
	{
		monthname = "January";
	}
	if (month == 12)
	{
		monthname = "February";
	}
	if (month == 1)
	{
		monthname = "March";
	}
	if (month == 2)
	{
		monthname = "April";
	}
	if (month == 3)
	{
		monthname = "May";
	}
	if (month == 4)
	{
		monthname = "June";
	}
	if (month == 5)
	{
		monthname = "July";
	}
	if (month == 6)
	{
		monthname = "August";
	}
	if (month == 7)
	{
		monthname = "September";
	}
	if (month == 8)
	{
		monthname = "October";
	}
	if (month == 9)
	{
		monthname = "November";
	}
	if (month == 10)
	{
		monthname = "December";
	}
	return monthname;
}

int FindRealMonth1(int month)
{

	return 0;
}

void ShowCalendar1(string monthstr, int year, int maxdays, int startday, int month, int day)
{

	int flag, fint, nd, y, mike, micah, george, cut;

	//mike = -1;
	//micah = -1;
	cout << setiosflags(ios::left || ios::showpoint) << setw(28) << monthstr;
	cout << endl;
	cout << setw(26) << year;
	cout << endl;
	cout << "   S      M      T      W      Th      F     S";
	cout << endl;

	nd = 0;
	//flag = 0;
	cout << "__________________________________________________\n";

	if (startday == 0) {
		startday = 1;
	}

	for (int i = 0; i < 42; i = i + 1) {


		if (i < startday) {
			cout << "|      ";


		}

		if (nd <= maxdays)
		{
			if (i > startday) {


				cout << "|";
				if (nd == day) {
					SetConsoleTextAttribute(console, 10);
				}
				cout << setw(6) << nd;
				nd = nd + 1;

			}




		}

		if (i == startday) {
			nd = 1;
			cout << "|";
			if (nd == day) {
				SetConsoleTextAttribute(console, 10);
			}
			cout << setw(6) << nd;
			nd = nd + 1;
		}



		if (nd > maxdays) {
			//george = mike + 7;
			if (i % 7 == 6) {
				cout << "|";
				break;
			}
			cout << "|      ";


		}

		if (i % 7 == 6 && i != 0)
		{
			SetConsoleTextAttribute(console, 15);
			mike = i;
			cout << "|";
			cout << endl;
			cout << "|      |      |      |      |      |      |      |\n";
			cout << "|      |      |      |      |      |      |      |\n";
			cout << "__________________________________________________\n";

		}

		//if (nd <= maxdays)
		//{
		///if (int(i) > startday) {
		//cout << "|" << setw(6) << nd;
		//if (fint > 0) {
		//if (nd % 7 == (7 - startday)) {
		// || nd == (8 - startday - 1)) 
		//if (mike != -1) {
		//mike = mike + 7;
		//}




		//}

		//flag = 1;
		//}
		//}

		//}cout << endl;

		SetConsoleTextAttribute(console, 15);

	}
	cout << "\n|      |      |      |      |      |      |      |\n";
	cout << "|      |      |      |      |      |      |      |\n";
	cout << "__________________________________________________\n";
	cout << "Legend: \n";

	if (month == 12)
	{

		cout << "Valentine's Day -- February 14\n";
		cout << "           @@@@@@           @@@@@@\n";
		cout << "         @@@@@@@@@@       @@@@@@@@@@\n";
		cout << "      @@@@@@@@@@@@@@   @@@@@@@@@@@@@@\n";
		cout << "    @@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@\n";
		cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "        @@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "          @@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "            @@@@@@@@@@@@@@@@@@@\n";
		cout << "              @@@@@@@@@@@@@@@\n";
		cout << "                @@@@@@@@@@@\n";
		cout << "                  @@@@@@@\n";
		cout << "                    @@@\n";
		cout << "                     @\n";
	}
	if (month == 11)
	{
		cout << "New Years Day -- January 1st\n";
		cout << "		                         .''.\n";
		cout << "	       .''.             *''*    :_\/_:     .\n";
		cout << "	      :_\/_:   .    .:.*_\/_*   : /\ :  .'.:.'.\n";
		cout << "	  .''.: /\ : _\(/_  ':'* /\ *  : '..'.  -=:o:=-\n";
		cout << "	 :_\/_:'.:::. /)\*''*  .|.* '.\'/.'_\(/_'.':'.'\n";
		cout << "	 : /\ : :::::  '*_\/_* | |  -= o =- /)\    '  *\n";
		cout << "	  '..'  ':::'   * /\ * |'|  .'/.\'.  '._____\n";
		cout << "	      *        __*..* |  |     :      |.   |' .--- |\n";
		cout << "	       _*   .-'   '-. |  |     .--'|  ||   | _|    |\n";
		cout << "	    .-'|  _.|  |    ||   '-__  |   |  |    ||      |\n";
		cout << "	    |' | |.    |    ||       | |   |  |    ||      |\n";
		cout << "	 ___|  '-'     '    ""       '-'   '-.'    '`      |____\n";
		cout << "	  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
	if (month == 1)
	{
		cout << "St. Patricks Day -- March 17\n";
		cout << "	          .-.-.\n";
		cout << "	         (     )\n";
		cout << "	       .-.\ : /.-.\n";
		cout << "	      (   .`:`.   )\n";
		cout << "	       (   /|\   )\n";
		cout << "	        ` ` | ` `\n";

	}
	if (month == 2)
	{
		cout << "Easter --";
		cout << "			 / \\n";
		cout << "	        / _ \\n";
		cout << "	       | / \ |\n";
		cout << "	       ||   || _______\n";
		cout << "	       ||   || |\     \\n";
		cout << "	       ||   || ||\     \\n";
		cout << "	       ||   || || \    |\n";
		cout << "	       ||   || ||  \__/\n";
		cout << "	       ||   || ||   ||\n";
		cout << "	        \\_/ \_/ \_//\n";
		cout << "	       /   _     _   \\n";
		cout << "	      /               \\n";
		cout << "	      |    O     O    |\n";
		cout << "	      |   \  ___  /   |\n";
		cout << "	     /     \ \_/ /     \\n";
		cout << "	    /  -----  |  --\    \\n";
		cout << "	    |     \__/|\__/ \   |\n";
		cout << "	    \       |_|_|       /\n";
		cout << "	     \_____       _____/\n";
		cout << "	           \     /\n";
		cout << "	           |     |\n";

	}
	if (month == 3)
	{
		cout << "Memorial Day -- May 28\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  ::::::::::::::::::::;::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	}
	if (month == 4)
	{
		cout << "Flag Day -- June 14th\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  :::::::::::::::::::::::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  | * * * * * * * * *  ::::::::::::::::::::;::::|\n";
		cout << "	  |* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
		cout << "	  |:::::::::::::::::::::::::::::::::::::::::::::|\n";
		cout << "	  |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	}
	if (month == 5)//july
	{
		cout << "4th of July -- July 4\n";
		cout << "			   .-""""""""-.         \n";
		cout << "	         .'       __  \_        \n";
		cout << "	        /        /  \/  \        \n";
		cout << "	       |         \_0/\_0/______     \n";
		cout << "	       |:.          .'       oo`\    \n";
		cout << "	       |:.         /             \    \n";
		cout << "	       |' ;        |             |    \n";
		cout << "	       |:..   .     \_______     |     \n";
		cout << "	       |::.|'     ,  \,_____\   /        \n";
		cout << "	       |:::.; ' | .  '|  ====)_/===;===========;()    \n";
		cout << "	       |::; | | ; ; | |            # # # #::::::\n";
		cout << "	      /::::.|-| |_|-|, \           # # # #::::::\n";
		cout << "	     /'-=-'`  '-'   '--'\          # # # #::::::\n";
		cout << "	    /                    \         # # # #::::::\n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	           H A P P Y               # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	   F O U R T H  O F  J U L Y       # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
		cout << "	                                   # # # # # # #  \n";
	}
	if (month == 6)
	{
		cout << " George's Birthday -- August 16\n";
		cout << "		        ,   ,   ,   ,\n";
		cout << "           , |_,_|_,_|_,_| ,\n";
		cout << "       _,-=|;  |,  |,  |,  |;=-_\n";
		cout << "     .-_| , | , | , | , | , |  _-.\n";
		cout << "     |:  -|:._|___|___|__.|:=-  :|\n";
		cout << "     ||*:  :    .     .    :  |*||\n";
		cout << "     || |  | *  |  *  |  * |  | ||\n";
		cout << " _.-=|:*|  |    |     |    |  |*:|=-._\n";
		cout << "-    `._:  | *  |  *  |  * |  :_.'    -\n";
		cout << " =_      -=:.___:_____|___.: =-     _=\n";
		cout << "    - . _ __ ___  ___  ___ __ _ . -\n";
	}
	if (month == 7)
	{
		cout << " Michael's Birthday -- September 29\n";
		cout << "		        ,   ,   ,   ,\n";
		cout << "           , |_,_|_,_|_,_| ,\n";
		cout << "       _,-=|;  |,  |,  |,  |;=-_\n";
		cout << "     .-_| , | , | , | , | , |  _-.\n";
		cout << "     |:  -|:._|___|___|__.|:=-  :|\n";
		cout << "     ||*:  :    .     .    :  |*||\n";
		cout << "     || |  | *  |  *  |  * |  | ||\n";
		cout << " _.-=|:*|  |    |     |    |  |*:|=-._\n";
		cout << "-    `._:  | *  |  *  |  * |  :_.'    -\n";
		cout << " =_      -=:.___:_____|___.: =-     _=\n";
		cout << "    - . _ __ ___  ___  ___ __ _ . -\n";

	}
	if (month == 8)
	{
		cout << "Halloween -- October 31st\n";
		cout << "		                           .-.\n";
		cout << "                   heehee      /aa \_\n";
		cout << "                             __\-  / )                 .-.\n";
		cout << "                   .-.      (__/    /        haha    _/oo \ \n";
		cout << "                 _/ ..\       /     \               ( \v  /__\n";
		cout << "                ( \  u/__    /       \__             \/   ___)\n";
		cout << "                 \    \__)   \_.-._._   )  .-.       /     \ \n";
		cout << "                 /     \             `-`  / ee\_    /       \_\n";
		cout << "              __/       \               __\  o/ )   \_.-.__   )\n";
		cout << "             (   _._.-._/     hoho     (___   \/           '-'\n";
		cout << "              '-'                        /     \ \n";
		cout << "                                       _/       \    teehee \n";
		cout << "                                      (   __.-._/ \n";
	}
	if (month == 9)
	{
		cout << "Thanksgiving Day -- November 22\n";
		cout << "               _,-- ^^ -.,_\n";
		cout << "         _.-""~^`~-.    .-~`^~""-._\n";
		cout << "     ,=`-._     .----.     _.- `  =,\n";
		cout << "    ;_        -. (0 )( 0) .-        _;\n";
		cout << "   .' `~ =,_    '.\ \/ /.'    _,= ~` `.\n";
		cout << "   ;_        -. _.-)  (-._ .-        _;\n";
		cout << "   : ^~ -.,___.'  (    )  `.___,.- ~^ ;\n";
		cout << "   :        _:     `--'     :_        :\n";
		cout << "    '._,-~ ` :':          :': ` ~-,_.'\n";
		cout << "       '.,_.-`.            .'`-._,.'\n";
		cout << "          :__.-`-.______.-'`-.__;\n";
		cout << "                 //    \\\n";
		cout << "               (((~    ~)))\n";

	}
	if (month == 10)
	{
		cout << "Christmas Day -- December 25\n";
		cout << " 	  \ /                                              \n";
		cout << " 	-->*<--                                                \n";
		cout << " 	    /_\ \n";
		cout << " 	  /_\_\ \n";
		cout << " 	   /_/_/_\ \n";
		cout << " 	    /_\_\_\   \n";
		cout << "       /_/_/_/_\  \n";
		cout << "       /_\_\_\_\   \n";
		cout << "      /_/_/_/_/_\   \n";
		cout << "      /_\_\_\_\_\   \n";
		cout << "      /_/_/_/_/_/_\  \n";
		cout << "      /_\_\_\_\_\_\     \n";
		cout << "     /_/_/_/_/_/_/_\   \n";
		cout << " 	 [___] \n";
	}
}

int FindTotalDays1(int month, int year)
{
	int md;
	int flag;
	md = 0;
	if (month == 11)
	{
		md = 31;
	}
	if (month == 12)
	{
		flag = 0;
		if (year % 400 == 0)
		{
			flag = 1;
		}
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				flag = 1;

			}

		}

		if (flag == 0)
		{
			md = 28;
		}
		else
		{
			md = 29;
		}
	}
	if (month == 1)
	{
		md = 31;
	}
	if (month == 2)
	{
		md = 30;
	}
	if (month == 3)
	{
		md = 31;
	}
	if (month == 4)
	{
		md = 30;
	}
	if (month == 5)//july
	{
		md = 31;
	}
	if (month == 6)
	{
		md = 31;
	}
	if (month == 7)
	{
		md = 30;
	}
	if (month == 8)
	{
		md = 31;
	}
	if (month == 9)
	{
		md = 30;
	}
	if (month == 10)
	{
		md = 31;
	}

	return md;
}

