/*
dfs를 거칠때마다 이전 상태를 저장하는 것이 핵심
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, M;
int map[10][10]; // map[y][x]
int ans = INF;
class info {
public:
    int y, x, n;
};
vector<info> cctv;
vector<int> dir[6] = { {0},
    {0b0001,0b0010,0b0100,0b1000}, // 1번
    {0b0011,0b1100}, // 2번
    {0b1010,0b1001,0b0110,0b0101}, // 3번
    {0b0111,0b1011,0b1101,0b1110}, // 4번
    {0b1111} }; // 5번

void _watch(int d, int r, int c){
    if (d & (1<<3)) { // 상
        for (int i = r-1; i >= 0; i--) {
            if (map[i][c] == 6) break;
            else if (0 < map[i][c] && map[i][c] < 6) continue;
            map[i][c] = -1;
        }
    }
    if (d & (1 << 2)) { // 하
        for (int i = r+1; i < N; i++) {
            if (map[i][c] == 6) break;
            else if (0 < map[i][c] && map[i][c] < 6) continue;
            map[i][c] = -1;
        }
    }
    if (d & (1 << 1)) { // 좌
        for (int i = c-1; i >= 0; i--) {
            if (map[r][i] == 6) break;
            else if (0 < map[r][i] && map[r][i] < 6) continue;
            map[r][i] = -1;
        }
    }
    if (d & (1 << 0)) { // 우
        for (int i = c+1; i < M; i++) {
            if (map[r][i] == 6) break;
            else if (0 < map[r][i] && map[r][i] < 6) continue;
            map[r][i] = -1;
        }
    }

}
void dfs(int idx) {
    if (idx == cctv.size()) { // 사각지대 카운트
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    for (int i = idx; i < cctv.size(); i++) {
        for (int k = 0; k < dir[cctv[i].n].size(); k++) {
            int backup[10][10];
            memcpy(backup, map, sizeof(map)); // 현재상태 저장
            _watch(dir[cctv[i].n][k], cctv[i].y, cctv[i].x);
            dfs(i+1);
            memcpy(map, backup, sizeof(map)); // 원래상태 불러오기
        }
    }
}


int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (0 < map[i][j] && map[i][j] < 6)
                cctv.push_back(info{i,j,map[i][j]});
        }
    }
    dfs(0);
    printf("%d", ans);
    return 0;
}
