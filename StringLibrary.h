 #pragma once
 #include<string>
 #include<vector>
 #include<iostream>
 enum enLetterType{Capital,Small,All};
 using namespace std;
class ClsString
{
     private:
	 string _String;
	 public:
     ClsString(){_String="";}
	 ClsString(string String)
	 {
		_String=String;
	 }
	 void SetString(string String){
		_String=String;
	 }
	 string GetString()
	 {
		return _String;
	 }
	// __declspec(property(get=GetString,put=SetString))string String
static int Length(string String){
	return String.length();
}
int Length()
{
	return Length(_String);
}
static char InvertingCharacter(char MyChar)
{
	return (isupper(MyChar)) ? tolower(MyChar) : toupper(MyChar);
}

static void PrintFirstLettersOfString(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			cout << Text[i] << endl;
		IsSpace = (Text[i] == ' ') ? true : false;
	}
}
void PrintFirstLettersOfString(){
     PrintFirstLettersOfString(_String);
}
static string UpperFirstLetterOfEachWord(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			Text[i] = toupper(Text[i]);
		IsSpace = (Text[i] == ' ') ? true : false;
	}
	return Text;
}
void UpperFirstLetterOfEachWord() 
{
	_String= UpperFirstLetterOfEachWord(_String);
}
static string LowerFirstLetterOfEachWord(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			Text[i] = tolower(Text[i]);
		IsSpace = (Text[i] == ' ') ? true : false;
	}
	return Text;
}
void LowerFirstLetterOfEachWord()
{
	_String= LowerFirstLetterOfEachWord(_String);
}
static string UpperAllLetterOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
	return Text;
}
void UpperAllLetterOfString(){
	_String=  UpperAllLetterOfString(_String);
}
static string LowerAllLetterOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
	return Text;
}
void LowerAllLetterOfString()
{
	_String=  LowerAllLetterOfString(_String);
}
static string InvertAllLettersOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = InvertingCharacter(Text[i]);
	}
	return Text;
}
void InvertAllLettersOfString(){
	_String=  InvertAllLettersOfString(_String);
}

static short CountCapital_SmallLetters(string Text, enLetterType Enum = ::All)
{
	if (Enum == All)
		return Text.length();
	short Counter = 0;
	for (short i = 0; i < Text.length(); i++)
	{
		if (Enum == enLetterType::Capital)
		{
			if (isupper(Text[i]))
				Counter++;
		}
		if (Enum == enLetterType::Small)
		{
			if (islower(Text[i]))
				Counter++;
		}
	}
	return Counter;
}
short CountCapital_SmallLetters(enLetterType Enum = ::All){
	return  CountCapital_SmallLetters(_String, Enum);
}
static short CountLettersByMatchCase(string Text, char CharToCount, bool MatchCase = true)
{
	short Counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (MatchCase == false)
		{
			if (toupper(Text[i]) == toupper(CharToCount))
				Counter++;
		}
		else
			if (Text[i] == CharToCount)
				Counter++;
	}
	return Counter;
}
short CountLettersByMatchCase( char CharToCount, bool MatchCase = true){
	return  CountLettersByMatchCase(_String,  CharToCount,  MatchCase);
}
static bool isvowel(char i)
{
	i = tolower(i);
	return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ? true : false;
}

static short CountVowelLetters(string Text)
{
	short Counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (isvowel(Text[i]))
			Counter++;
	}
	return Counter;
}
short CountVowelLetters(){
	return CountVowelLetters(_String);
}

static string PrintAllVowelsInString(string Text, string Space = "  ")
{
	string Vowels;
	for (int i = 0; i < Text.length(); i++)
	{
		if (isvowel(Text[i]))
			Vowels += Text[i] + Space;
	}
	return Vowels;
}
string PrintAllVowelsInString( string Space = "  "){
	return PrintAllVowelsInString(_String,Space);
}

static void  PrintEachWordInString(string Text)
{
	string Space = " ";
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
			cout << NewText << endl;
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		cout << Text << endl;
}
void  PrintEachWordInString()
{
	 PrintEachWordInString(_String);
}
static short CountEachWordInString(string Text)
{
	short Counter = 0;
	string Space = " ";
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
			Counter++;
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		return ++Counter;
}
short CountEachWordInString()
{
	return CountEachWordInString(_String);
}

static vector <string> SplitString(string Text, string Space)
{
	vector <string> vSplit;
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
		{
			vSplit.push_back(NewText);
		}
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		vSplit.push_back(Text);
	return vSplit;
}
vector <string> SplitString( string Space){
	return  SplitString(_String,  Space);
}
static string TrimLeft(string Text, char Delim)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != Delim)
			return Text = Text.substr(i, Text.length());
	}
}
void TrimLeft( char Delim){
	_String=  TrimLeft(_String,  Delim);
}
static string TrimRight(string Text, char Delim)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[Text.length() - i - 1] != Delim)
			return Text = Text.substr(0, Text.length() - i);
	}
}
void TrimRight( char Delim){
	_String=TrimRight(_String,  Delim);
}
static string Trim(string Text, char Delim)
{
	return TrimLeft(TrimRight(Text, Delim), Delim);
}
void Trim( char Delim)
{
	_String= TrimLeft(TrimRight(_String, Delim), Delim);
}
static string JoinString(vector <string> vSplit, string Delim)
{
	string Line;
	for (string& temp : vSplit)
		Line += temp + Delim;
	return Trim(Line, '#');
}

static string JoinString(string ArrString[], short length, string Delim)
{
	string Line;
	for (int i = 0; i < length; i++)
	{
		Line += ArrString[i] + Delim;
	}
	return Trim(Line, '*');
}
static string ReverseWords(string Text)
{
	string Line;
	vector <string> vSplit = SplitString(Text, " ");
	vector <string>::iterator iter = vSplit.end();
	while (iter != vSplit.begin())
	{
		--iter;
		Line += *iter + " ";
	}
	Line = Line.substr(0, Line.length() - 1);
	return Line;
}
void ReverseWords()
{
	_String=  ReverseWords(_String);
}
static string ReplaceWords(string Text, string Word, string Replace)
{
	int Pos;
	while ((Pos = Text.find(Word)) != string::npos)
		Text = Text.replace(Pos, Word.length(), Replace);
	return Text;
}
void ReplaceWords( string Word, string Replace){
	_String=  ReplaceWords(_String,  Word,  Replace);
}
static string ReplaceWordsCustom(string Text, string Word, string Replace, bool MatchCase = true)
{
	int Pos;
	vector <string> vText = SplitString(Text, " ");
	if (MatchCase)
	{
		while ((Pos = Text.find(Word)) != string::npos)
		{
			Text = Text.replace(Pos, Word.length(), Replace);
			vText = SplitString(Text, " ");
		}
	}
	else
		for (string& temp : vText)
			if (LowerAllLetterOfString(Word) == LowerAllLetterOfString(temp))
				temp = Replace;
	return JoinString(vText, " ");
}
void ReplaceWordsCustom( string Word, string Replace, bool MatchCase = true){
     _String= ReplaceWordsCustom(_String,  Word, Replace,  MatchCase = true);
}
static string RemovePuncuations(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (ispunct(Text[i]))
			Text[i] = ' ';
	}
	return Text;
}
void RemovePuncuations( ){
	_String=  RemovePuncuations(_String );
}
static string PrintStringWithoutPunct(string Text, string Space)
{
	string Word;
	vector <string> vText = SplitString(Text, " ");
	for (string& temp : vText)
		Word += temp + Space;
	return Word.substr(0, Word.length() - 1);
}
string PrintStringWithoutPunct( string Space){
	return  PrintStringWithoutPunct(_String,  Space);
}
static string Tabs(int n)
{ 
    string n_Taps;
	for(int i; i<n ; i++)
	n_Taps+='\t';
	return n_Taps;
}
};



 
