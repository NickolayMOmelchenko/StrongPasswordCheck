/*
Title: LAB 10
Author: Mykola Omelchenko
Date: 11/11/2021
Purpose: set up a password with several exceptions
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
#include <unistd.h>
using namespace std;

bool testPassWord(char input[])
{
	bool aUpper = false, aLower = false, aDigit = false, aPunctuation = false, aSpace = false;
    char current;

	for (int i = 0 ; i < strlen(input) ; i++)
    {

		if (isupper(*(input+i)))
        {
			aUpper = true;
        }
		if (islower(*(input+i)))
        {
			aLower = true;
        }
		if (isdigit(*(input+i)))
        {
			aDigit = true;
        }
        if (ispunct(*(input+i)))
        {
			aPunctuation = true;
        }
        if (isspace(*(input+i)))
        {
			aSpace = true;
        }

    }
    
	if (aUpper && aLower && aDigit && aPunctuation && !aSpace)
		return true;
	else
    {
        if (aUpper == false)
        {
            cout << "Oops!  you didn't enter at least one uppercase letter!" << endl;
        }
        if (aLower == false)
        {
            cout << "Oops!  you didn't enter at least one lowercase letter!" << endl;
        }
        if (aDigit == false)
        {
            cout << "Oops!  you didn't enter at least one digit letter!" << endl;
        }
        if (aPunctuation == false)
        {
            cout << "Oops!  you didn't enter at least one punctuation letter!" << endl;
        }
        if (!aSpace == false)
        {
            cout << "Oops!  you entered at least one space!" << endl;
        }
        cout << "----------Invalid password!----------" << endl << endl;
		return false ;
    }
}

int main()
{
    int size = 0;
    char *input;
    string str[size];

    // Makes sure the user chooses the password over 3 characters
    cout << "How many characters should the password be (must at least 4)? ";
    cin >> size;
    while (!cin.good() || !(size >= 4))
    {
        if (!cin.good())
        {
            cout << "There was a problem with what you entered."  << endl;
        }
        
        else if (size <= 4)
        {
            cout << "There was a problem with what you entered." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> size;   

    }
    cin.ignore();

    //increment size by 1 to account for null terminator
    size++;

    //dynamically allocate
    input = new char[size];

    // checks if input is the right size
    do
    {
        cout << "Enter a password consisting of exactly "<< size-1 << " characters." << endl;
        cout << "You must have at least one capital letter, one lowercase letter, one digit," << endl;
        cout << "and one punctuation character (examples: !#$%.?@)." << endl;
        cout << "The password can't contain any spaces." << endl;
        //cin.ignore();
        cin.getline(input, size);
        while (strlen(input) != size-1 || !cin)
        {
            if(!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "There was a problem with what you entered" << endl;
            cout << "Maybe you didn't enter the "<< size-1 << " characthers";
            cout << " Please re-enter your password." << endl;
            cin.getline(input, size);
        }
        cout << "Please wait - your password is being verified" << endl << endl;
        //sleep(3);

    }while(testPassWord(input) == false);

    cout << "Yay!  You came up with a valid password!" << endl;
return 0;
} 
