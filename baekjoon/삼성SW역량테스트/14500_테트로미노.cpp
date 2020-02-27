/*
시간복잡도O(N*M*40)
크기가 4인 블록들 5개(회전, 대칭 가능) 중 하나를
NxM종이 위에 놓았을 때 놓인 칸의 수들의 최대합 구하기

생각 한 풀이
: 각 칸에 대하여 가능한 모형 전부 검사(브루트포스)
그 칸을 기준점으로 도형 회전, 대칭(만들어질 수 있는 도형 총 19가지(이지만 코드 편의상 40가지))
rouph하게 잡아도 연산 대략 2억번(2초) 이하.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int map[502][502];
int ny[4], nx[4];
int ans;
// t[0] : ㅡ, t[1] : ㅁ, t[2] : ㄱ, t[3] : z, t[4] : ㅜ
vector<pair<int, int>>tetromino[5];

void count_sum() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (ny[i] < 0 || ny[i] >= N || nx[i] < 0 || nx[i] >= M) return;
        sum += map[ny[i]][nx[i]];
    }
        
    ans = max(ans, sum);
    return;
}

void rotate(int y, int x) {
    // (y,x) 기준으로 90도 회전
    for (int i = 0; i < 4; i++) {
        int dy = y - ny[i], dx = x - nx[i];
        ny[i] = y - dx;
        nx[i] = x + dy;
    }
    return;
}
void reverse(int y,int x) {
    // (y,x) 기준으로 좌우반전
    for (int i = 0; i < 4; i++) {
        int dx = x - nx[i];
        nx[i] = x + dx;
    }
    return;
}

void simulation(int y, int x) {
    // y,x를 기준점으로 도형을 회전, 대칭
    
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 4; k++) {
            ny[k] = y + tetromino[i][k].first;
            nx[k] = x + tetromino[i][k].second;
        }

        for (int n = 0; n < 2; n++) {
            for (int j = 0; j < 4; j++) {
                count_sum(); // 최대합 구하기
                rotate(y, x); // 90도 회전
            }
            // 좌우대칭
            reverse(y, x);
        }
        
    }
    return;
}

void make_tetromino() {
    // 기준점만 고정하면 push순서는 상관없음
    // 0. ㅡ
    for (int i = 0; i < 4; i++)
        tetromino[0].push_back(make_pair(0, i));
    // 1. ㅁ
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) 
            tetromino[1].push_back(make_pair(i, j));
    // 2. ㄱ
    tetromino[2].push_back(make_pair(0, 0));
    tetromino[2].push_back(make_pair(-1, 0));
    tetromino[2].push_back(make_pair(-2, 0));
    tetromino[2].push_back(make_pair(0, 1));

    // 3. z
    tetromino[3].push_back(make_pair(0, 0));
    tetromino[3].push_back(make_pair(-1, 0));
    tetromino[3].push_back(make_pair(0, 1));
    tetromino[3].push_back(make_pair(1, 1));

    // 4. ㅜ
    tetromino[4].push_back(make_pair(0, 0));
    tetromino[4].push_back(make_pair(0, -1));
    tetromino[4].push_back(make_pair(0, 1));
    tetromino[4].push_back(make_pair(1, 0));

    return;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    make_tetromino(); // 도형 만들기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            simulation(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}
