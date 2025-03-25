#include <iostream>
using namespace std;

// 計算 GCD（輾轉相除法）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        int G = 0;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += gcd(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}
