#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <vector>

double calculate_entropy(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }
    
    std::unordered_map<char, int> freq_map;
    char c;
    int total_chars = 0;

    while (file.get(c)) {
        if (c != ' ' && c != '\n') { 
            freq_map[c]++;
            total_chars++;
        }
    }

    file.close();

    double entropy = 0.0;
    for (const auto& pair : freq_map) {
        double probability = static_cast<double>(pair.second) / total_chars;
        entropy += probability * log2(probability);
    }

    return -entropy;
}

int main() {
    std::string filename = "vector.txt";
    double entropy = calculate_entropy(filename);
    std::ofstream values;
    values.open("values.txt", std::ios::app);

    if (entropy >= 0) {
        std::cout << "The entropy of the file is: " << entropy << std::endl;
        values << entropy << " ";
    }

    return 0;
}