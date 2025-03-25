#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<string>& grid, int r, int c, int side, int M, int N, char target) {
    int half = side / 2;

    int top = r - half;
    int bottom = r + half;
    int left = c - half;
    int right = c + half;

    if (top < 0 || bottom >= M || left < 0 || right >= N) return false;

    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (grid[i][j] != target) return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, Q;
        cin >> M >> N >> Q;

        vector<string> grid(M);
        for (int i = 0; i < M; ++i) {
            cin >> grid[i];
        }

        cout << M << " " << N << " " << Q << endl;

        while (Q--) {
            int r, c;
            cin >> r >> c;
            char centerChar = grid[r][c];

            int side = 1;
            while (isValid(grid, r, c, side + 2, M, N, centerChar)) {
                side += 2;
            }

            cout << side << endl;
        }
    }

    return 0;
}
