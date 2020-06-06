/*
군집 위치, 미생물 수, 이동방향
1시간마다
1. 동시에 이동방향에 있는 다음셀로 이동 (이동 중 섞이지 않음).
2. 약품이 칠해진 셀에 도착하면 
- 군집 내 미생물 절반이 죽고, 이동 반대방향
- 홀수인 경우 = 미생물 수/2(소수점 버림)
- 만약, 군집에 미생물이 한 마리있으면 군집이 사라짐.
- 두 개 이상의 군집이 모이는 경우 합쳐짐.
(미생물 수 = 군집 미생물 수 합, 
이동방향 = 미생물 수가 가장 많은 군집의 이동방향)

M시간 후 남아있는 미생물 수 총합 구하기.
*/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct node {
    int y, x, cnt, d;
};
int N, M, K;
vector<int> map[100][100];
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };
vector<node> cell, ncell;

void merge() {
    ncell.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j].size() == 0) continue;
            int sum = 0, cnt = 0, b = 0;
            while (!map[i][j].empty()) {
                int idx = map[i][j].back(); map[i][j].pop_back();
                sum += cell[idx].cnt;

                if (cnt < cell[idx].cnt) {
                    cnt = cell[idx].cnt;
                    b = idx;
                }
            }
            ncell.push_back({ cell[b].y,cell[b].x,sum,cell[b].d });
        }
    }
    cell = ncell;
}

void simulation() {

    // 이동
    for(int i=0;i<cell.size();i++){
        int y = cell[i].y, x = cell[i].x, cnt = cell[i].cnt, d = cell[i].d;
        int ny = y + dy[d], nx = x + dx[d];
        // 약품인 경우, 미생물 절반, 반대방향
        if (ny==0 || ny==N-1 || nx==0 || nx==N-1) {
            cnt /= 2;
            if (d % 2) d++;
            else d--;
        }
        if (cnt > 0) {
            cell[i] = { ny,nx,cnt,d };
            map[ny][nx].push_back(i);
        }
    }
    // 군집 합치기
    merge();
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K;
        memset(map, 0, sizeof(map));
        cell.clear();
        for (int i = 0; i < K; i++) {
            node temp;
            cin >> temp.y >> temp.x >> temp.cnt >> temp.d;
            cell.push_back(temp);
        }
        while (M--) {
            simulation();
            if (cell.size() == 0) break;
        }

        // 미생물 총 수
        int ans = 0;
        if (cell.size() > 0) {
            for (auto cur : cell) ans += cur.cnt;
        }
        else ans = 0;
        cout << '#' << test_case << ' ' << ans << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
