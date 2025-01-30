#pragma once
#include<iostream>
#include<string>
#include<limits>
#include"DateLibrary.h"
using namespace std;

class clsInputValidate 
{
    public:
   static int ReadIntNumber(string message)
    {
        int N;
        while(true)
        {
            cin>>N;
            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
            continue;
        }
            return N;
        } 
        
    }
   static bool IsNumberBetween(int number,int number1,int number2)
    {
            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        else if (number > number2 or number<number1)
        {
            return false;
        }
        else return true;
     
    }
   static bool IsNumberBetween(double number,double number1,double number2)
    {
            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        else if (number > number2 or number<number1)
        {
            return false;
        }
        else return true;
     
    }
   static  int ReadIntNumberBetween(int number1,int number2,string message)
    {
        int N;
        while(true)
        {
            cin>>N;

            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Inter a valid number! ";
            continue;
        }
        else if (N > number2 or N<number1)
        {
            cout<<message;
            continue;
        }
         return N;
        } 
       
    }
 static   double ReadDblNumberBetween(double number1,double number2,string message)
    {
        double N;
        while(true)
        {
            cin>>N;
            
            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Inter a valid number! ";
            continue;
        }
        else if (N > number2 or N<number1)
        {
            cout<<message;
            continue;
        }
         return N;
        } 
       
    }
 static   double ReadDblNumber(string message)
    {
        double N;
        while(true)
        {
            cin>>N;
            if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << message;
            continue;
        }
            return N;
        } 
        
    }
    static bool IsValideDate(clsDate Date) 
       { 
        return clsDate::IsValidateDate(Date);  
       }
    static bool IsDateBetween(clsDate Date1 , clsDate Date2, clsDate Date3)
    {
        return clsDate::IsDateBetween(Date1,Date2,Date3);
    }    
    
};