#include <iostream>
#include <vector>

/* Topic 8: Algorithmic Systems (Selection Sort & Binary Search)
   Demonstrates algorithm design, data rearranging, and logarithmic data matching loops.
*/
class DataSorterAndSearcher {
public:
    // Selection Sort algorithm to sort raw sequences
    void executeSelectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swapping using standard swap utilities
            std::swap(arr[i], arr[minIndex]);
        }
    }

    // Binary Search algorithm (Requires sorted data; splits searching spaces in half)
    int executeBinarySearch(const std::vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow states

            if (arr[mid] == target) return mid;       // Target matched successfully
            if (arr[mid] < target) low = mid + 1;     // Discard left half
            else high = mid - 1;                      // Discard right half
        }
        return -1; // Target not found in the vector data matrix
    }
};

int main() {
    DataSorterAndSearcher engine;
    std::vector<int> numbers = {64, 25, 12, 22, 11};

    std::cout << "--- 1. Executing Sorting Pass (Selection Sort) ---\n";
    engine.executeSelectionSort(numbers);
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    std::cout << "\n--- 2. Executing Precision Query (Binary Search) ---\n";
    int seekValue = 22;
    int indexResult = engine.executeBinarySearch(numbers, seekValue);

    if (indexResult != -1) {
        std::cout << "Target element (" << seekValue << ") verified at internal array sorted index: [" << indexResult << "]\n";
    } else {
        std::cout << "Target missing from dataset parameters.\n";
    }

    return 0;
}
