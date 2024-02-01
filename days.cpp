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
int cy = now.tm_year + 1900;
int cm = now.tm_mon + 1;
int cd = now.tm_mday;

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
   if(yyyy >= cy && mm >= cm && dd >= cd)
   {
      cout << "i don't speak to unborn bruh" << endl;
      return(0);
   }           
   return(dd >0 && dd <= 31 && mm > 0 && mm <= 12 && yyyy > 0 && yyyy <= cy);
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

int totaldays(int d, int m, int y)
{
   days = 0;
   cout << d << " "<< m << " "<<y<< " till today is -> ";
   // calculating days from start to end
   if(y < cy)
   {
     days += daysinmonth(m,y) - d;
     days += now.tm_yday;
     for(int i = 12; i>m ; i--)
      days += daysinmonth(i,y);
   }  
   //calculating days from birth year till previous year
   for(int i= cy-1;i>y;i--)
     days += (isleap(i)? 366:365);
   //calculating days since january of current year
   if(y == cy)
   {
      days += daysinmonth(m,y) - d;
      days += cd -1;
      for(int i = m+1; i < cm; i++)
         days += daysinmonth(i,y); 
   }  
   return(days);
  
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
   cout << "days since " << totaldays(dd,mm,yyyy) << endl;   
   cout << "hit y to calculate again or any key to exit" << endl;
   cin.clear();
   cin >> t;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return((t == t2) ? 1 : 0);
}

int main()
{
cout << "i'm just hooked buddy, check this out" << endl;
sleep(0);
cout << "it is " << ctime(&tnow) << endl;
cout << "let's check the number of days since birth" << endl;
sleep(0);
int again = 1;
while(again)
{
  again = io();
}
return(0);
}


