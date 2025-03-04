#include <iostream>
#include <vector>
#include <string>
#include <sstream>



std::vector<std::vector<double> > generateDifferences(const std::vector<double>& input) {
    std::vector<std::vector<double> > result;
    if (input.empty()) return result;

    result.push_back(input);
    std::vector<double> current = input;

    while (current.size() > 1) {
        std::vector<double> next;
        for (size_t i = 1; i < current.size(); ++i) {
            next.push_back(current[i] - current[i - 1]);
        }
        result.push_back(next);
        
        // Check if all values in the new row are the same
        bool allSame = true;
        if (!next.empty()) {
            double firstValue = next[0];
            for (size_t i = 1; i < next.size(); ++i) {
                if (next[i] != firstValue) {
                    allSame = false;
                    break;
                }
            }
        }
        
        // If all values are the same, we've found a constant sequence, so we can stop
        if (allSame && next.size() > 1) {
            break;
        }
        
        current = next;
    }

    return result;
}

int main() {
    // Vector to store the parsed numbers
    std::vector<double> numbers;
    // Vector to store the differences
    std::vector<std::vector<double> > differences;

    
    // Read stdin into a string
    std::string input;
    std::string line;
    while (std::getline(std::cin, line)) {
        input += line + "\n";
    }
    
    // Replace commas with spaces to simplify parsing
    for (char& c : input) {
        if (c == ',') {
            c = ' ';
        }
    }
    
    // Use a stringstream to parse the numbers
    std::stringstream ss(input);
    double number;
    
    // Extract numbers from the stringstream and add them to the vector
    while (ss >> number) {
        numbers.push_back(number);
    }
   
    // Generate Diferences
    differences = generateDifferences(numbers);


    // Print the numbers
    std::cout << "Parsed numbers:" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    
    // Print the differences table
    std::cout << "\nDifferences table:" << std::endl;
    for (size_t i = 0; i < differences.size(); ++i) {
        // Add indentation for each level
        for (size_t indent = 0; indent < i; ++indent) {
            std::cout << "  ";  // Two spaces for each level
        }
        
        // Print the row
        for (size_t j = 0; j < differences[i].size(); ++j) {
            std::cout << differences[i][j];
            if (j < differences[i].size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}

