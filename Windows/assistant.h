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
#include <process.h>
#include <windows.h>

using namespace std;

class assistant
{

public:
  assistant();
  ~assistant();
  void greeting();
  void typing(string);
  void clock();
  void speak(string);

};

#endif // ASSISTANT_H