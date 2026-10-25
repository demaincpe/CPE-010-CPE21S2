#include <iostream>
#include <string>

// Step 1: Job Class
class Job {
public:
    int jobID;
    std::string userName;
    int numberOfPages;

    Job(int id, std::string user, int pages)
        : jobID(id), userName(user), numberOfPages(pages) {}

    void displayJob() const {
        std::cout << "Job #" << jobID << " | User: " << userName 
                  << " | Pages: " << numberOfPages;
    }
};

// Node structure for custom queue
struct JobNode {
    Job job;
    JobNode* next;
    JobNode(Job j) : job(j), next(nullptr) {}
};

// Step 2 & 3: Printer Class with Custom Linked List Queue
class Printer {
private:
    JobNode* frontPtr;
    JobNode* backPtr;
    int pendingCount;

public:
    Printer() : frontPtr(nullptr), backPtr(nullptr), pendingCount(0) {}

    ~Printer() {
        while (frontPtr != nullptr) {
            JobNode* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
    }

    // Add a new print job to the queue
    void addJob(int id, std::string user, int pages) {
        Job newJob(id, user, pages);
        JobNode* newNode = new JobNode(newJob);

        if (frontPtr == nullptr) {
            frontPtr = newNode;
            backPtr = newNode;
        } 
        else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        pendingCount++;

        std::cout << "[ADDED] ";
        newJob.displayJob();
        std::cout << "\n";
    }

    // Process all jobs in First-Come, First-Served order
    void processJobs() {
        std::cout << "\n--- STARTING PRINTER JOB PROCESSING ---\n";
        if (frontPtr == nullptr) {
            std::cout << "No pending print jobs in the queue.\n";
            return;
        }

        while (frontPtr != nullptr) {
            JobNode* temp = frontPtr;
            std::cout << "[PROCESSING] ";
            temp->job.displayJob();
            std::cout << " -> Completed!\n";

            frontPtr = frontPtr->next;
            delete temp;
            pendingCount--;
        }
        backPtr = nullptr;
        std::cout << "All print jobs completed successfully.\n";
    }

    void showPendingJobs() const {
        std::cout << "\n--- CURRENT PENDING JOBS (" << pendingCount << ") ---\n";
        if (frontPtr == nullptr) {
            std::cout << "Printer queue is empty.\n";
            return;
        }
        JobNode* curr = frontPtr;
        while (curr != nullptr) {
            std::cout << " -> ";
            curr->job.displayJob();
            std::cout << "\n";
            curr = curr->next;
        }
    }
};

// Step 4: Scenario Simulation
int main() {
    Printer officePrinter;

    std::cout << "=== SHARED PRINTER SIMULATION ===\n\n";

    // Users submitting jobs
    officePrinter.addJob(101, "Engr. Jaime", 6);
    officePrinter.addJob(102, "Engr. Jammy", 7);
    officePrinter.addJob(103, "Engr. Jaimito", 19);
    officePrinter.addJob(104, "Engr. Tempest", 5);

    // View queue before processing
    officePrinter.showPendingJobs();

    // Process all jobs
    officePrinter.processJobs();

    // Verify empty queue
    officePrinter.showPendingJobs();

    return 0;
}