#include <iostream>
#include <string>

int main() {
    std::string txHex;

    std::cout << "Enter raw Bitcoin transaction hex: ";
    std::cin >> txHex;

    std::cout << "\n--- Transaction Info ---\n";
    std::cout << "Hex length: " << txHex.length() << " characters\n";

    if (txHex.length() < 8) {
        std::cout << "Invalid transaction (too short)\n";
        return 0;
    }

    std::string versionHex = txHex.substr(0, 8);
    std::cout << "Version (hex): " << versionHex << "\n";

    std::cout << "Parsing completed (basic)\n";
    return 0;
}
