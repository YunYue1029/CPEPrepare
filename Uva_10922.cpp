#include <iostream>
#include <string>
using namespace std;

int digit_sum(const string& num) {
    int sum = 0;
    for (char c : num) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    string number;
    while (cin >> number && number != "0") {
        int degree = 0;
        string current = number;
        int sum = digit_sum(current);

        if (sum % 9 != 0) {
            cout << number << " is not a multiple of 9." << endl;
        } else {
            degree = 1;
            while (sum >= 10) {
                sum = digit_sum(to_string(sum));
                degree++;
            }
            cout << number << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
        }
    }
    return 0;
}
