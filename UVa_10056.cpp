#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int S;
    cin >> S;

    while (S--) {
        int N, I;
        double p;
        cin >> N >> p >> I;

        double numerator = p * pow(1 - p, I - 1);
        double denominator = 1 - pow(1 - p, N);
        double result = numerator / denominator;

        cout << fixed << setprecision(4) << result << endl;
    }

    return 0;
}
