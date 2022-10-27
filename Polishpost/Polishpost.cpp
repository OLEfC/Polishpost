// Polishpost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "postfix.h"

int main()
{
    string input;
    getline(cin, input);

    string* a;
    a=parser(input);
    toPostfix(a);



    


   
}

