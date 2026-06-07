#include <iostream>
#include <string>

/* Topic 1: String Processing Algorithms
   Uses C++ Object-Oriented standards to analyze text sequences.
*/
class StringAnalyzer {
public:
    // Calculates string length manually without built-in methods
    int calculateLength(const std::string& str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // Evaluates if a string reads the same forward and backward
    bool isPalindrome(const std::string& str) {
        int start = 0;
        int end = calculateLength(str) - 1;

        while (start < end) {
            if (str[start] != str[end]) {
                return false; 
            }
            start++;
            end--;
        }
        return true; 
    }
};

int main() {
    StringAnalyzer analyzer;
    std::string word = "radar";

    std::cout << "--- String Processing Suite (C++) ---\n";
    std::cout << "Target Text: " << word << "\n";
    std::cout << "Manual Length Check: " << analyzer.calculateLength(word) << " indices\n";

    if (analyzer.isPalindrome(word)) {
        std::cout << "Result: Sequence is a verified PALINDROME.\n";
    } else {
        std::cout << "Result: Sequence is NOT a palindrome.\n";
    }

    return 0;
}
