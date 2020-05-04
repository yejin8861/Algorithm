/*
[문제]
자물쇠는 NxN, 열쇠는 MxM
자물쇠엔 홈(0)이 파여 있고 열쇠 또한 홈(0)과 돌기(1) 부분이 있다.
열쇠는 회전, 이동이 가능하며 열쇠의 돌기 부분을 자물쇠의 홈 부분에
딱 맞게 채우면 자물쇠가 열린다.
열쇠의 돌기와 자물쇠의 돌기가 만나서는 안되고
자물쇠의 모든 홈을 채워 비어있는 곳이 없어야 자물쇠를 열 수 있다.

[출력]
열쇠로 자물쇠를 열수 있으면 true, 열 수 없으면 false 반환.
*/

#include <string>
#include <vector>
using namespace std;
int N, M, R, C;
int map[60][60];
int CntHom;
vector<vector<int>> Key;
vector<vector<int>> Lock;

bool check(int offY, int offX) {
    int cnt = 0;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < M; c++) {
            // 자물쇠 범위 안에 있을 때
            if (M - 1 <= offY + r && offY + r < M + N - 1
                && M - 1 <= offX + c && offX + c < M + N - 1) {
                // 둘 다 돌기이면
                if (Key[r][c] && map[offY + r][offX + c]) return false;
                // 자물쇠 홈과 열쇠 돌기가 만났을 때
                if (Key[r][c] && map[offY + r][offX + c] == 0) cnt++;
            }
        }
    }
    if (cnt == CntHom) return true;
    else return false;
}

void rotate() {
    vector<vector<int>> ret;
    ret.resize(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ret[i].push_back(0);
        }
    }
    // 90도 회전
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < M; c++) {
            ret[c][M - 1 - r] = Key[r][c];
        }
    }
    Key = ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    Key = key;
    Lock = lock;
    N = lock.size();
    M = key.size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[M - 1 + i][M - 1 + j] = lock[i][j];
            if (!lock[i][j]) CntHom++;
        }
    }
    R = C = 2 * M + N;
    for (int k = 0; k < 4; k++) {
        // 1. 열쇠 회전
        rotate();
        // 2. 이동
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (check(i, j)) return true;
            }
        }
    }
    return false;
}

int main() {
    solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1,1},{1,1,1,0},{1,1,0,1},{1,0,0,0} });
    //solution({ {0,0,0},{0,0,0},{0,0,0} }, { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } });
}
