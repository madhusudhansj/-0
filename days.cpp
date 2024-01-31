#include<iostream>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;
int l = 1;
int days;
int dd;
int mm;
int yyyy;
time_t tnow = time(0);
struct tm now = *localtime(&tnow);
int cyyyy = now.tm_year +1900;
int cmm = now.tm_mon +1;
int cdd = now.tm_wday;
void length()
{
    if(dd >0 && dd <= 31 && mm > 0 && mm <= 12 && yyyy > 0 && yyyy <= cyyyy)
      l=0;
    else
      l=1;  
}



int main()
{
cout << "I solemnly swear that you're on the right path" << endl;
sleep(0);
cout << "let's check the number of days since birth" << endl;
sleep(0);
cout << "enter DOB in DD MM YYYY format" << endl;
cin >> dd >> mm >> yyyy;
length();
while (l)
{
    cout << "dude enter any date between 1 1 1 till today in DD MM YYYY format" << endl;
    cin >> dd >> mm >> yyyy;
    length();
}
cout << dd << endl;
cout << mm << endl;
cout << yyyy << endl;
cout << cyyyy - yyyy << endl;
return(0);
}

