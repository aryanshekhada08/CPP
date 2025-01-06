#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Hello day" << endl;
    fstream file;
    string userInput;

    // Open file for writing
    file.open("write.txt", ios::out);
    if (!file.is_open()) {
        cout << "The file is not opening." << endl;
        return 0;
    }

    cout << "Enter text to write to the file (enter 'exit' to stop): " << endl;
    while (true) {
        getline(cin, userInput);
        if (userInput == "exit") {
            break;
        }
        file << userInput << endl;
    }
    file.close();

    // Open file for reading
    file.open("write.txt", ios::in);
    if (!file.is_open()) {
        cout << "The file is not opening." << endl;
        return 0;
    }

    cout << "Contents of the file:" << endl;
    while (getline(file, userInput)) {
        cout << userInput << endl;
    }
    file.close();

    return 0;
}
