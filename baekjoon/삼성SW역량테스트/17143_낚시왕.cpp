/*
# 설명
1초 동안
1. 낚시왕이 오른쪽으로 한 칸 이동
2. 열에 있는 상어 중 땅과 가까운 상어를 잡는다. (상어는 사라짐)
3. 상어 이동
3-1. 만약 한 칸에 상어가 두 마리 이상 있으면 가장 큰 상어만 남기기

상어 정보 (r,c,s,d,z) : (r,c)=위치,s=속력,d=방향,z=크기
d 1:위, 2:아래, 3:오른쪽, 4:왼쪽
상어가 경계에 닿으면 방향 반대로 이동

# 출력
낚시왕이 잡은 상어 크기의 합
*/
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct info {
    int alive, r, c, s, d, z;
};
int R, C, M;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,1,-1 };
vector<info> shark; // 상어 정보
int shark_cnt;
int map[101][101]; // 상어 번호가 저장되어 있음.
int ans;

void catch_shark(int c) {
    for (int i = 1; i <= R; i++) {
        if (map[i][c] >= 0) {
            ans += shark[map[i][c]].z;
            shark[map[i][c]].alive = 0;
            shark_cnt--;
            map[i][c] = -1;
            return;
        }
    }
}

void move_shark() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].alive) {
            // C*2-2 or R*2-2은 결국 제자리이기 때문에 중복 제거
            if(shark[i].d < 3) shark[i].s = shark[i].s % (R * 2 - 2);
            else shark[i].s = shark[i].s % (C * 2 - 2);

            for (int k = 0; k < shark[i].s; k++) {
                int d = shark[i].d;
                int ny = shark[i].r + dy[d];
                int nx = shark[i].c + dx[d];
                // 범위를 넘어가면 방향 바꾸기
                if (ny <= 0 || ny > R || nx <= 0 || nx > C) {
                    if (shark[i].d % 2) shark[i].d++;
                    else shark[i].d--;
                }
                // 한 칸 이동
                shark[i].r += dy[shark[i].d];
                shark[i].c += dx[shark[i].d];
            }
        }
    }
    // 이동을 마친 후 map 업데이트
    memset(map, -1, sizeof(map));
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].alive) {
            // 한 곳에 두 마리 이상 있으면 큰 상어만 남기기
            if (map[shark[i].r][shark[i].c]>=0) {
                int origin = map[shark[i].r][shark[i].c];
                // 다음 상어가 더 크면
                if (shark[origin].z < shark[i].z) {
                    // 기존 상어 제거
                    shark[origin].alive = 0;
                    shark_cnt--;
                    // 맵 업데이트
                    map[shark[i].r][shark[i].c] = i;
                }
                // 기존 상어가 더 크면
                else {
                    // 다음 상어 제거
                    shark[i].alive = 0;
                    shark_cnt--;
                }
            }
            else {
                map[shark[i].r][shark[i].c] = i;
            }
        }
    }
    return;
}

void simulation() {
    int c = 0;
    shark_cnt = M;
    while (c++ < C) {
        // 상어가 있는지 확인
        if (shark_cnt == 0) break;
        // 1. 가까운 상어 잡기
        catch_shark(c);
        // 2. 상어 이동
        move_shark();
    }
    printf("%d", ans);
    return;
}

int main() {
    scanf("%d %d %d", &R, &C, &M);
    memset(map, -1, sizeof(map));
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        shark.push_back({ 1,r,c,s,d,z });
        map[r][c] = i;
    }
    simulation();
    return 0;
}
