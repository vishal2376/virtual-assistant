/*
----------------------------------------------------------------------------
               Project title : hydron(virtual assistant)
               Made By       : Vishal Singh
               Written in    : c++ and vbs(few lines)
               Start project : 27 December , 2018
               Platform      : Windows
               IDE used      : Codeblocks
 ----------------------------------------------------------------------------
*/


#ifndef ASSISTANT_H
#define ASSISTANT_H
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
