//To count the frequency of elements in a hashmap in C++, you can iterate through the hashmap and maintain a count for each unique element

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> hashMap; // Create an unordered_map with int keys and int values

    // Sample array with values
    std::vector<int> arrayValues = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // Insert array values into the hashmap with their frequencies
    for (int i = 0; i < arrayValues.size(); ++i) {
        hashMap[arrayValues[i]]++;
    }

    // Iterate through the hashmap to count and print frequencies
    for (const auto& pair : hashMap) {
        std::cout << "Element: " << pair.first << ", Frequency: " << pair.second << std::endl;
    }

    return 0;
}

// to store with indices
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> hashMap; // Create an unordered_map with int keys and int values

    // Sample array with values
    std::vector<int> arrayValues = {1, 2, 3, 4, 5};

    // Insert array values into the hashmap with their indices as keys
    for (int i = 0; i < arrayValues.size(); ++i) {
        hashMap[i] = arrayValues[i];
    }

    // Access and print values from the hashmap
    for (const auto& pair : hashMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
