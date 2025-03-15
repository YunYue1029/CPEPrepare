#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <set>
#include <iomanip>

using namespace std;

// 查找最終響鈴的分機
int findFinalTarget(int time, int ext, unordered_map<int, vector<tuple<int, int, int>>> &forwarding) {
    set<int> visited; // 記錄是否有循環轉接

    while (true) {
        if (visited.count(ext)) return 9999; // 發生循環，轉接到 9999
        visited.insert(ext);

        if (forwarding.find(ext) == forwarding.end()) return ext; // 無轉接，直接響鈴

        bool foundForwardingRule = false;
        for (auto &[start, end, target] : forwarding[ext]) {
            if (time >= start && time <= end) {
                ext = target; // 轉接到新目標
                foundForwardingRule = true;
                break;
            }
        }

        if (!foundForwardingRule) return ext; // 若沒有找到匹配的轉接規則，則響鈴
    }
}

int main() {
    int N;
    cin >> N;
    cout << "CALL FORWARDING OUTPUT" << endl;

    for (int system_no = 1; system_no <= N; ++system_no) {
        unordered_map<int, vector<tuple<int, int, int>>> forwarding;
        vector<pair<int, int>> calls;

        // 讀取轉接規則
        while (true) {
            int source, start, duration, target;
            cin >> source;
            if (source == 0) break; // 轉接輸入結束
            cin >> start >> duration >> target;
            forwarding[source].emplace_back(start, start + duration, target);
        }

        // 讀取來電請求
        while (true) {
            int time, ext;
            cin >> time;
            if (time == 9000) break; // 來電輸入結束
            cin >> ext;
            calls.emplace_back(time, ext);
        }

        // 處理來電並輸出結果
        cout << "SYSTEM " << system_no << endl;
        for (auto &[time, ext] : calls) {
            int final_target = findFinalTarget(time, ext, forwarding);
            cout << "AT " << setw(4) << setfill('0') << time
                 << " CALL TO " << setw(4) << setfill('0') << ext
                 << " RINGS " << setw(4) << setfill('0') << final_target << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}
