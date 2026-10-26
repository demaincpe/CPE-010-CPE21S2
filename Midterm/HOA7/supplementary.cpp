#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int TOTAL_VOTES = 100;

void insertionSort(int arr[], int n) {
    for (int k = 1; k < n; k++) {
        int temp = arr[k];
        int j = k - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int votes[TOTAL_VOTES];
    std::string candidates[5] = {
        "Jaime Luis M Demain",
        "Paula Esguerra",
        "Jesse Matthew Esteta",
        "Clint Hoven Estorco",
        "Cedric Hernandez"
    };
    int voteCounts[5] = {0, 0, 0, 0, 0};

    srand(time(0));

    // Generate random votes ranging from 1 to 5
    for (int i = 0; i < TOTAL_VOTES; i++) {
        votes[i] = (rand() % 5) + 1;
    }

    // Sort using Insertion Sort
    insertionSort(votes, TOTAL_VOTES);

    // Tally votes from the sorted array
    for (int i = 0; i < TOTAL_VOTES; i++) {
        voteCounts[votes[i] - 1]++;
    }

    // Display sorted votes
    std::cout << "Sorted Votes Array (A[0...99]):\n";
    for (int i = 0; i < TOTAL_VOTES; i++) {
        std::cout << votes[i] << " ";
        if ((i + 1) % 25 == 0) std::cout << "\n";
    }
    std::cout << "\nELECTION TALLY\n";

    int maxVotes = -1;
    int winnerIndex = 0;

    for (int c = 0; c < 5; c++) {
        std::cout << "Candidate " << (c + 1) << " (" << candidates[c] 
                  << "): " << voteCounts[c] << " votes\n";
        if (voteCounts[c] > maxVotes) {
            maxVotes = voteCounts[c];
            winnerIndex = c;
        }
    }

    std::cout << "\nWINNING CANDIDATE: Candidate " << (winnerIndex + 1) 
              << " (" << candidates[winnerIndex] << ") with " 
              << maxVotes << " votes!\n";

    return 0;
}