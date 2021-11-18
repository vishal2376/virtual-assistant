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



#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <ctype.h>
#include <ctime>
#include <thread>

using namespace std;


namespace assistant
{
void init();

void banner();
void greeting();
void local_clock();

void typing(string);
void speak(string);

void load_settings();
}

// namespace settings
// {
// string u_name = "Vishal";

// // int s_speed; //speaking speed
// // int s_volume;
// // int s_pitch;

// // int t_speed; //typing speed
// }

#endif // ASSISTANT_H