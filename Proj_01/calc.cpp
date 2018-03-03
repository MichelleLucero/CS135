/*
Author: Michelle Lucero
Course: CSI-135
Instructor: Mike Zamansky
Assignment: Task B. A calculator program.
*/


#include <iostream>
using namespace std;

int simple_math(){
    char s; // will be used to store + or -
    int num; // the current number that is being read
    int result = 0; // total sum of the read expression
    cin >> result; //grab first number to result.
    while(cin >> s >> num) { // While the reading operation is a success
        if(s == '+'){
            result += num;//addition
        }
        else if(s == '-'){

            result -= num;//subtraction
        }

    }
    return result;
}



int main() {
    cout << simple_math(); // prints final sum
}