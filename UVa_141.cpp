#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> rotate90(const vector<vector<int>>& board, int N) {
    vector<vector<int>> rotated(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = board[i][j];
        }
    }
    return rotated;
}

vector<vector<vector<int>>> getAllRotations(const vector<vector<int>>& board, int N) {
    vector<vector<vector<int>>> rotations;
    rotations.push_back(board);
    auto rotated90 = rotate90(board, N);
    auto rotated180 = rotate90(rotated90, N);
    auto rotated270 = rotate90(rotated180, N);
    rotations.push_back(rotated90);
    rotations.push_back(rotated180);
    rotations.push_back(rotated270);
    return rotations;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<vector<int>> board(N, vector<int>(N, 0));
        set<vector<vector<int>>> seenStates;
        bool gameOver = false;
        int moveCount = 0;
        for (int i = 0; i < 2 * N; i++) {
            int x, y;
            char op;
            cin >> x >> y >> op;
            x--, y--;
            
            if (op == '+') {
                board[x][y] = 1;
            } else {
                board[x][y] = 0;
            }
            moveCount++;
            
            auto rotations = getAllRotations(board, N);
            for (const auto& rot : rotations) {
                if (seenStates.count(rot)) {
                    cout << "Player " << (i % 2 == 0 ? 2 : 1) << " wins on move " << moveCount << "\n";
                    gameOver = true;
                    break;
                }
            }
            if (gameOver) break;
            seenStates.insert(board);
        }
        if (!gameOver) {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
