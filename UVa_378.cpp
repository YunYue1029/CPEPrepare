#include <iostream>
#include <iomanip>

using namespace std;

void findIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int A1 = y2 - y1, B1 = x1 - x2, C1 = A1 * x1 + B1 * y1;
    int A2 = y4 - y3, B2 = x3 - x4, C2 = A2 * x3 + B2 * y3;

    int D = A1 * B2 - A2 * B1;

    if (D == 0) {
        if (A1 * C2 == A2 * C1 && B1 * C2 == B2 * C1) {
            cout << "LINE" << endl;
        } else {
            cout << "NONE" << endl;
        }
    } else {
        double x = (double)(C1 * B2 - C2 * B1) / D;
        double y = (double)(A1 * C2 - A2 * C1) / D;
        cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
    }
}

int main() {
    int N;
    cin >> N;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    
    while (N--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        findIntersection(x1, y1, x2, y2, x3, y3, x4, y4);
    }
    
    cout << "END OF OUTPUT" << endl;
    return 0;
}
