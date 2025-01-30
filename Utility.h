#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<limits>
#include"DateLibrary.h"
using namespace std;
class clsUtil{
     private:
       
     struct stDate
{
short Year;
short Month;
short Day;
};
  stDate _Date; 
     public:
static void Srand()
{
    srand((unsigned)time(NULL));
}     
    static int RandomNumber(int From, int To)
{ 
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}
 enum enCharType { SamallLetter = 1, CapitalLetter = 2, 
SpecialCharacter = 3, Digit = 4 };
static char GetRandomCharacter(enCharType CharType)
{
switch (CharType)
{
case enCharType::SamallLetter:
{
return char(RandomNumber(97, 122));
break;
}
case enCharType::CapitalLetter:
{ 
return char(RandomNumber(65, 90));
break;
}
case enCharType::SpecialCharacter:
{
return char(RandomNumber(33, 47));
break;
}
case enCharType::Digit:
{
return char(RandomNumber(48, 57));
break;
}
}
}

static string GenerateWord(enCharType CharType, short Length)
{
string Word;
for (int i = 1; i <= Length; i++)
{
Word = Word + GetRandomCharacter(CharType);
}
return Word;
}

static string GenerateKey(enCharType CharType)
{
string Key = "";
Key = GenerateWord(CharType, 4) + "-";
Key = Key + GenerateWord(CharType, 4) + "-";
Key = Key + GenerateWord(CharType, 4) + "-";
Key = Key + GenerateWord(CharType, 4);
return Key;
}

static void GenerateKeys(short NumberOfKeys,enCharType CharType)
{
for (int i = 1; i <= NumberOfKeys; i++)
{
cout << "Key [" << i << "] : ";
cout << GenerateKey(CharType) << endl;
}
}
static void Sum(int arr1[100], int arr2[100], int arrSum[100], int
arrLength)
{
for (int i = 0; i < arrLength; i++)
{
arrSum[i] = arr1[i] + arr2[i];
}
}
static void Swap(int& A, int& B)
{
int Temp;
Temp = A;
A = B;
B = Temp;
}
static void Swap(double& A, double& B)
{
int Temp;
Temp = A;
A = B;
B = Temp;
}
static void Swap(string& A, string& B)
{
string Temp;
Temp = A;
A = B;
B = Temp;
}
static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A,B);
    }

static void ShuffleArray(int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
{
Swap(arr[RandomNumber(1, arrLength) - 1], 
arr[RandomNumber(1, arrLength) - 1]);
}
}
static void ShuffleArray(string arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
{
Swap(arr[RandomNumber(1, arrLength) - 1], 
arr[RandomNumber(1, arrLength) - 1]);
}
}
static void FillArrayWithRandomNumbers(int arr[100], int& arrLength,int from,int to)
{
cout << "\nEnter number of elements:\n";
cin >> arrLength;
for (int i = 0; i < arrLength; i++) 
arr[i] = RandomNumber(from, to);
}
static void FillArrayWithRandomNumbers(string arr[100], int& arrLength,int from,int to)
{
cout << "\nEnter number of elements:\n";
cin >> arrLength;
for (int i = 0; i < arrLength; i++) 
arr[i] = RandomNumber(from, to);
}
static void FillArrayWithRandomNumbers(int arr[100], int arrLength,int from,int to)
{
for (int i = 0; i < arrLength; i++) 
arr[i] = RandomNumber(from, to);
}
 static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

static void FillArrayWithKeys(string arr[100], int arrLength,enCharType CharType)
{
for (int i = 0; i < arrLength; i++)
arr[i] = GenerateKey( CharType);
}
static string Tabs(int n)
{
    string taps;
    for (size_t i = 0; i < n; i++)
    {
        taps+='\t';
    }
    return taps;
}
static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

};