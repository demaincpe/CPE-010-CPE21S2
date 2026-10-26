#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

// Step 1: Define the Student class
class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    // Constructor
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    // Getters
    auto get_name() const { return name; }
    auto is_vaccinated() const { return vaccinated; }

    // Step 2: Operator Overloads for Sorting and Searching
    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

// Step 3: Function to generate a random Student
auto generate_random_Student(int max) {
    std::random_device rd;
    std::mt19937 rand(rd());
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, max);

    auto random_name = std::make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = (uniform_dist(rand) % 2) ? true : false;
    return Student(random_name, is_vaccinated);
}

// Step 5: Binary Search logic for vaccination status
bool needs_vaccination(Student P, std::vector<Student>& people) {
    auto first = people.begin();
    auto last = people.end();

    while (first < last) {
        auto range_length = std::distance(first, last);
        auto mid_element_index = range_length / 2;
        auto mid_element = first + mid_element_index;

        if (*mid_element == P) {
            return !mid_element->is_vaccinated();
        } else if (*mid_element > P) {
            last = mid_element;
        } else {
            first = mid_element + 1;
        }
    }
    // Student not found in the list; therefore, needs vaccination
    return true;
}

// Step 4: Experimental Analysis driver using std::chrono
void search_test(int size, Student p) {
    std::vector<Student> people;

    // Create a list of random students
    for (auto i = 0; i < size; i++) {
        people.push_back(generate_random_Student(size));
    }

    // Sort using overloaded operator<
    std::sort(people.begin(), people.end());

    // Measure only the binary search execution time
    auto begin = std::chrono::steady_clock::now();
    bool search_result = needs_vaccination(p, people);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

    std::cout << "Time taken to search = " << duration << " nanoseconds" << std::endl;    
    if (search_result) {
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") needs vaccination." << std::endl;
    } else {
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") does not need vaccination." << std::endl;
    }
}

// Step 6: Main execution
int main() {
    auto p = generate_random_Student(1000);

    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}