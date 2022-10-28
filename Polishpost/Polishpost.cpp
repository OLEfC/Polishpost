// Polishpost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "postfix.h"

int main()
{
    string input;
    getline(cin, input);

   string* a;
   a= toPostfix(parser(input));;
    
    double x= calculator(a, 3);
    cout << x << endl;
    


    


   
}

