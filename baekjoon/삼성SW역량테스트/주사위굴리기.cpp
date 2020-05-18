#include<cstdio>
#include<queue>
using namespace std;
int map[20][20];
int N, M, y, x, K;
int dir[1001];
int dy[] = { 0,0,0,-1,1 }; // 동,서,북,남
int dx[] = { 0,1,-1,0,0 };

int main() {
    scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    deque<int> row = { 0,0,0 };
    deque<int> col = { 0,0,0,0 };
    int d;
    for (int i = 0; i < K; i++) {
        scanf("%d", &d);
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        y = ny, x = nx;
        switch (d){
        case 1: // 동
            row.push_front(col.back());
            col[3] = row.back();
            row.pop_back();
            col[1] = row[1];
            break;
        case 2: // 서
            row.push_back(col.back());
            col[3] = row.front();
            row.pop_front();
            col[1] = row[1];
            break;
        case 3: // 북
            col.push_back(col.front());
            col.pop_front();
            row[1] = col[1];
            break;
        case 4: // 남
            col.push_front(col.back());
            col.pop_back();
            row[1] = col[1];
            break;
        }
        if (map[y][x] == 0) { // 1. 이동한 칸이 0인 경우
            map[y][x] = col[3]; // 칸에 복사
        }
        else { // 2. 0이 아닌 경우
            col[3] = map[y][x]; // 주사위 바닥에 복사
            map[y][x] = 0;
        }
        printf("%d\n", col[1]);
    }
    return 0;
}
