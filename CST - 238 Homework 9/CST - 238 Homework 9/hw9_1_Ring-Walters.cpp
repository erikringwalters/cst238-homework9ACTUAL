//Erik Ring-Walters
//November 16, 2016
//CST - 238 Homework 9
//ID: 002488407
//counter of number 8
//replace pi with 3.14
//I had problems with calling void main() twice, so i'm just using one cpp file for simplicity
#include <iostream>
#include <string>
using namespace std;
int count8(int n)
{
	int sum = 0;
	if (n == 8)
	{
		return 1;
	}
	if (n < 10 && n != 8)
	{
		return 0;
	}
	if (n % 10 == 8)
	{
		sum++;
		if ((n / 10) % 10 == 8)
		{
			sum++;
		}
	}
	return count8(n / 10) + sum;
}
//Beginning problem 2
string piReplacer(string word, int num)//takes in the word you'd like to modify as well as where the iterator should start.
{
	string pi = "3.14";
	int i = num;
	if (i == word.length() - 1)
	{
		return word;
	}
	if (word[i] == 'p' || word[i] == 'P')//Accounts for capitals as well
	{
		if (word[i + 1] == 'i' || word[i + 1] == 'I')
		{
			//looked up documentation for replacing functions in string class here: http://www.cplusplus.com/reference/string/string/
			word.erase(i, 2);//First erased 'pi'
			word.insert(i, pi);//then inserted '3.14' at location i.
		}
	}
	i++;
	return piReplacer(word, i);
}
//beginning main
void main()
{
	int testNum;
	cout << "Enter the case you'd like to test: ";
	cin >> testNum;
	cout << count8(testNum) << endl;
	string w;
	cout << "Give me a word you'd like to modify: ";
	cin >> w;
	cout << piReplacer(w, 0) << endl;//it should usually be zero. Not quite sure how to get argument zero inside function as well as iterate it without getting an infinite loop.
}