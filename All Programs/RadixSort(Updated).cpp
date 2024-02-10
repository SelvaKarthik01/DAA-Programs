#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function

// Function to find the maximum number to determine the number of digits
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Using counting sort to sort elements based on significant places
int countingSort(int arr[], int n, int exp) {
    const int k = 10; // 10 possible digits (0-9)
    int output[n];
    int count[k] = {0};
    int comparisons = 0;

    // Count occurrences of each digit in arr
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to store the position of the digit in the output array
    for (int i = 1; i < k; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        comparisons++;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    return comparisons;
}

// Radix Sort implementation
int radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    int totalComparisons = 0;

    // Perform counting sort for every digit place
    for (int exp = 1; max / exp > 0; exp *= 10) {
        totalComparisons += countingSort(arr, n, exp);
    }

    return totalComparisons;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Seed for random number generation
    std::srand(std::time(0));

    // Generate an array of n random integers between 1000 and 9999
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 9000 + 1000; // Random number between 1000 and 9999
    }

    std::cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Perform Radix Sort and get the number of comparisons
    int comparisons = radixSort(arr, n);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of Comparisons: " << comparisons << std::endl;

    return 0;
}

