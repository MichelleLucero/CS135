/*
Author: Michelle Lucero
Course: CSI-135
Instructor: Mike Zamansky
Assignment: Task D. Calc3: Squares.
*/


#include <iostream>

using namespace std;


void simple_math(){
    char op; // stores op such '-','+',';', or '^'
    int num; // current number being read
    int remnum; //stores current number being read to use in case if it's squared
    int squ; //stores numbers that are squared
    char reop; //stores only '-' or  '+'
    int result; //total of the expression being read


    cin >> result; //grab first number to result.
    remnum = result;
    reop = '+';

    while(cin >> op) { // While the reading operation is a success

        if(op == '^'){ 
            
            if(reop == '+'){
                result -= remnum;//reverse addition
                result += (remnum * remnum); 
            }
            else if (reop == '-'){
                result += remnum;//reverse subtraction
                result -= (remnum * remnum);
            }

        }
        else if(op == '+'){
            cin >> num;
            remnum = num;
            reop = '+';
            result += num;//addition

        }
        else if(op == '-'){
            cin >> num;
            remnum = num; // stores current number being read to renum
            reop = '-';
            result -= num; //subtraction

        }

        else if(op == ';'){
            cout << result << endl;
            cin >> num;
            result = num;
            remnum = num;
            reop = '+';
        }
    }
    
}


int main() {
    simple_math();
}