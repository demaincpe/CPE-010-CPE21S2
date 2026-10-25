#include<iostream>
using namespace std;


int main(){
    int total_score, average_score = 0;
    int quiz_1, quiz_2, quiz_3;
    cout << "Enter the scores for Quiz 1, Quiz 2, and Quiz 3: ";
    cin >> quiz_1 >> quiz_2 >> quiz_3;
    total_score = quiz_1 + quiz_2 + quiz_3;
    cout << "The total result of all quiz combined is: " << total_score << endl;
    average_score = total_score / 3;
    cout << "The average result of quizzes is: " << average_score;
    return 0;
}