/*
----------------------------------------------------------------------------
               Project title   : Hydron(virtual assistant)
               Made By         : Vishal Singh
               Written in      : C++
               Started project : 27 December , 2018
               Platform        : Windows
               IDE used        : Codeblocks
               Last Modified   : 20 December , 2020
               Total Code      : 700+ Lines
 ----------------------------------------------------------------------------
*/


//---------------assistant.c++-----------------
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cstring>
#include <ctype.h>
#include<windows.h>
#include<ctime>
#include "assistant.h"

using namespace std;

string greet;
//--------------constructor---------------
assistant::assistant()
{

 system("md data");
 system("attrib +s +h data");
 system("cls");
 system("title   Hydron");

}

//----------greeting function--------------
void assistant::greeting()
{
    system("color a");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t";
    cout<<"Welcome to the Hydron ";
    Sleep(300);
    speak(greet);
    system("color 0c");
    Sleep(400);
}

//--------------speak function--------------
void assistant::speak(string s)
{
ofstream file;
file.open("data//speak.vbs",ios::out);
file<<"dim s";
file<<"\nset s = createObject(\"sapi.spvoice\")";
file<<"\ns.speak \""<<s<<"\"";
file.close();
system("start data//speak.vbs");
Sleep(300);
}

//---------------typing function--------------
void assistant::typing(string t)
{
    speak(t);   //----------for speaking the text
for (int i=0;t[i]!='\0';i++)
   {
     cout<<t[i];
     Sleep(65);
   }

}

//-------------------clock function--------------
void assistant::clock()
{
string DAYS[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
string numDesc[]={"th","st","nd","rd","th","th","th","th","th","th"};
string monthDesc[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    cout << std::boolalpha;
    time_t now = time(0);
    tm*ltm = localtime(&now);
    if(ltm->tm_hour < 12)
        greet="Good morning";
    else if (ltm->tm_hour >=12)
           if(ltm->tm_hour >16)
            greet="Good evening";
           else
            greet="Good Afternoon";

    cout <<"   "<<monthDesc[ltm->tm_mon];
    cout <<" "<<ltm->tm_mday <<numDesc[ltm->tm_mday%10];
    cout <<" "<<ltm->tm_year+1900 ;
    if (DAYS[ltm->tm_wday]=="Monday")
        cout<<" (Sunday)";
    else
        cout << " (" << DAYS[ltm->tm_wday-1]<<")";
    greet += " Vishal";
    cout<<"\t\t\t\t\t\t\t\t\t";
    cout<<greet;
    cout << "\n   Time:-"<<( ltm->tm_hour <= 12 ?ltm->tm_hour : ltm->tm_hour-12);
    cout <<":"<< ltm->tm_min<<(ltm->tm_hour < 12 ? "am":"pm");

}




assistant::~assistant()
{
    system("attrib +s +h data");
}