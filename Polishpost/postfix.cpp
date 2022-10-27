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


string* parser(string input) {
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
    itter++;
   
    int v = 1;
    string* parse = new string[itter];
    parse[0] = to_string(itter-1);
    for (int i =0; i < input.length(); i++) {
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

    /*for (int i = 0; i < itter; i++) {
        cout << parse[i] << endl;
    }*/

    return parse;
}
void toPostfix(string* parse) {
    int inputLength = stoi(parse[0]);
    int postlen=0;
    string temp;
    for (int i = 1; i < inputLength; i++) {
        if (isDushky((parse[i])[0])==false) {
            
            postlen++;

        }
    }
    string* output = new string[postlen];
    stack <string> stack;
    int lich = 0;
    for (int i = 1; i < inputLength; i++) {
        if (parse[i] == "(") {
            stack.push("(");
        }
        if (parse[i] == ")") {
            while (stack.top()!="(")
            {
                output[lich] = stack.top();
                stack.pop();
                lich++;
            }
            stack.pop();
            if (isFunction(stack.top(),0)) {
                output[lich] = stack.top();
                stack.pop();
                lich++;
            }
        }
        if (isOperand((parse[i])[0])) {
            output[lich] = parse[i];
            lich++;
        }
        if (isFunction(parse[i], 0)) {
            stack.push(parse[i]);

        }
        if (isOperator((parse[i])[0])) {
           

        }
    }
    for (int i = 0; i < lich; i++) {
        cout << output[i] << " ";
    }

   

}