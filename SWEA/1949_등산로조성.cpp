#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node {
    int y, x;
};
int N, K, high, ans;
int map[8][8], visited[8][8];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void dfs(int y, int x, int dist) {
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k], nx = x + dx[k];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (map[ny][nx] < map[y][x]) {
            dfs(ny, nx, dist + 1);
        }
    }
    ans = max(ans, dist);
    return;
}

void find_highest() {
    // 봉우리 찾기
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == high) {
                for (int k = 0; k < 4; k++) {
                    dfs(y, x, 1);
                }

            }
        }
    }
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> K;
        memset(map, 0, sizeof(map));
        ans = 0, high = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                high = max(high, map[i][j]);
            }
        }
        find_highest();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 등산로 깎기
                int origin = map[i][j];
                for (int k = 1; k <= K; k++) {
                    if (origin - k < 0) break;
                    map[i][j] = origin - k;
                    find_highest();
                }
                map[i][j] = origin;
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
