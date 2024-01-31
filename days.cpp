#include<iostream>
#include<string>
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
   int l = f.length();
   cout << "checking for addition " << l << endl;
   for (int i = 0; i < l; i++)
        if (isdigit(f[i]) == false)
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
   int t = 0;
   string d;
   string m;
   string y;
   cout << "enter DOB in DD MM YYYY format" << endl;
   cin >> d>> m >> y;
   while (!isvalid(d,m,y))
   {
     cout << "dude enter any date between 1 1 1 till today in DD MM YYYY format" << endl;
     cin >> d >> m >> y;
   }
   cout << "is it leap " << isleap(yyyy) << endl;
   cout << "days in the month " << daysinmonth(mm,yyyy) << endl;
   cout << "hit 1 to calculate again" << endl;
   cin >> t;
   return(t);
}

int main()
{
cout << "I solemnly swear that you're on the right path" << endl;
sleep(0);
cout << "let's check the number of days since birth" << endl;
sleep(0);
while(io())
{
  io();
}
return(0);
}


