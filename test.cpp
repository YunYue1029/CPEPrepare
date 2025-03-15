#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 定義方向索引：N, E, S, W
vector<char> directions = {'N', 'E', 'S', 'W'};

// 方向對應的移動向量：{dx, dy}
vector< pair<int, int> > movement = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int getDirectionIndex(char dir) {
    for (int i = 0; i < 4; ++i) {
        if (directions[i] == dir) return i;
    }
    return -1; // 不應該發生
}

int main() {
    int max_x, max_y;
    cin >> max_x >> max_y;

    set<pair<int, int> > scent; // 儲存掉落的位置（氣味）

    int x, y;
    char dir;
    string commands;
    
    while (cin >> x >> y >> dir) {
        cin >> commands;

        int dirIndex = getDirectionIndex(dir);
        bool lost = false;

        for (char command : commands) {
            if (command == 'L') {
                dirIndex = (dirIndex + 3) % 4; // 左轉
            } 
            else if (command == 'R') {
                dirIndex = (dirIndex + 1) % 4; // 右轉
            } 
            else if (command == 'F') {
                int new_x = x + movement[dirIndex].first;
                int new_y = y + movement[dirIndex].second;

                // 檢查是否超出邊界
                if (new_x < 0 || new_x > max_x || new_y < 0 || new_y > max_y) {
                    if (scent.count({x, y})) {
                        continue; // 有氣味，忽略這次移動
                    } else {
                        lost = true;
                        scent.insert({x, y}); // 記錄氣味
                        break;
                    }
                }

                // 更新位置
                x = new_x;
                y = new_y;
            }
        }

        // 輸出結果
        cout << x << " " << y << " " << directions[dirIndex];
        if (lost) cout << " LOST";
        cout << endl;
    }

    return 0;
}
