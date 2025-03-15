#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int n) {
    int count = 0;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L, U;
        cin >> L >> U;

        int maxP = L;
        int maxD = countDivisors(L);

        for (int i = L + 1; i <= U; i++) {
            int divCount = countDivisors(i);
            if (divCount > maxD) {
                maxD = divCount;
                maxP = i;
            }
        }

        cout << "Between " << L << " and " << U << ", " << maxP
             << " has a maximum of " << maxD << " divisors." << endl;
    }

    return 0;
}
