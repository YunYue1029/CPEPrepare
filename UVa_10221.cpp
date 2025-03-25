#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI acos(-1.0)

int main() {
    double s, a;
    string unit;

    while (cin >> s >> a >> unit) {
        double radius = 6440 + s;
        double angle_rad;

        if (unit == "deg") {
            angle_rad = a * PI / 180.0;
        } else if (unit == "min") {
            angle_rad = a * PI / (180.0 * 60);
        }

        double arc = radius * angle_rad;
        double chord = 2 * radius * sin(angle_rad / 2.0);

        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }

    return 0;
}
