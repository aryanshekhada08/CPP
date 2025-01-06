#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    double bal = 1000.00;
    double amt;

    try {
        cout << "Enter a deposit amount: " << endl;
        cin >> amt;

        if (amt <= 0) {
            throw invalid_argument("Invalid deposit amount. The amount must be positive.");
        }

        bal = amt + bal;
        cout << "Current balance is: " << bal << endl;

        cout << "Enter a withdrawal amount: " << endl;
        cin >> amt;

        if (amt <= 0) {
            throw invalid_argument("Invalid withdrawal amount. The amount must be positive.");
        }

        if (amt > bal) {
            throw runtime_error("Insufficient funds for withdrawal.");
        }

        bal = bal - amt;
        cout << "Total amount remaining is: " << bal << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
