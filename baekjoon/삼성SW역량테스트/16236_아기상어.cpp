/*
시간복잡도 O(N*4)
아기 상어 크기=2, 1초에 상하좌우 중 한 칸으로 이동
물고기 크기 > 상어 크기 : X
물고기 크기 = 상어 크기 : 지나갈 순 있지만 먹진 못함
물고기 크기 < 상어 크기 : 지나가면서 먹음
크기만큼 물고기를 먹으면 크기 +1
- 종료조건
1. 물고기가 없는 경우
2. 상어 크기 이상의 물고기만 남은 경우 = 먹을 수 X
*/

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int N, time;
int map[22][22];
int sy, sx, shark_size = 2;
int dy[] = { -1,0,0,1 }; // 위,왼,오른,아래
int dx[] = { 0,-1,1,0 };
int total_fish, eaten_fish;
int visited[22][22];

bool is_possible() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && map[i][j] < shark_size) return true;
        }
    }
    return false;
}

bool find_fish() {
    int dist = 0, flag = 0;
    queue<pair<int, int>> q;
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    q.push(make_pair(sy, sx));
    
    while (!q.empty()) {
        int s = q.size();

        for (int i = 0; i < s; i++) {
            int y = q.front().first;
            int x = q.front().second; q.pop();
            
            // 4. 물고기가 작으면 pq에 추가
            if (map[y][x] && map[y][x] < shark_size && !visited[y][x]) {
                visited[y][x] = 1;
                pq.push(make_pair(y, x));
                flag = 1;
            }
            visited[y][x] = 1;
            if (flag) continue; // 최단거리 찾았으면 더 이동X. 남은 것만 검사
            // 6. 먹을 물고기가 없으면 이동
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
                    visited[ny][nx] || map[ny][nx]>shark_size) continue;
                q.push(make_pair(ny, nx));
                
            }
        }
        dist++;
        // 5. 먹을 수 있는 물고기 중에서 위쪽에 있는 물고기 먹기
        if (!pq.empty()) {
            int y = pq.top().first;
            int x = pq.top().second;
            map[y][x] = 0;
            sy = y, sx = x; // 상어 위치 옮기기
            eaten_fish++; total_fish--;
            if (eaten_fish == shark_size) {
                shark_size++;
                eaten_fish = 0;
            }
                
            time += dist-1;
            //printf("%d", time);
            return true;
        }
    }
    return false;
}

void simulation() {
    while (1) {
        // 1. 물고기가 없는 경우 종료
        if (total_fish==0) return;
        // 2. 먹을 수 있는 물고기가 없으면 종료
        if (!is_possible()) return;

        // 3. 현재 위치에서 가장 가까운 물고기를 찾는데
        // 상어가 더 이상 갈 곳이 없으면 종료
        memset(visited, 0, sizeof(visited));
        if (!find_fish()) return;
    }
    return; 
}


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                sy = i, sx = j;
                map[i][j] = 0;
            }
            else if(map[i][j]) total_fish++;
        }
    }
    simulation();
    printf("%d",time);
    return 0;
}
