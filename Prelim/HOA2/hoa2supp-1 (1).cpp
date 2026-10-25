#include <iostream>
#include <string>

// Fruit Class 
class Fruit {
private:
    std::string name;
    double price;
    int qty;

public:
    Fruit(std::string n = "Unknown", double p = 0.0, int q = 0) : name(n), price(p), qty(q) {
        std::cout << "Constructor Called." << std::endl;
    }
    ~Fruit() {
        std::cout << "Destructor Called." << std::endl;
    }
    Fruit(const Fruit &f) : name(f.name), price(f.price), qty(f.qty) {
        std::cout << "Copy Constructor Called" << std::endl;
    }
    Fruit& operator=(const Fruit &f) {
        std::cout << "Copy Assignment Called" << std::endl;
        if (this != &f) {
            name = f.name;
            price = f.price;
            qty = f.qty;
        }
        return *this;
    }

    double calculateSum() const { return price * qty; }
    std::string getName() const { return name; }
    void printDetails() const {
        std::cout << "[Fruit] " << name << " | PHP " << price << " | x" << qty << " | Subtotal: PHP " << calculateSum() << std::endl;
    }
};

// Vegetable Class 
class Vegetable {
private:
    std::string name;
    double price;
    int qty;

public:
    Vegetable(std::string n = "Unknown", double p = 0.0, int q = 0) : name(n), price(p), qty(q) {
        std::cout << "Constructor Called." << std::endl;
    }
    ~Vegetable() {
        std::cout << "Destructor Called." << std::endl;
    }
    Vegetable(const Vegetable &v) : name(v.name), price(v.price), qty(v.qty) {
        std::cout << "Copy Constructor Called" << std::endl;
    }
    Vegetable& operator=(const Vegetable &v) {
        std::cout << "Copy Assignment Called" << std::endl;
        if (this != &v) {
            name = v.name;
            price = v.price;
            qty = v.qty;
        }
        return *this;
    }

    double calculateSum() const { return price * qty; }
    std::string getName() const { return name; }
    void printDetails() const {
        std::cout << "[Vegetable] " << name << " | PHP " << price << " | x" << qty << " | Subtotal: PHP " << calculateSum() << std::endl;
    }
};

// Function to calculate total sum of fruits and vegetables in the grocery list
double TotalSum(const Fruit fList[], int fSize, const Vegetable vList[], int vSize) {
    double total = 0.0;
    for (int i = 0; i < fSize; i++) {
        if (fList[i].getName() != "Unknown") total += fList[i].calculateSum();
    }
    for (int i = 0; i < vSize; i++) {
        if (vList[i].getName() != "Unknown") total += vList[i].calculateSum();
    }
    return total;
}

int main() {
    // Array for Grocery List
    Fruit FruitList[2];
    Vegetable VegList[2];

    // Data lists for processing
    std::string fNames[2] = {"Apple", "Banana"};
    double fPrices[2] = {10.0, 10.0};
    int fQty[2] = {7, 8};

    std::string vNames[2] = {"Broccoli", "Lettuce"};
    double vPrices[2] = {60.0, 50.0};
    int vQty[2] = {12, 10};

    std::cout << "\n--- Populating Fruit List via Dynamic Memory ---\n";
    for (int i = 0; i < 2; i++) {
        Fruit *ptr = new Fruit(fNames[i], fPrices[i], fQty[i]); 
        FruitList[i] = *ptr;                                    
        delete ptr;                                             
    }

    std::cout << "\n--- Populating Vegetable List via Dynamic Memory ---\n";
    for (int i = 0; i < 2; i++) {
        Vegetable *ptr = new Vegetable(vNames[i], vPrices[i], vQty[i]);
        VegList[i] = *ptr;
        delete ptr;
    }

    std::cout << "\n--- Displaying Jenna's Grocery List ---\n";
    for (int i = 0; i < 2; i++) FruitList[i].printDetails();
    for (int i = 0; i < 2; i++) VegList[i].printDetails();

    std::cout << "\nInitial Grand Total: PHP " << TotalSum(FruitList, 2, VegList, 2) << "\n\n";

    // Deleting Lettuce from the list 
    std::cout << "--- Removing Lettuce from List ---\n";
    for (int i = 0; i < 2; i++) {
        if (VegList[i].getName() == "Lettuce") {
            // Re-assigning to a default blank object effectively clears it
            VegList[i] = Vegetable(); 
            break;
        }
    }

    std::cout << "\nNew Grand Total after removing Lettuce: PHP " << TotalSum(FruitList, 2, VegList, 2) << "\n\n";
    std::cout << "--- End of Main Scope (Stack Cleanup) ---\n";
    return 0;
}