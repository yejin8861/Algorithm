/*
각 세로방향에 동일한 특성의 셀들이 K개 이상
연속적으로 있는 경우에만 성능검사 통과

특정 행에 약품을 투입하면 그 행의 모든 셀들이 변경
약품 투입횟수 최소 구하기
두께 D, 가로크기 W, 합격기준 K
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int idx, n;
};
int D, W, K, flag;
int map[13][20];
vector<node> v;

bool is_possible() {
    for (int c = 0; c < W; c++) {
        int cnt = 1, Len = 1;
        for (int r = 0; r < D-1; r++) {
            if (map[r][c] != map[r+1][c]) {
                Len = max(Len, cnt);
                cnt = 1;
            }
            else cnt++;
        }
        Len = max(Len, cnt);
        // Len이 K보다 작은 경우 false.
        if (Len < K) return false;
    }
    return true;
}
void change_row() {
    for (auto temp : v) {
        int r = temp.idx, n = temp.n;
        for (int c = 0; c < W; c++) {
            map[r][c] = n;
        }
    }
}

void choice(int start, int cnt) {
    if (v.size() == cnt) {
        int backup[13][20] = { };
        memcpy(backup, map, sizeof(map));
        change_row();
        if (is_possible()) flag = 1;
        memcpy(map, backup, sizeof(map));
        return;
    }

    for (int i = start; i < D; i++) {
        for (int k = 0; k < 2; k++) {
            v.push_back({ i, k });
            choice(i + 1, cnt);
            v.pop_back();
        }
        if (flag) return;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> D >> W >> K;
        memset(map, 0, sizeof(map));
        flag = 0;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i <= D; i++) {
            choice(0, i);
            if (flag) {
                cout << '#' << test_case << ' ' << i << '\n';
                break;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
