#include <iostream>
#include <vector>
#include <string>
#include <sstream>


// Given a sequence of numbers, calculate the differences in successive lines recursively
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

// Extract the first item from each sub-vector in a vector of vectors
std::vector<double> getFirstItems(const std::vector<std::vector<double>>& input) {
    std::vector<double> result;
    for (const auto& subVector : input) {
        if (!subVector.empty()) {
            result.push_back(subVector[0]);
        }
    }
    return result;
}

std::string gregoryNewton(std::vector<double> input) {
    std::ostringstream result;  

    for (size_t i = 0; i < input.size(); i++) {
        if (i == 0) {
            // First term (constant term)
            result << input[i];
        } else if (i == 1) {
            // Special case for i=1, simplify (n)/1! to just n
            result << " + ";
            if (input[i] == 1) {
                result << "n";
            } else {
                result << input[i] << " * n";
            }
        } else {
            // Subsequent terms for i > 1
            result << " + ";
            
            // Numerator part: (n)(n-1)(n-2)...(n-(i-1)) * input[i]
            result << "(";
            for (size_t j = 0; j < i; j++) {
                if (j > 0) {
                    result << " * ";
                }
                if (j == 0) {
                    result << "n";
                } else {
                    result << "(n - " << j << ")";
                }
            }
            if (i > 0) {
                if (input[i] == 1) {
                    result << ")";
                } else {
                    result << " * " << input[i] << ")";
                }
            }
            
            // Denominator part: i!
            result << " / " << i << "!";
        }
    }
    return result.str();
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

    std::cout << "\nGregory Newton Formula: (maxima definition)\n f(n) := " << gregoryNewton(getFirstItems(differences)) << ";" << std::endl;
    
    return 0;
}

