#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int s, d;
        cin >> s >> d;

        if ((s + d) % 2 != 0 || (s - d) % 2 != 0 || s < d) {
            cout << "impossible" << endl;
        } else {
            int a = (s + d) / 2;
            int b = (s - d) / 2;
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
