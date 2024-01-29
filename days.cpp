#include<iostream>
#include<ctime>
#include<unistd.h>

using namespace std;
int dob;
int dd;
int mm;
int yyyy;

int main()
{
cout << "I solemnly swear that you're on the right path" << endl;
sleep(3);
cout << "let's" << endl;
sleep(1);
cout << "check" << endl;
sleep(1);
cout << "how" << endl;
sleep(1);
cout << "many" << endl;
sleep(1);
cout << "days" << endl;
sleep(1);
cout << "you" << endl;
sleep(1);
cout << "have" << endl;
sleep(1);
cout << "lived" << endl;
sleep(1);
cout << "so" << endl;
sleep(1);
cout << "far" << endl;
sleep(2);
cout << "enter DOB in DDMMYYYY format" << endl;
cin >> dob;
time_t now = time(0);
char* date_time = ctime(&now);
cout << "born on" << dob << "current date" << date_time << endl;
return(0);
}
