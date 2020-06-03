#include<iostream>
#include<cstring>
using namespace std;
int N, X, ans;
int map[20][20], visited[20][20];

bool is_possible_right(int r, int c) {
    for (int i = c; i > c - X; i--) {
        if (i < 0 || visited[r][i]) return false;
    }
    for (int i = c; i > c - X; i--) {
        visited[r][i] = 1;
    }
    return true;
}

bool is_possible_left(int r, int c) {
    for (int i = c; i < c + X; i++) {
        if (i >= N || visited[r][i]) return false;
    }
    for (int i = c; i < c + X; i++) {
        visited[r][i] = 1;
    }
    return true;
}

void rotate() {
    int ret[20][20] = {};
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            ret[N - 1 - c][r] = map[r][c];
        }
    }
    memcpy(map, ret, sizeof(map));
}

void simulation() {
    int num = 2;
    while (num--) {
        memset(visited, 0, sizeof(visited));
        for (int r = 0; r < N; r++) {
            bool flag = true;
            // 왼 -> 오
            for (int c = 0; c < N - 1; c++) {
                if (map[r][c] < map[r][c + 1]) {
                    if(map[r][c+1] - map[r][c] > 1 || !is_possible_right(r, c)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) continue;

            // 오 -> 왼
            for (int c = N - 1; c > 0; c--) {
                if (map[r][c] < map[r][c - 1]) {
                    if (map[r][c-1] - map[r][c] > 1 || !is_possible_left(r, c)) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) ans++;
        }
        rotate();
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> X;
        ans = 0;
        memset(map, 0, sizeof(map));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        simulation();
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
