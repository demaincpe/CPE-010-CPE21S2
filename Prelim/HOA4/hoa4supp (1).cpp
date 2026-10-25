#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Array of expressions to test
    string expressions[4] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (int i = 0; i < 4; i++) {
        string expr = expressions[i];
        stack<char> s;
        bool isValid = true;

        for (int j = 0; j < expr.length(); j++) {
            char ch = expr[j];

            // Step 1: Push opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            }
            // Step 2: Handle closing brackets
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (s.empty()) {
                    isValid = false;
                    break;
                }

                char top = s.top();
                s.pop();

                // Check for mismatch
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    isValid = false;
                    break;
                }
            }
        }

        // Step 3: Check if stack is empty at the end
        if (!s.empty()) {
            isValid = false;
        }

        // Display results
        cout << "Expression: " << expr << endl;
        if (isValid) {
            cout << "Valid? Y" << endl;
        } else {
            cout << "Valid? N" << endl;
        }
        cout << "---------------------------------" << endl;
    }

    return 0;
}