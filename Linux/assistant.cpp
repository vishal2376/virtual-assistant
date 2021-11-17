/*
----------------------------------------------------------------------------
               Project title   : Hydron(virtual assistant)
               Made By         : Vishal Singh
               Written in      : C++
               Started project : 27 December , 2018
               Platform        : Linux
               Total Code      : 700+ Lines
 ----------------------------------------------------------------------------
*/


//---------------assistant.c++-----------------

#include "assistant.h"

#define t_const 1000

string greet;
//--------------start---------------
void assistant::start()
{
	system("mkdir data");
	system("clear");
	// update_settings();
}

//-----------update settings-------------
void assistant::update_settings()
{

}

//----------greeting function--------------
void assistant::greeting()
{
	cout << "\n";
	usleep(t_const * 300);
	speak(greet);
	usleep(t_const * 400);
}

//--------------speak function--------------
void assistant::speak(string s)
{
	string cmd = "espeak \"";
	cmd += s;
	cmd += "\"";

	system(cmd.c_str());

}

//---------------typing function--------------
void assistant::typing(string t)
{

	thread th(assistant::speak, t); //using thread for TTS

	for (int i = 0; t[i] != '\0'; i++)
	{
		cout << t[i] << flush;
		usleep(40000); // speed 40ms
	}

	th.join();//finish thread after complete TTS (text to speech)
}

//-------------------clock function--------------
void assistant::local_clock()
{
	string day[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	string day_no[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
	string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	time_t now = time(0);

	tm *l_time = localtime(&now);

	if (l_time->tm_hour < 12)
		greet = "Good morning";
	else if (l_time->tm_hour >= 12)
		if (l_time->tm_hour > 16)
			greet = "Good evening";
		else
			greet = "Good Afternoon";

	cout << "   " << month[l_time->tm_mon];
	cout << " " << l_time->tm_mday << day_no[l_time->tm_mday % 10];
	cout << " " << l_time->tm_year + 1900 ;
	if (day[l_time->tm_wday] == "Monday")
		cout << " (Sunday)";
	else
		cout << " (" << day[l_time->tm_wday - 1] << ")";
	greet += " Vishal";
	cout << "\t\t\t\t\t";
	cout << greet;
	cout << "\n   Time:-" << ( l_time->tm_hour <= 12 ? l_time->tm_hour : l_time->tm_hour - 12);
	cout << ":" << l_time->tm_min << (l_time->tm_hour < 12 ? "am" : "pm");

}