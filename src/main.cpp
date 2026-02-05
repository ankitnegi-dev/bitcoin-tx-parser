#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cstdint>

using namespace std;

/* Convert hex string → byte vector */
vector<unsigned char> hexToBytes(const string &hex) {
    vector<unsigned char> bytes;

    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }

    return bytes;
}

/* Read little-endian integer */
uint32_t readLE(const vector<unsigned char> &data, size_t pos, int size) {
    uint32_t value = 0;

    for (int i = 0; i < size; i++) {
        value |= data[pos + i] << (8 * i);
    }

    return value;
}

/* Convert bytes → reversed hex string (for TXID display) */
string bytesToReversedHex(const vector<unsigned char> &data, size_t pos, int size) {
    stringstream ss;

    for (int i = size - 1; i >= 0; i--) {
        ss << hex << setw(2) << setfill('0') << (int)data[pos + i];
    }

    return ss.str();
}

int main() {
    string hex;
    cout << "Enter raw Bitcoin transaction hex: ";
    cin >> hex;

    vector<unsigned char> tx = hexToBytes(hex);

    cout << "\n--- Bitcoin Transaction Info ---\n";

    /* Version */
    uint32_t version = readLE(tx, 0, 4);
    cout << "Version: " << version << endl;

    size_t pos = 4;

    /* Input count (assume < 0xfd for now) */
    int inputCount = tx[pos];
    pos += 1;

    cout << "Input count: " << inputCount << "\n\n";

    /* Loop through inputs */
    for (int i = 0; i < inputCount; i++) {
        cout << "Input #" << i + 1 << endl;

        string txid = bytesToReversedHex(tx, pos, 32);
        pos += 32;

        uint32_t vout = readLE(tx, pos, 4);
        pos += 4;

        int scriptLen = tx[pos];
        pos += 1;

        pos += scriptLen;  // skip scriptSig

        uint32_t sequence = readLE(tx, pos, 4);
        pos += 4;

        cout << "  Prev TXID : " << txid << endl;
        cout << "  VOUT      : " << vout << endl;
        cout << "  ScriptLen : " << scriptLen << endl;
        cout << "  Sequence  : " << sequence << "\n\n";
    }

    cout << "Parsing stage-1 completed.\n";
    return 0;
}

