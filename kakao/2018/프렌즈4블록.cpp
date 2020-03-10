/*
같은 모양의 블록이 2x2형태로 4개 붙어있는 경우 사라지면서 점수 획득.
1. 조건을 만족하는 2x2 모양이 여러 개 있으면 한꺼번에 지워진다.
2. 지워진 후엔 위에 있는 블록이 빈 공간을 채운다.
더 이상 사라질 블록이 없어질 때 까지 1,2 반복
*/
#include <string>
#include <cstring>
#include <vector>
using namespace std;
char map[31][31];
int check[31][31];
int answer;
vector<vector<char>> v(31);

bool find_block(int m, int n) {
    bool flag = false;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (map[i][j] != 0 && map[i][j] == map[i][j + 1]
                && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1]) {
                flag = true;
                check[i][j] = 1;
                check[i][j + 1] = 1;
                check[i + 1][j] = 1;
                check[i + 1][j + 1] = 1;
            }
        }
    }
    return flag;
}

void update_map(int m, int n) {
    memset(map, 0, sizeof(map));
    for (int c = 0; c < n; c++)
        for (int r = 0; r < v[c].size(); r++)
            map[m - 1 - r][c] = v[c][r];
}

void remove_block(int m, int n) {
    for (int c = 0; c < n; c++) {
        vector<char> temp;
        for (int r = m - 1; r >= 0; r--) {
            if (!check[r][c]) {
                temp.push_back(map[r][c]);
            }
            else answer++;
        }
        v[c] = temp;
    }
}

int solution(int m, int n, vector<string> board) {
    
    // board를 vector에 복사
    for (int c = 0; c < n; c++) {
        for (int r = m - 1; r >= 0; r--) {
            v[c].push_back(board[r][c]);
        }
    }

    while (1) {
        // 1. vector를 map에 복사 (빈 칸 제거)
        update_map(m, n);
        // 2. 붙어있는 2x2블록 찾기, 없으면 return
        if (!find_block(m, n)) break;
        // 3. vector에서 해당 위치 블록 제거
        remove_block(m,n);
    }
    
    printf("%d", answer);
    return answer;
}

int main() {
    vector<string> s = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    solution(4, 5, s);
    /*vector<string> s = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    solution(6, 6, s);*/
}
