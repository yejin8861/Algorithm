/*
[문제]
성의 지도를 입력받아 다음을 계산한다.
1. 이 성에 있는 방의 개수
2. 가장 넓은 방의 넓이
3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

- 벽에 대한 정보
1 : 서쪽, 2: 북쪽, 4: 동쪽, 8: 남쪽의 총 합 (비트 연산)

[출력]
첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.
*/
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 50
using namespace std;
struct node {
    int y, x;
};
int R, C;
int map[MAX][MAX], room[MAX][MAX], visited[MAX][MAX];
int CountRoom, MaxSpace;
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };
vector<int> RoomSpace;
vector<set<int>> connect(3000);

int bfs(int y, int x) {
    queue<node> q;
    q.push({ y,x });
    visited[y][x] = 1;
    room[y][x] = CountRoom;

    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        
        // 서,북,동,남 중 갈 수 있는 곳 확인
        int n = map[y][x];
        for (int k = 0; k < 4; k++) {
            if (n & (1 << k)) continue;
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C 
                || visited[ny][nx]) continue;
            
            visited[ny][nx] = 1;
            room[ny][nx] = CountRoom;
            cnt++;
            q.push({ ny,nx });
        }
    }
    RoomSpace.push_back(cnt);
    return cnt;
}

void make_room() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j]) continue;
            CountRoom++;
            MaxSpace = max(MaxSpace, bfs(i, j));
        }
    }
}

void connected_room() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int n = room[i][j];
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k], nx = j + dx[k];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C
                    || room[ny][nx] == n) continue;
                connect[n].insert(room[ny][nx]);
            }
        }
    }
}

int main() {
    scanf("%d %d", &C, &R);
    int n;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 1. 방의 개수, 가장 넓은 방의 넓이 구하기
    make_room();
    // 2. 연결된 방 찾기
    connected_room();
    // 3. 연결된 두 방 넓이의 합 최댓값 구하기
    int GetSpace = 0;
    for (int i = 1; i <= CountRoom; i++) {
        for (int n : connect[i]) {
            GetSpace = max(GetSpace, RoomSpace[i - 1] + RoomSpace[n - 1]);
        }
    }
    printf("%d\n%d\n%d", CountRoom, MaxSpace, GetSpace);
    return 0;
}
