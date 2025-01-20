#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int user_input;
    cout << "display my info " << endl;
    cout << "1. name " << endl;
    cout << "2. age " << endl;
    cout << "3. gender " << endl;
    cin >> user_input;

    switch (user_input) {
        case 1:
            cout << "Psi ! " << endl;
            break;
        case 2:
            cout << "99years old" << endl;
            break;
        case 3:
            cout << "man" << endl;
            break;
        default:
            cout << "no questions " << endl;
            break;
    }
}