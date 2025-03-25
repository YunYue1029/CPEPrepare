#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        vector<long long> sequence;

        if (m <= 1) {
            if (n == 1) cout << "1\n";
            else cout << "Boring!\n";
            continue;
        }

        bool ok = true;
        while (n > 1) {
            if (n % m != 0) {
                ok = false;
                break;
            }
            sequence.push_back(n);
            n /= m;
        }

        if (!ok || n != 1) {
            cout << "Boring!" << endl;
        } else {
            sequence.push_back(1);
            for (size_t i = 0; i < sequence.size(); ++i) {
                if (i > 0) cout << " ";
                cout << sequence[i];
            }
            cout << endl;
        }
    }
    return 0;
}
