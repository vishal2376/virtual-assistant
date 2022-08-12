/*
----------------------------------------------------------------------------
               Project title   : Hydron(virtual assistant)
               Made By         : Vishal Singh
               Written in      : C++
               started project : 27 December , 2018
               Platform        : Linux
               Total Code      : 700+ Lines
----------------------------------------------------------------------------
*/


//-------------------main.c++--------------------

#include "assistant.h"

using namespace assistant;

#define t_const 1000

//------------------global variables----------------
string input;

int pos , l_pos, cnt = 0;
string m_word , s_word;
int s_count = 0;

string user_name;

//---------------------all functions-------------------------

void check();   //compare the user input with defined commands
void line();      // create new line
void repeat();     //ask user input again.
void shutdown_timer(int);
//void display(int);
void player(string);  //search the song from file(songs.txt) then play the song.
void help();          //show commands
void hacking();
void install(string); // create music folders
void block(string);  //block the websites
void openf(string);   // open the file directory
void lists(string);   //show song list
void convert(string&);   //convert 'space( )' to 'underscore'( _ ) and lowercase string
void srch(string, string extra = "");
void update_song(string);   //copy song name from different files(list.txt) file into one file(songs.txt)
void settings(); // user settings

int main()
{
	init(); // init hydron

	user_name = get_uname();

	repeat();

	return 0;
}

//-----------------------------Repeat function-------------------------//
void repeat()
{
	// system("color a");
	system("clear");
	local_clock();
	cout << " \n\n\nType Here  ---> ";
	cin.clear();
	getline(cin, input);  // get command from user

	pos = input.find(" ");
	m_word = input.substr(0, pos); //main command word
	l_pos = input.find('\0');
	s_word = input.substr(pos + 1, l_pos); //rest word


//-----------check conditions--------------//
	check();
}

//----------------------------check function---------------------------//
void check()
{
	if (m_word == "hi" || m_word == "hey" || m_word == "hello" || m_word == "hlo")
	{
		typing("Hi " + user_name + ", how can I help you..");
	}
	else if (m_word == "play")
	{
		if (input == "play" || input == "play " || s_word == " " || s_word == "  " || s_word == "   ")
		{
			speak("Sorry " + user_name + " ,you does not enter song name");
			// tutorial("play");
		}
		else
		{
			player(s_word);
		}
	}

	else if (m_word == "update" || m_word == "updating")
	{
		system("clear");
		line();
		typing("Updating the song list...");
		usleep(t_const * 100);
		system("clear");
		line();
		typing("Please wait");
		update_song("punjabi");
		update_song("english");
		update_song("hindi");
		update_song("others");
		system("clear");
		remove("data/songs.txt");
		rename("data/temp.txt", "data/songs.txt");
		line();
		typing("All songs are updated in the file");
	}
	else if (input == "exit" || input == "q" || input == "quit")
	{
		speak("Good bye," + user_name);
		usleep(t_const * 600);
		cout << "\n\n\n\n\n\n\t\t\t\t\t";
		typing("Created By : Vishal Singh");
		usleep(t_const * 1000);
		system("clear");
		exit(1);
	}
	else if (input == "find ip" || input == "find my ip" || m_word == "ip")
	{
		typing("Finding your IP address");
		system("ipconfig");
		system("pause");
	}
	else if (m_word == "shutdown" || m_word == "restart")
	{
		typing("Your Pc will ");
		typing(m_word);
		shutdown_timer(5);
		speak("Now , I am going to sleep");
		if (m_word == "shutdown")
			system("shutdown /s");
		else
			system("shutdown /r");
		usleep(t_const * 10);
		exit(1);
	}

	else if (m_word == "what" || m_word == "who" || m_word == "how" || m_word == "when" || m_word == "where" || m_word == "why")
	{
		if (input == "what is your name")
		{
			typing("My name is hydron.");
		}
		else if (input == "who are you" || input == "who created you" || input == "who made you")
		{
			typing("I am Hydron, a virtual assistant");
			usleep(t_const * 300);
			line();
			typing("I was created on 27 December ,2018");
			usleep(t_const * 300);
		}
		else
			srch(input);
	}

	else if (input == "settings" || input == "setting" || input == "set")
		settings();

	else if (m_word == "song" || m_word == "music")
		srch(s_word, "song");

	else if (input == "install")
	{
		system("mkdir My_beat");

		install("hindi");
		install("english");
		install("punjabi");
		install("others");
		cout << "\nCreating folders...";
		usleep(t_const * 200);
		cout << "\nCreating files...";
		usleep(t_const * 200);
		system("clear");

		typing("\nAll files are installed");
		usleep(t_const * 300);
	}

	else if (input == "help")
		help();

	else if (m_word == "movie")
		srch(s_word, "movie");

	else if (m_word == "pdf")
		srch(s_word, "pdf");

	else if (m_word == "search")
		srch(s_word);

	else if (m_word == "cmd")
		system(s_word.c_str());

	else if (input == "start hacking" || input == "hacking lab" || input == "hackingzone" || input == "hacking tools" || m_word == "hack")
	{
		hacking();
	}

	else if (m_word == "list")
	{
		if (s_word == "all songs" || s_word == "songs")
			lists("data/songs.txt");
	}
	/*else if(input=="unhide data"||input=="unhide data folder")
	      {
	        system("attrib -s -h data");
	      }
	else if(input=="hide data"||input=="hide data folder")
	      {
	        system("attrib +s +h data");
	      }
	      */

	else if (m_word == "block")
	{
		block(s_word);
	}
	else if (m_word == "yt" || m_word == "youtube" || m_word == "watch")
	{
		srch(s_word, "youtube");
	}

	else if (m_word == "open")
	{
		if (s_word == "chrome" || s_word == "google chrome")
		{
			system("chrome");
		}
		else if (s_word == "mozilla" || s_word == "firefox")
		{
			system("firefox");
		}
		else
			openf(s_word);
	}

	else
	{
		speak("Sorry " + user_name + ", unknown command...");
		cnt++;
		if (cnt >= 3)
		{	usleep(t_const * 600);
			speak("I think ");
			usleep(t_const * 500);
			speak("you are a new user");
			usleep(t_const * 600);
			speak("You need some help...");
			help();
			//typing("do you want some tutorial(y/n)");
			//if yes then tutorial();
		}
	}

	usleep(t_const * 700);
	repeat();
}

//-----------------------user settings---------------------
void settings()
{
	string un;
	int ss, sa, sp, ts;

	cout << "\n\n";
	typing("Enter data in the following given format:\n");
	cout << "\n1.user name(single word only)";
	cout << "\n2.speak speed(in WPM)";
	cout << "\n3.speak volume(0-200)";
	cout << "\n4.speak pitch(0-99)";
	cout << "\n5.typing speed(in ms)";
	cout << "\n\nExample 1:\n";
	cout << "Vishal 160 100 40 40";
	cout << "\n\nExample 2:\n";
	cout << "Vishal 150 120 60 30";
	cout << "\n\n\n---> ";
	cin >> un >> ss >> sa >> sp >> ts;
	if ((sa <= 200 && sa > 0) && (sp <= 99 && sp > 0 ))
	{
		save_settings(un, ss, sa, sp, ts);
		typing("Restart hydron to see changes");
	}
	else
	{
		speak("Something went wrong");
	}
	cin.ignore('\n');
}

//------------------------------player function------------------------//
void player(string item)
{
	ifstream file;
	string song_name;
	song_name = item;
	convert(item);
	char song[30], singer[30];
	char path[90] = "xdg-open My_beat/";
	file.open("data/songs.txt", ios::app);
	while (file >> song >> singer)
	{
		if (song == item)
		{
			typing("Playing the song ");
			usleep(t_const * 150);
			typing(song_name);
			strcat(path, singer);
			strcat(path, "/");
			strcat(path, song);
			strcat(path, ".mp3");
			system(path);
			break;
		}
	}
	usleep(t_const * 150);
	system("clear");
	//--------------if song not found------------------
	if (song != item)
	{
		typing(song_name);
		typing(" not found.");
		if (s_count % 3 == 0)
		{
			usleep(t_const * 200);
			system("clear");
			speak("But you can download the song by using the command");
			usleep(t_const * 1300);
			line();
			typing("song ");
			typing(song_name);
		}
		s_count++;
	}

	file.close();
}

//------------------------------convert string-------------------------//
void convert(string &c)
{

	for (int i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == ' ')
			c[i] = '_';
		c[i] = tolower(c[i]);
	}
}

//------------------------------update the song list-------------------//
void update_song(string name)
{
	fstream a, b;
	char word[20], old[20];
	system("clear");
	a.open("My_beat/" + name + "/list.txt");
	b.open("data/temp.txt", ios::app | ios::ate);
	while (a >> word)
	{
		b << word << " " << name << "\n";
	}
	b.close();
	a.close();
}

//------------------------timer function--------------

// function to display the timer
void displayClock(int seconds)
{
	int h, m;
	h = m = 0;
	// system call to clear the screen
	system("clear");
	cout << "\n\n";
	cout << setfill(' ') << setw(75) << "	        TIMER	      	\n";
	cout << setfill(' ') << setw(75) << " --------------------------\n";
	cout << setfill(' ') << setw(29);
	cout << "| " << setfill('0') << setw(2) << h << " hrs | ";
	cout << setfill('0') << setw(2) << m << " min | ";
	cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
	cout << setfill(' ') << setw(75) << " --------------------------\n";
}

void shutdown_timer(int t)
{
	while (t)
	{
		displayClock(t);
		usleep(t_const * 900);
		t--;
	}
}

//----------------online srch and also 0download songs----------------

void srch(string query, string extra)
{
	for (int i = 0; query[i] != '\0'; i++)
	{
		if (query[i] == ' ')
			query[i] = '+';
	}

	usleep(t_const * 200);
	system("clear");
	line();
	typing("Cheking internet connection...");
	if (s_count % 5 == 0)
	{
		line();
		usleep(t_const * 90);
		cout << "Colleting information..\n";
		usleep(t_const * 50);
		cout << "securing the data..\n";
		usleep(t_const * 30);
		cout << "clear the cookies..\n";
		usleep(t_const * 100);
		system("ipconfig");
		line();
		typing("All protocols are secured...");
	}

	usleep(t_const * 250);
	speak("Connecting to your browser.");
	string url;

	if (extra == "youtube")
	{
		url = "xdg-open https://www.youtube.com/results?search_query=";
		url += query;
		system(string(url).c_str());
	}
	else if (extra == "song")
	{
		// for international songs
		url = "xdg-open https://en.muzmo.org/search?q=";
		url += query;
		system(string(url).c_str());
		usleep(t_const * 50);

		url = "xdg-open https://m.soundcloud.com/search?q=";
		url += query;
		system(string(url).c_str());

		//only for hindi and punjabi songs

		url = "xdg-open https://www.google.com/search?q=";
		url += query;
		url += "+djpunjab";
		system(string(url).c_str());
		usleep(t_const * 50);
	}
	else if (extra == "pdf")
	{
		url = "xdg-open https://www.google.com/search?q=filetype%3Apdf+";
		url += query;
		system(string(url).c_str());
	}
	else if (extra == "movie")
	{

		url = "xdg-open https://www.google.com/search?q=";
		url += query;
		url += "+-inurl%3A(htm%7Chtml%7Cphp%7Cpls%7Ctxt)+intitle%3Aindeof+%22last+modified%22(mp4%7Cmkv%7Cwma%7Caac%7Cavi)";
		system(string(url).c_str());
	}
	else
	{
		url = "xdg-open https://www.google.com/search?q=";
		url += query;
		system(string(url).c_str());
	}

	s_count++;
}
//-----------------newline function----------------
void line()
{
	cout << "\n";
}

//----------------install files---------------------
void install(string fold)
{
	fstream file;
	string foldname, filename;
	foldname = "mkdir My_beat/";

	foldname += fold;
	system(string(foldname).c_str());

	filename = "My_beat/";
	filename += fold;
	filename += "/list.txt";
	file.open(filename, ios::app);
	file.close();
}

//---------------list the file texts------------------
void lists(string link)
{
	fstream file;
	int cnt = 0;
	char word[50], old[50];
	file.open(link);
	while (file >> word >> old)
	{
		cnt++;
		cout << word << "\n";
	}
	cout << "\n\t\tTotal songs available :" << cnt << endl;
	string p, s = "Only ";
	p = cnt;
	s += p;
	s += "songs are available";
	if (cnt != 0)
	{
		speak(s);
	}
	file.close();
	system("pause");
}

//----------------------hacking zone------------------
void hacking()
{
	system("clear");
	system("color f");
	speak("You are Welcome in the Hacking Lab");
	cout << setfill(' ') << setw(50) << "      ________       \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |        |      \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |  #   # |      \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |  #   # |      \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |   # #  |      \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |    #   |      \n";
	usleep(t_const * 100);
	cout << setfill(' ') << setw(50) << "     |________|      \n";
	line();
	usleep(t_const * 1000);
	system("color c");
	cout << setfill(' ') << setw(50) << " Vishal Hacking Lab  \n";
	usleep(t_const * 1000);
	line();
	typing("Still in development...");
}

void block(string website)
{
	fstream file;
	file.open("C:/WINDOWS/system32/drivers/etc/hosts", ios::app);
	file << "\n127.0.0.2 www." << website;
	typing("Blocking the website..");
	file.close();
}

void openf(string location)
{
	string path = "xdg-open ", item = location;
	convert(item);
	path += item;
	typing("Open....");
	typing(location);
	system(string(path).c_str());
}

//----------------------help file---------------------
void help()
{
	cnt = 0;
	speak("you can use only these cammands");
	system("clear");
	cout << "\n\n";
	system("color f");
	line();
	cout << setfill(' ') << setw(75) << "----------------------------\n";
	cout << setfill(' ') << setw(75) << "          Commands          \n";
	cout << setfill(' ') << setw(75) << "--------------------------\n\n";
	cout << setfill(' ') << setw(75) << "    1.search (any question)  \n";
	cout << setfill(' ') << setw(75) << "    2.open (google,mozilla)  \n";
	cout << setfill(' ') << setw(75) << "    3.block (website name)   \n";
	cout << setfill(' ') << setw(75) << "    4.song (song name)       \n";
	cout << setfill(' ') << setw(75) << "    5.update                 \n";
	cout << setfill(' ') << setw(75) << "    6.watch (videoname)      \n";
	cout << setfill(' ') << setw(75) << "    7.pdf (pdfname)          \n";
	cout << setfill(' ') << setw(75) << "    8.movie (moviename)      \n";
	cout << setfill(' ') << setw(85) << "    9.what/how/where/who/why (question)\n";
	cout << setfill(' ') << setw(75) << "   10.cmd (cmd commands)     \n";
	cout << setfill(' ') << setw(75) << "   11.find my ip             \n";
	cout << setfill(' ') << setw(75) << "   12.play (song name)       \n";
	cout << setfill(' ') << setw(75) << "   13.list songs             \n";
	cout << setfill(' ') << setw(75) << "   10.exit/quit/q            \n";
	cout << setfill(' ') << setw(75) << "   11.shutdown/restart       \n";
	cout << setfill(' ') << setw(75) << "   12.install                \n";
	usleep(t_const * 3000);
}
