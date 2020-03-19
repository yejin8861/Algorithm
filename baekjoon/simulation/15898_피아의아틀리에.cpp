/*
시간복잡도 O(10*9*8*(4*4)^3)
5x5 격자 모양 가마에 서로 다른 재료 3개를 순서대로 넣어
최고 품질의 폭탄을 만들어야 한다.

10개 이하의 주어진 재료 중 3개를 고른 뒤, 순서를 정해 가마에 넣는다.
각 칸 : 품질을 나타나는 숫자, 원소를 나타내는 색
재료 : 4x4모양, 회전 가능
재료가 위치한 가마의 격자칸에 있는 품질과 원소값은 바뀔 수 있다.
- 격자의 품질은 재료의 효능이 더해진다. 더한 뒤 값이 음수면 0, 9 초과이면 9.
- 격자의 색은 재료의 원소가 흰색인 경우 그대로, 아닌 경우 재료 원소와 같은 색.
(폭탄의 품질) = 7R + 5B + 3G + 2Y

[출력]
재료를 적절히 선택하고 배치해 폭탄의 최대 품질 구하기.
*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
    int num;
    char color;
};
int n;
info map[5][5];
info backup_map[5][5];
info m[10][4][4];
info backup_m[10][4][4];
int offset[10][2];
int ans;
vector<int> visited;


void PutInTheKiln() {
    for (int idx : visited) {
        int off_y = offset[idx][0], off_x = offset[idx][1];
        // m[idx]를 offset부터 4x4로 채우기
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                // 효능
                map[r+off_y][c+off_x].num += m[idx][r][c].num;
                if (map[r+off_y][c+ off_x].num < 0) map[r+ off_y][c+ off_x].num = 0;
                else if (map[r+ off_y][c+ off_x].num > 9) map[r+ off_y][c+ off_x].num = 9;

                // 원소
                if (m[idx][r][c].color == 'W') continue; // 흰색이면 그대로
                map[r+ off_y][c+ off_x].color = m[idx][r][c].color;

            }
        }
    }
}

void Bomb_quality() {
    int R = 0, B = 0, G = 0, Y = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            switch (map[r][c].color) {
            case 'R': R += map[r][c].num; break;
            case 'B': B += map[r][c].num; break;
            case 'G': G += map[r][c].num; break;
            case 'Y': Y += map[r][c].num; break;
            }
        }
    }
    int sum = (7 * R) + (5 * B) + (3 * G) + (2 * Y);
    ans = max(ans, sum);
    return;
}

void rotate(int idx) {
    info temp[4][4];
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            temp[c][3 - r] = m[idx][r][c];
        }
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            m[idx][r][c] = temp[r][c];
        }
    }
}

void simulation(int cnt) {
    if (cnt == 3) { // 모든 재료를 변경했다면
        memcpy(map, backup_map, sizeof(map)); // map 초기화
        PutInTheKiln(); // 3. 조건에 맞게 map update
        Bomb_quality(); // 4. 폭탄 품질 계산
        return;
    }

    for (int i = cnt; i < 3; i++) {
        for (int k = 0; k < 4; k++) {
            // 1. 시계방향으로 90도 회전
            rotate(visited[i]); 

            // 2. (0,0),(0,1),(1,0),(1,1) 4가지 경우 탐색
            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 2; c++) {
                    offset[visited[i]][0] = r, offset[visited[i]][1] = c;
                    simulation(i+1); // 다음 재료 탐색
                }
            }
        }
    }
    
    return;
}

void select(int start) {
    if (visited.size() == 3) {
        // 2. 재료 3개를 골랐으면 가마에 넣기
        // 선택된 재료의 순서에 따라 달라지므로 permutation
        // ex. (0,1,2)순서와 (2,1,0)순서의 결과가 다르다.
        do {
            memcpy(m, backup_m, sizeof(m)); // 기존 재료 정보로 복원
            simulation(0); // 재귀적으로 모든 경우 확인

        } while (next_permutation(visited.begin(), visited.end()));
        return;
    }

    for (int i = start; i < n; i++) {
        visited.push_back(i);
        select(i+1);
        visited.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> m[i][r][c].num;
            }
        }
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> m[i][r][c].color;
            }
        }
    }

    memcpy(backup_m, m, sizeof(m));
    // 1. 재료 3가지 선택하기
    select(0);
    cout << ans;

    return 0;
}

