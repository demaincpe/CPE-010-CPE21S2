#include<iostream>
using namespace std;


int main(){
    int total_price = 0;
    int item_1, item_2, item_3, cash, change;
    cout << "Enter the prices for Item 1, Item 2, and Item 3: ";
    cin >> item_1 >> item_2 >> item_3;
    cout << "Enter the cash given by the customer: ";
    cin >> cash;
    total_price = item_1 + item_2 + item_3;
    cout << "The total price of all items is: " << total_price << endl;
    change = cash - total_price;
    cout << "The change to be given to the customer is: " << change;
    return 0;
}