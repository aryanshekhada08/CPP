#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream in;
    string userInput;
    in.open("write.txt");
    if (!in.is_open())
    {
        cout << "file is not opening";
        return 0;
    }
    while (true)
    {
        cout <<" ";
        getline(cin, userInput);
        in << userInput << endl; // Write user input to the file
        in.close();
        cout << "hello day !";
        return 0;
    }
}