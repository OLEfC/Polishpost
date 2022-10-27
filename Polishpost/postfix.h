#pragma once
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


bool isOperator(char x);
bool isOperand(char x);
bool isDushky(char x);
bool isFunction(string rivny, int i);
string* toPostfix(string* rivny);
double plus(double a, double b);
double minus(double a, double b);
double dobutok(double a, double b);
double chastka(double a, double b);
string* parser(string input); 
int getPriority(char C);

