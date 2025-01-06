#include <iostream>
#include <fstream>
using namespace std;
 // Check the write.txt file in the same folder..
int main() {
    string line;
    ifstream inFile;
    
    inFile.open("write.txt");
    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return 0;
    }

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    cout << "File reading complete." << endl;
    cout << "Hello day!" << endl;

    return 0;
}
