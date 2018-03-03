/*
Author: Michelle Lucero
Course: CSI-135
Instructor: Mike Zamansky
Assignment: Task A. Adding integers
*/

#include <iostream>

using namespace std; //takes out std

int add(){
    int s; // s is current number
    int sum = 0; // sum is the total of the all the numbers
    while(cin >> s) { // While the reading operation is a success

        sum += s; //adds current number to the current sum
    }
    return sum; //returns the final sum
}


int main(){
    cout << add(); //prints final sum 
}
