#include "postfix.h"
/*Перелік функцій
* sin
* cos
* abs
* pow
* log
* +
* -
* *
* /
*/

/*INFIX->POSTFIX
* Якщо символ є числом або постфіксною функцією
* Якщо символ є префіксною функцією
* Якщо символ є '(',
* Якщо символ є ')'
* Якщо символ є бінарною операцією
* 
* 
*/

double synus(double a) {
    return sin(a);
}
double cosys(double a) {
    return cos(a);
}
double modul(double a) {
    return abs(a);
}
double corin(double a) {
    return sqrt(a);
}



double plus(double a, double b) {
    return (a+b);
}
double minus(double a, double b) {
    return (a - b);
}
double dobutok(double a, double b) {
    return (a * b);
}
double chastka(double a, double b) {
    return (a / b);
}
double stepin(double a, double b) {
    return pow(a,b);
}







void toPostfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isdigit(infix[i])) {

        }
    }
    

}
bool isOperator(char x) {
    if (x == '+') {
        return true;

    }
    if (x == '-') {
        return true;

    }
    if (x == '*') {
        return true;

    }
    if (x == '/' ) {
        return true;

    }

    
    return false;
}
bool isFunction(string rivny, int i) {
    if (rivny[i] == 's') {
        if (rivny[i+1] == 'i') {
            if (rivny[i+2] == 'n') {
                return true;
            }
        }
        

    }
    if (rivny[i] == 'c') {
        if (rivny[i + 1] == 'o') {
            if (rivny[i + 2] == 's') {
                return true;
            }
        }
    }
    if (rivny[i] == 'a') {
        if (rivny[i + 1] == 'b') {
            if (rivny[i + 2] == 's') {
                return true;
            }
        }
    }
    

    return false;

}
bool isOperand(char x) {
    if (x == 'x') {
        return true;

    }
    if (isdigit(x)) {
        return true;

    }
    return false;
}
bool isDushky(char x) {
    if (x == ')') {
        return true;

    }
    if (x == '(') {
        return true;

    }
    return false;
}


string parser(string input) {
    input = "(" + input + ")";
    int itter = 0;

    for (int i = 0; i < input.length(); i++) {
        if (isOperand(input[i])) {

            while (isOperand(input[i])) {

                i++;



            }
            itter++;
        }
        if (isOperator(input[i])) {
            itter++;
        }

        if (isFunction(input, i)) {
            itter++;
        }

        if (isDushky(input[i])) {
            itter++;
        }
    }
    int v = 0;
    string* parse = new string[itter];
    for (int i = 0; i < input.length(); i++) {
        if (isOperator(input[i])) {
            parse[v] = input[i];
        }

        else if (isFunction(input, i)) {
            if (input[i] == 's') {
                parse[v] = "sin";
            }
            if (input[i] == 'c') {
                parse[v] = "cos";
            }
            if (input[i] == 'a') {
                parse[v] = "abs";
            }
            i = i + 2;
        }
        else if (isOperand(input[i])) {
            string chyslo = "";


            while (isOperand(input[i])) {
                if (i < input.length()) {
                    chyslo = chyslo + input[i];
                    i++;
                }

            }
            i--;

            parse[v] = chyslo;
        }
        else if (isDushky(input[i])) {
            parse[v] = input[i];
        }

        v++;
    }

    for (int i = 0; i < itter; i++) {
        cout << parse[i] << endl;
    }

    return input;
}