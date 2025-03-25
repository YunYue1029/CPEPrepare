#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int T;
    string line;
    getline(cin, line); // 讀取 T
    T = stoi(line);

    getline(cin, line); // 讀取第一個空行

    for (int t = 0; t < T; ++t) {
        map<string, int> counter;
        int total = 0;

        while (getline(cin, line)) {
            if (line.empty()) break; // 空行代表測資結束
            counter[line]++;
            total++;
        }

        // 輸出排序後的每個樹種
        for (auto& entry : counter) {
            cout << fixed << setprecision(4);
            cout << entry.first << " " << (entry.second * 100.0 / total) << endl;
        }

        if (t != T - 1) cout << endl; // 測資間要空一行
    }

    return 0;
}
