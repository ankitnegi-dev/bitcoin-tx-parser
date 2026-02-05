#include <iostream>
#include <string>

int main() {
    std::string tx_hex;
    std::cout << "Enter raw Bitcoin transaction hex: ";
    std::cin >> tx_hex;

    std::cout << "\n--- Bitcoin Transaction Info ---\n";
    std::cout << "Total hex length: " << tx_hex.length() << " characters\n";

    // 1. Parse version (4 bytes = 8 hex chars)
    if (tx_hex.length() < 8) {
        std::cout << "Invalid transaction: too short\n";
        return 0;
    }

    std::string version_hex = tx_hex.substr(0, 8);
    std::cout << "Version (hex): " << version_hex << "\n";

    // 2. Parse input count (1 byte = 2 hex chars)
    if (tx_hex.length() < 10) {
        std::cout << "Invalid transaction: missing input count\n";
        return 0;
    }

    std::string input_count_hex = tx_hex.substr(8, 2);
    int input_count = std::stoi(input_count_hex, nullptr, 16);
    std::cout << "Input count: " << input_count << "\n";

    // 3. Parse output count (simulated offset)
    int output_offset = 10 + (input_count * 2);
    if (tx_hex.length() >= output_offset + 2) {
        std::string output_count_hex = tx_hex.substr(output_offset, 2);
        int output_count = std::stoi(output_count_hex, nullptr, 16);
        std::cout << "Output count: " << output_count << "\n";
    } else {
        std::cout << "Output count: not available\n";
    }

    std::cout << "Parsing completed (basic v3)\n";
    return 0;
}

