#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class clsDate{
    private:
  struct stDate
{
short Year;
short Month;
short Day;
};
  stDate _Date;    


    public:
  
    clsDate()
{
      time_t now = time(0);
        string Date;
        char buffer[80]; // Allocate enough space for formatted date string
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", localtime(&now));  // Use strftime for formatted date
        Date = buffer;
        _Date=StringToDate(Date);
}

    clsDate(string Date)
    {
        _Date=StringToDate(Date);
    }
    
    clsDate(short d,short m,short y)
    {
        _Date.Day=d;
        _Date.Month=m;
        _Date.Year=y;
    }
    clsDate(short DaysOrderInYear, short Year)
    {
        _Date=GetDateFromDayOrderInAYear( DaysOrderInYear,  Year);
    }

    stDate GetDate()
    {
        return _Date;
    }
   static stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Year++;
        Date.Month = 1;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

void IncreaseDateByOneMonth()
{
    _Date= IncreaseDateByOneMonth( _Date);
}

static  clsDate IncreaseDateByOneDay(clsDate Date) 
{
if (IsLastDayInMonth(Date)) 
{
if (IsLastMonthInYear(Date._Date.Month)) 
{
Date._Date.Month = 1;
Date._Date.Day = 1; 
Date._Date.Year++; 
}
else
{
Date._Date.Day = 1; 
Date._Date.Month++; 
}
}
else
{
Date._Date.Day++;
}
return Date; 
}

void IncreaseDateByOneDay()
{
   *this=IncreaseDateByOneDay(*this);
}

static bool IsLastDayInMonth(clsDate Date)
{
return (Date._Date.Day == NumberOfDaysInAMonth(Date._Date.Month, Date._Date.Year)); 
}
bool IsLastDayInMonth()
{
    return  IsLastDayInMonth( *this);
}
static bool IsLastMonthInYear(short Month) 
{
return (Month == 12); 
}
bool IsLastMonthInYear( )
{
    return  IsLastMonthInYear(_Date.Month);
}

static string DateToString(clsDate Date)
    { 
        return  to_string(Date._Date.Day) + "/" + to_string(Date._Date.Month) + "/" + to_string(Date._Date.Year);  
    } 
string DateToString() 
    { 
    return  DateToString(*this);
    }


static int GetDifferenceInDays(clsDate Date1 , clsDate Date2 , bool IncludeEndDay= false)
{
int Days = 0;
while (IsDate1BeforeDate2(Date1, Date2))
{
Days++;
Date1 = IncreaseDateByOneDay(Date1);
}
return IncludeEndDay ? ++Days : Days;
}
static clsDate GetSystemDate()
{
clsDate Date;
time_t t = time(0);
tm* now = localtime(&t);
Date._Date.Year = now->tm_year + 1900;
Date._Date.Month = now->tm_mon + 1;
Date._Date.Day = now->tm_mday;
return Date;
}

     int CalculateMyAgeInDays()
     {
        return  GetDifferenceInDays(*this , GetSystemDate() , false);
     }
     static int CalculateMyAgeInDays(clsDate Date)
     {
        return  GetDifferenceInDays(Date , GetSystemDate() , false);
     }

 static  bool IsLeapYear(short Year)
{
      return (Year % 4 == 0 && Year % 100 != 0) || 
(Year % 400 == 0);
}
bool IsLeapYear()
{ 
    return  IsLeapYear(_Date.Year);
}
static short NumberOfDaysInAMonth(short Month, short Year)
{
if (Month < 1 || Month > 12)
return 0;
int NumberOfDays[12] = { 
31,28,31,30,31,30,31,31,30,31,30,31 };
 return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
 short NumberOfDaysInAMonth()
{
    return  NumberOfDaysInAMonth(_Date.Month,_Date.Year );
}

static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
short TotalDays = 0;
for (int i = 1 ; i <= Month - 1 ; i++)
{
TotalDays += NumberOfDaysInAMonth(i, Year);
}
TotalDays += Day;
return TotalDays;
}

short NumberOfDaysFromTheBeginingOfTheYear( )
{
    return  NumberOfDaysFromTheBeginingOfTheYear(_Date.Day, _Date.Month, _Date.Year);
}

static stDate GetDateFromDayOrderInAYear(short DaysOrderInYear, short Year)
{
    stDate Date;
    short ReminingDays = DaysOrderInYear;
    short MonthDays = 0;

    Date.Month = 1;
    Date.Year = Year;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (ReminingDays > MonthDays)
        {
            ReminingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = ReminingDays;
            break;
        }
    }

    return Date;
}

    vector<string> SplitString(string S1, string Delim)
{
vector<string> vString;
short pos = 0;
string sWord; // define a string variable
// use find() function to get the position of the delimiters
while ((pos = S1.find(Delim)) != 
std::string::npos)
{
sWord = S1.substr(0, pos); // store the word
if (sWord != "")
{
vString.push_back(sWord);
}
S1.erase(0, pos + Delim.length());
}
if (S1 != "")
{
vString.push_back(S1); // it adds last word of the string.
}
return vString;
}

    stDate StringToDate(string DateString)
{
stDate Date;
vector <string> vDate; 
if(DateString.find('/')!=DateString.npos)
vDate = SplitString(DateString, "/");
else  vDate = SplitString(DateString, "-");
Date.Day = stoi(vDate[0]); 
Date.Month = stoi(vDate[1]); 
Date.Year = stoi(vDate[2]); 
return Date; 
}

  static short DayOfWeekOrder(short Day, short Month, short Year) 
{
short a, y, m;
a = (14 - Month) / 12; 
y = Year - a; 
m = Month + (12 * a) - 2; 
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc.
return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder()
{
    return DayOfWeekOrder(_Date.Day,_Date.Month,_Date.Year);
}

  static  string MonthShortName(short Month)
{
    const string arrMonths[12] =
    { "Jan", "Feb", "Mar", "Apr", "May",
        "Jun", "July", "Aug", "Sep",
        "Oct", "Nov", "Dec" };

    return arrMonths[Month - 1];
}

string MonthShortName()
{
    return  MonthShortName(_Date.Month);
}
     void Print()
    {
        Print(_Date);
    }
    static void Print(stDate Date)
    {
        cout<<Date.Day<<"/"<<Date.Month<<"/"<<Date.Year;
    }
   static void PrintMonthCalendar(short Month, short Year)
{
    short NumberOfDays = 0;

    short currnet = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n  ---------------%s---------------\n\n", MonthShortName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

    int i;
    for (i = 0; i < currnet; i++)
        printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _________________________________\n");


}
void PrintMonthCalendar( )
{
        PrintMonthCalendar(_Date.Month, _Date.Year);
}

static void PrintYearCalendar(short Year)
{

    printf("\n  ---------------------------------\n\n");
    printf("            Calendar - %d\n", Year);
    printf("\n  _________________________________\n");

    for (int i = 1; i <= 12; i++)
        PrintMonthCalendar(i, Year);
}
void PrintYearCalendar()
{
     PrintYearCalendar(_Date.Year);
}
static void SwapDates(clsDate & Date1, clsDate & Date2)
{
    stDate TempDate;

    TempDate.Year = Date1._Date.Year;
    TempDate.Month = Date1._Date.Month;
    TempDate.Day = Date1._Date.Day;
                                                
    Date1._Date.Year = Date2._Date.Year;
    Date1._Date.Month = Date2._Date.Month;
    Date1._Date.Day = Date2._Date.Day;

    Date2._Date.Year = TempDate.Year;
    Date2._Date.Month = TempDate.Month;
    Date2._Date.Day = TempDate.Day;

}
void SwapDates( clsDate & Date2){
     SwapDates( *this,  Date2);
}

static bool IsValidateDate(clsDate Date)
{
    if (Date._Date.Day < 1 || Date._Date.Day > 31)
        return false;

    if (Date._Date.Month < 1 || Date._Date.Month > 12)
        return false;


    if (Date._Date.Month == 2)
    {
        if (IsLeapYear(Date._Date.Year))
        {
            if (Date._Date.Day > 29)
                return false;
        }
        else
        {
            if (Date._Date.Day > 28)
                return false;
        }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date._Date.Month, Date._Date.Year);

    if (Date._Date.Day > DaysInMonth)
        return false;

    return true;

}

bool IsValidateDate()
{
    return IsValidateDate(*this);
}
enum enCompareDate { Before = -1, Equal = 0, After = 1 };

static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) 
{
return (Date1._Date.Year == Date2._Date.Year ) ? (( 
Date1._Date.Month == Date2._Date.Month ) ? ((Date1._Date.Day == Date2._Date.Day) ? true : false ) : false ) : false ;
}
bool IsDate1EqualDate2( clsDate Date2){
    return  IsDate1EqualDate2( *this,  Date2);
}
static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
bool IsDate1AfterDate2( clsDate Date2){
    return  IsDate1AfterDate2( *this,  Date2);
}
static bool IsDate1BeforeDate2(clsDate Date1,clsDate Date2) 
{
return (Date1._Date.Year < Date2._Date.Year) ? true : ((Date1._Date.Year == Date2._Date.Year) ? 
(Date1._Date.Month < Date2._Date.Month ? true : (Date1._Date.Month == Date2._Date.Month ? 
Date1._Date.Day < Date2._Date.Day : false)) : false); 
}
bool IsDate1BeforeDate2( clsDate Date2){
    return IsDate1BeforeDate2( *this,  Date2);
}
static short CompareDates(clsDate Date1, clsDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;

    if (IsDate1AfterDate2(Date1, Date2))
        return enCompareDate::Equal;

    return enCompareDate::After;
}
 short CompareDates( clsDate Date2){
    return  CompareDates( *this,  Date2);
}
static bool IsDateBetween(clsDate Date1,clsDate Date2,clsDate Date3)
{
      if ((IsDate1BeforeDate2(Date1, Date3) || IsDate1EqualDate2( Date1,  Date3)) && (IsDate1AfterDate2(Date1, Date2) || IsDate1EqualDate2( Date1,  Date2)))
      {
        return true;
      }
      else if ((IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualDate2( Date1,  Date2)) && (IsDate1AfterDate2(Date1, Date3) || IsDate1EqualDate2( Date1,  Date3)))
      {
        return true;
      }
      else return false; 
}

};