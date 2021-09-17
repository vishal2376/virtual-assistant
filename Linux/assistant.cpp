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
//--------------constructor---------------
assistant::assistant()
{
  system("mkdir data");
  system("clear");

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
  usleep(t_const * 300);
}

//---------------typing function--------------
void assistant::typing(string t)
{
  speak(t);   //---------- speaking the text
  for (int i = 0; t[i] != '\0'; i++)
  {
    cout << t[i] << flush;
    usleep(20000);
  }

}

//-------------------clock function--------------
void assistant::clock()
{
  string DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  string numDesc[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
  string monthDesc[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  cout << std::boolalpha;
  time_t now = time(0);
  tm*ltm = localtime(&now);
  if (ltm->tm_hour < 12)
    greet = "Good morning";
  else if (ltm->tm_hour >= 12)
    if (ltm->tm_hour > 16)
      greet = "Good evening";
    else
      greet = "Good Afternoon";

  cout << "   " << monthDesc[ltm->tm_mon];
  cout << " " << ltm->tm_mday << numDesc[ltm->tm_mday % 10];
  cout << " " << ltm->tm_year + 1900 ;
  if (DAYS[ltm->tm_wday] == "Monday")
    cout << " (Sunday)";
  else
    cout << " (" << DAYS[ltm->tm_wday - 1] << ")";
  greet += " Vishal";
  cout << "\t\t\t\t\t";
  cout << greet;
  cout << "\n   Time:-" << ( ltm->tm_hour <= 12 ? ltm->tm_hour : ltm->tm_hour - 12);
  cout << ":" << ltm->tm_min << (ltm->tm_hour < 12 ? "am" : "pm");

}




assistant::~assistant()
{

}