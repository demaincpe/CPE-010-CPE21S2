#include<iostream>
#include<iomanip>
using namespace std;


int sumOftwo (int num1, int num2){
    int sum = num1 + num2;
    return sum;
}
void greaterOftwo (int varA, int varB){
    if (varA < varB) {
        cout << varA << " is greater than " << varB << endl;
        }
    else {
        cout << varA << " is less than " << varB << endl;
        }
}
bool logicalOp (int x ,int y){
    cout << "Logical AND: " << (x && y) << endl;
    cout << "Logical OR: " << (x || y) << endl;
    cout << "Logical XOR: " << (x != y) << endl;
    cout << "Logical NOT x: " << (!x) << endl;
    cout << "Logical NOT y: " << (!y) << endl;
    return true;
}


int main(){
    //Create a function that will take two numbers and display the sum.
    int sumOftwo (int num1, int num2);
    cout << "The sum of two number is " << sumOftwo(7,11) << endl;
    //Create a function that will return whether variable A is greater than variable B.
    greaterOftwo(7,11);
    //Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.
    bool success = logicalOp(true, true);
    return 0;
}
