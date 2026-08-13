#include <iostream>
#include <string>
using namespace std;

class Triangle {
private:
    double totalandPerimeterAngle, angleA, angleB, angleC, areaAngle; // Private member variables to store the angles, their sum, and their area
public:
    Triangle(double A, double B, double C); // Constructor declaration to initialize the triangle with three angles
    void setAngles(double A, double B, double C); // Setter method declaration to update the values of all angles
    const bool validateTriangle(); // To determine whether it is triangle or not
};
// Constructor definition to initialize private member variables and calculate total angle
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalandPerimeterAngle = A+B+C;
    areaAngle = (A+B+C)/3;
}
// Setter method definition to update angle values and recalculate the overall sum
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalandPerimeterAngle = A+B+C;
    areaAngle = (A+B+C)/3;
}
// Method to determine if overall angle is triangle or not
const bool Triangle::validateTriangle() {
    return (totalandPerimeterAngle <= 180);
}
//A function that determines whether the triangle is acute-angled, obtuse-angled or ‘others.’
string determineTriangleType(double angleA, double angleB, double angleC) { // Function to determine the type of triangle based on its angles
        if (angleA < 90 && angleB < 90 && angleC < 90) {
            return "Acute-angled triangle";
        } else if (angleA > 90 || angleB > 90 || angleC > 90) {
            return "Obtuse-angled triangle";
        } else {
            return "Right-angled triangle";
        }
    }
// Driver code
int main(){
    Triangle set1(40, 30, 110);
    if(set1.validateTriangle()){
        cout << "The shape is a valid triangle.\n";
    } else {
        cout << "The shape is NOT a valid triangle.\n";
    }
    Triangle set2(90, 60, 60);
    string triangleType = determineTriangleType(90, 60, 60);
    cout << "The triangle is: " << triangleType << std::endl;
    return 0;
}
