#include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>
#include"DateLibrary.h"

using namespace std;
int main()
{
   clsDate Date1;   
     Date1.Print(); 
     cout<<endl;
     clsDate Date2("31/1/2022");  
        Date2.Print();
         cout<<endl;
         clsDate Date3(20, 12, 2022);   
          Date3.Print(); 
          cout<<endl;
          clsDate Date4(250,2022);   
            Date4.Print();   
              cout<<endl;
              Date1.IncreaseDateByOneMonth();   
                Date1.Print(); 
                cout<<endl;
                Date3.PrintYearCalendar();
                cout<<endl;
                cout << Date2.IsValidateDate() << endl;
                cout<<endl;
                cout << "My Age InDays:" <<   clsDate::CalculateMyAgeInDays(  Date2 );
}