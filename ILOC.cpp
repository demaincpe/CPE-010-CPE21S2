#include<iostream>
#include <cmath> // Include the cmath library for mathematical functions
using namespace std;

//Function for Kelvin to Fahrenheit conversion
double convertKelvinToFahrenheit(double kelvin) {           
    return (kelvin - 273.15) * 9/5 + 32;
}
//Function to find distance between two points in 2D space
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
    //Create a C++ program to swap the two numbers in different variables.
    double num1, num2, temp;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Before swapping: " << num1 << " and " << num2 << endl;
    //Swapping the two numbers using a temporary variable
    temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "After swapping: " << num1 << " and " << num2 << endl;

    //Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit.
    double kelvin;
    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;
    cout << "Temperature in Fahrenheit: " << convertKelvinToFahrenheit(kelvin) << endl;

    //Create a C++ program that has a function that will calculate the distance between two points.
    double x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";   
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Distance between the two points: " << distance(x1, y1, x2, y2) << endl;
    return 0;
}
