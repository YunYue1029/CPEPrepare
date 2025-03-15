#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 埃拉托色尼篩法找出 2 ~ 100 的所有質數
vector<int> sievePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    
    isPrime[0] = isPrime[1] = false; // 0 和 1 不是質數
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

// 計算 N! 的質因數分解次數
vector<int> factorizeFactorial(int N, const vector<int>& primes) {
    vector<int> factorCounts(primes.size(), 0);

    for (size_t i = 0; i < primes.size(); i++) {
        int p = primes[i];
        int count = 0, power = p;
        while (power <= N) {
            count += N / power;
            if (N / power < p) break; // 避免溢出
            power *= p;
        }
        factorCounts[i] = count;
    }
    
    return factorCounts;
}

void printFactorialDecomposition(int N, const vector<int>& primes, const vector<int>& factors) {
    cout << setw(3) << N << "! =";

    int count = 0;
    for (size_t i = 0; i < primes.size() && factors[i] > 0; i++) {
        if (count == 15) { // 每 15 個數字換行並縮進
            cout << endl << "      ";
            count = 0;
        }
        cout << setw(3) << factors[i];
        count++;
    }
    cout << endl;
}

int main() {
    vector<int> primes = sievePrimes(100);
    int N;

    while (cin >> N && N != 0) {
        vector<int> factors = factorizeFactorial(N, primes);
        printFactorialDecomposition(N, primes, factors);
    }

    return 0;
}
