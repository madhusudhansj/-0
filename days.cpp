#include<iostream>
#include<string>
#include<limits>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;
int tyears;
int tmonths;
int days;
int dd;
int mm;
int yyyy;
time_t tnow = time(0);
struct tm now = *localtime(&tnow);
int cyyyy = now.tm_year + 1900;
int cmm = now.tm_mon + 1;
int cdd = now.tm_wday;

bool isvalid(string d, string m, string y)
{
   string f = d+m+y;
   cout << "checking for valid input . . . "<< endl;
   for (unsigned int i = 0; i < f.size(); i++)
        if (!isdigit(f[i]))
           return(0);
   dd = stoi(d);
   mm = stoi(m);
   yyyy = stoi(y);           
   return(dd >0 && dd <= 31 && mm > 0 && mm <= 12 && yyyy > 0 && yyyy <= cyyyy);
}

bool isleap(int y)
{
   return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int daysinmonth(int m, int y)
{  
   const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   return((m==2 && isleap(y)) ? 29 : daysPerMonth[m]); 
}

int totaldays()
{
   return(0);
}

bool io()
{
   char t;
   const char t2 = 'y';
   string d;
   string m;
   string y;
   cout << "enter DOB in DD MM YYYY format" << endl;
   cin.clear();
   cin >> d>> m >> y;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   while (!isvalid(d,m,y))
   {
     cout << "dude enter any date between 1 1 1 till today in DD MM YYYY format" << endl;
     cin.clear();
     cin >> d >> m >> y;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   cout << "is it leap " << isleap(yyyy) << endl;
   cout << "days in the month " << daysinmonth(mm,yyyy) << endl;
   cout << "hit y to calculate again or any key to exit" << endl;
   cin.clear();
   cin >> t;
   cout << "checking why t is stuck at y " << t << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return((t == t2) ? 1 : 0);
}

int main()
{
cout << "i'm just hooked buddy, check this out" << endl;
sleep(0);
cout << "let's check the number of days since birth" << endl;
sleep(0);
int again = 1;
while(again)
{
  again = io();
}
return(0);
}


