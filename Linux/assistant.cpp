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

//------------global var----------------
string greet;

string u_name;
int s_pitch;
int s_speed;
int s_volume;
int t_speed;

//--------------start---------------
void assistant::init()
{
	system("mkdir data");
	system("clear");

	load_settings();
	local_clock();
	banner();
	greeting();
}


//---------------banner----------------
void assistant::banner()
{
	system("clear");
	cout << "\n\n\n\n";
	cout << "\n\t\t\t██╗  ██╗██╗   ██╗██████╗ ██████╗  ██████╗ ███╗   ██╗";
	usleep(t_const * 30);
	cout << "\n\t\t\t██║  ██║╚██╗ ██╔╝██╔══██╗██╔══██╗██╔═══██╗████╗  ██║";
	usleep(t_const * 30);
	cout << "\n\t\t\t███████║ ╚████╔╝ ██║  ██║██████╔╝██║   ██║██╔██╗ ██║";
	usleep(t_const * 30);
	cout << "\n\t\t\t██╔══██║  ╚██╔╝  ██║  ██║██╔══██╗██║   ██║██║╚██╗██║";
	usleep(t_const * 30);
	cout << "\n\t\t\t██║  ██║   ██║   ██████╔╝██║  ██║╚██████╔╝██║ ╚████║";
	usleep(t_const * 30);
	cout << "\n\t\t\t╚═╝  ╚═╝   ╚═╝   ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝";
	usleep(t_const * 30);
	cout << "\n";
	usleep(t_const * 100);
}


//------------load user settings--------
void assistant::load_settings()
{
	ifstream file;
	file.open(".user-settings", ios::in);
	if (file.good())
	{
		string name;

		while (!file.eof())
		{
			file >> u_name >> s_speed >> s_volume >> s_pitch >> t_speed;
		}

	}
	else
	{
		u_name = "Vishal";
		s_speed = 160;
		s_pitch = 40;
		s_volume = 100;
		t_speed = 40;
	}
	file.close();
}

void assistant::save_settings(string un, int ss, int sa, int sp, int ts)
{
	ofstream file;
	file.open(".user-settings", ios::out);

	file << un << " " << ss << " "  << sa << " "  << sp << " "  << ts;

	file.close();
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
	string cmd = "espeak -a";
	cmd += to_string(s_volume);
	cmd += " -p";
	cmd += to_string(s_pitch);
	cmd += " -s";
	cmd += to_string(s_speed);
	cmd += " \"";
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
		usleep(t_const * t_speed); // speed 40ms
	}

	th.join();//finish thread after complete TTS (text to speech)
}

//-----------return user name-----------
string assistant::get_uname()
{
	return u_name;
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
	greet += " ";
	greet += u_name;
	cout << "\t\t\t\t\t";
	cout << greet;
	cout << "\n   Time:-" << ( l_time->tm_hour <= 12 ? l_time->tm_hour : l_time->tm_hour - 12);
	cout << ":" << l_time->tm_min << (l_time->tm_hour < 12 ? "am" : "pm");

}