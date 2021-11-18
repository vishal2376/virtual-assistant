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

//-------------main group--------------
namespace assistant
{
void init();
void load_settings();

void banner();
void greeting();
void local_clock();

void typing(string);
void speak(string);

}

#endif // ASSISTANT_H