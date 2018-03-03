/*
Author: Michelle Lucero
Course: CSI-135
Instructor: Mike Zamansky
Assignment: Task C.Reading multiple formulas.
*/


#include <iostream>
using namespace std;


int simple_math(){
    char s; //stores either '+','-', or ';'
    int num; // current num being read
    int result; // total of each expression 
    // multi values

    while (cin >> result){ //grab first number to result.
    while(cin >> s >> num) { // While the reading operation is a success
        if(s == '+'){
            result += num;//addition
        }
        else if(s == '-'){

            result -= num;//subtraction
        }
        else if(s == ';'){
            cout << result << endl;
            result = num; // assigned result to the next num after ';'
        }

    }
    return result;
}

}


int main() {
    cout << simple_math();
}