#include <iostream>
#include <vector>
using namespace std;

int findUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < n; i++) {
        int nextUgly = min(next2, min(next3, next5));
        ugly[i] = nextUgly;
        if (nextUgly == next2) next2 = 2 * ugly[++p2];
        if (nextUgly == next3) next3 = 3 * ugly[++p3];
        if (nextUgly == next5) next5 = 5 * ugly[++p5];
    }
    return ugly[n - 1];
}

int main() {
    int n = 1500;
    cout << "The 1500'th ugly number is " << findUglyNumber(n) << "." << endl;
    return 0;
}
