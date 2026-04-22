#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty() || rails >= (int)plaintext.size()) {
        return plaintext;
    }

    vector<string> fence(rails);
    int row = 0;
    int dir = 1; // 1 = đi xuống, -1 = đi lên

    for (char c : plaintext) {
        fence[row] += c;

        if (row == 0) {
            dir = 1;
        } else if (row == rails - 1) {
            dir = -1;
        }

        row += dir;
    }

    string ciphertext;
    for (const string &r : fence) {
        ciphertext += r;
    }

    return ciphertext;
}

string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty() || rails >= (int)ciphertext.size()) {
        return ciphertext;
    }

    int n = ciphertext.size();

    // Bước 1: đánh dấu đường zigzag
    vector<vector<char>> fence(rails, vector<char>(n, '\n'));

    int row = 0;
    int dir = 1;

    for (int col = 0; col < n; ++col) {
        fence[row][col] = '*';

        if (row == 0) {
            dir = 1;
        } else if (row == rails - 1) {
            dir = -1;
        }

        row += dir;
    }

    // Bước 2: điền ciphertext vào các vị trí đã đánh dấu
    int idx = 0;
    for (int r = 0; r < rails; ++r) {
        for (int c = 0; c < n; ++c) {
            if (fence[r][c] == '*' && idx < n) {
                fence[r][c] = ciphertext[idx++];
            }
        }
    }

    // Bước 3: đọc lại theo đường zigzag để lấy plaintext
    string plaintext;
    plaintext.reserve(n);

    row = 0;
    dir = 1;

    for (int col = 0; col < n; ++col) {
        plaintext += fence[row][col];

        if (row == 0) {
            dir = 1;
        } else if (row == rails - 1) {
            dir = -1;
        }

        row += dir;
    }

    return plaintext;
}

string read_message_from_file(const string &path) {
    ifstream fin(path);
    if (!fin) {
        return "";
    }

    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Read from file and encrypt\n";
    cout << "Choose: ";

    int choice;
    if (!(cin >> choice)) {
        cout << "Invalid choice input.\n";
        return 0;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        if (message.empty()) {
            cout << "Cannot read message from file data/input.txt.\n";
            return 0;
        }
        cout << "Message from file: " << message << "\n";
    } else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    if (!(cin >> rails)) {
        cout << "Invalid rails input.\n";
        return 0;
    }

    if (rails <= 1) {
        cout << "Invalid rails. Please enter a value greater than 1.\n";
        return 0;
    }

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}