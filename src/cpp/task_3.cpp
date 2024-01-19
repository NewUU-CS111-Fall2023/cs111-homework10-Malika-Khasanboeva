#include <iostream>
using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    int i = 0, j = 0;
    while (num1[i] == '0') i++; // skip leading zeros
    while (num2[j] == '0') j++;
    if (num1.size() - i > num2.size() - j) {
        cout << 1 << endl;
    } else if (num1.size() - i < num2.size() - j) {
        cout << 1 << " " << 1 << endl;
    } else {
        while (i < num1.size()) {
            if (num1[i] > num2[j]) {
                cout << 1 << endl;
                return 0;
            } else if (num2[j] > num1[i]) {
                cout << 1 << " " << 1 << endl;
                return 0;
            }
            i++;
            j++;
        }
        cout << 1 << endl; // numbers are equal
    }
    return 0;
}
