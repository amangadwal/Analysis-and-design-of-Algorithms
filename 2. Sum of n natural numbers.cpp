#Sum of N natural numbers with its Execution time

#include <iostream>
#include <ctime>

using namespace std;

// Function to calculate the sum of first n natural numbers
int sumOfNaturalNumbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

// Function to measure the execution time of a given function
template <typename Func>
double measureExecutionTime(Func func) {
    time_t start, end;

    // Record start time
    time(&start);

    // Execute the function
    func();

    // Record end time
    time(&end);

    // Calculate total time taken by the program
    double time_taken = difftime(end, start);

    return time_taken;
}

int main() {
    // Varying n from 10000 to 100000 with a gap of 10000
    for (int n = 100000; n <= 10000000; n += 1000000) {
        // Measure the execution time of sumOfNaturalNumbers for the current value of n
        double executionTime = measureExecutionTime([&]() {
            int result = sumOfNaturalNumbers(n);
            cout << "Sum of first " << n << " natural numbers: " << result << endl;
        });

        cout << "Execution time for n = " << n << ": " << fixed << executionTime << " seconds" << endl;
    }

    return 0;
}
