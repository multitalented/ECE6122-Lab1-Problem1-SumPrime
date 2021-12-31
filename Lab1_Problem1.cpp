/*
Author: Deanna Gierzak
Class: ECE 6122
Last Date Modified: 9/8/2020

Description:

Sum of Primes:

This program takes one command line input and calculates the sum of all primes equal to and below this number.
For example, an input of 13 will generate the primes of 13 11 7 5 3 2 and a sum of 41
The resulting sum is output to a file calling Output1.txt

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool isPrime(unsigned long lNum);

// takes one command-line argument variable of type unsigned long
int main(int argc, char* argv[])
{
	unsigned long sum = 0;
	unsigned long num = 0;
	bool primenum = false;

	stringstream convert(argv[1]);
	convert >> num;

	//cout << "Enter a number: ";
	//cin >> num;

	for (unsigned long j = num; j > 1; --j)
	{
		if (isPrime(j) == true) 
		{
			sum = sum + j;
		}

		/*
		if (primenum == true)
		{
			cout << "Number is Prime";
		}
		if (primenum == false)
		{
			cout << "Number is NOT Prime";
		}
		*/
	}

	//cout << "Sum of primes below " << num << " is " << sum << endl;
	ofstream ofs;
	ofs.open("Output1.txt");
	ofs << sum;
	ofs.close();

	//system("pause");

	return 0;
}

bool isPrime(unsigned long lNum)
{
	if (lNum <= 1)
	{
		return false;
	}
	for (unsigned long i = 2; i < lNum; ++i)
	{
		if (lNum % i == 0)
		{
			return false;
		}
	}
	return true;
}