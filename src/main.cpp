#include <iostream>
#include <string>

int main() {
    std::string tx_hex;

    std::cout << "Enter raw Bitcoin transaction hex: ";
    std::cin >> tx_hex;

    std::cout << "\n--- Transaction Info ---\n";
    std::cout << "Hex length: " << tx_hex.length() << " characters\n";

    // Check minimum length for version (4 bytes = 8 hex chars)
    if (tx_hex.length() >= 8) {
        std::string version = tx_hex.substr(0, 8);
        std::cout << "Version (hex): " << version << "\n";
    } else {
        std::cout << "Invalid transaction: too short for version\n";
        return 0;
    }

    // Check for input count byte (next 2 hex chars after version)
    if (tx_hex.length() >= 10) {
        std::string input_count_hex = tx_hex.substr(8, 2);

        // Convert hex → integer
        int input_count = std::stoi(input_count_hex, nullptr, 16);

        std::cout << "Number of Inputs: " << input_count << "\n";
    } else {
        std::cout << "Input count not available\n";
    }

    std::cout << "Parsing completed (basic v2)\n";
    return 0;
}
