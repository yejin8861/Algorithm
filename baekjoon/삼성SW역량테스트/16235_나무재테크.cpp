/*
# 문제
N*N땅, 처음엔 모든 칸에 양분 5만큼 있다.
M개의 나무, 같은 칸에 여러 개의 나무 가능

사계절 반복
-봄: 나이+1, 나무가 있는 칸에서만 양분 얻음 
    1. 여러 개 있으면 나이 어린 나무부터 먹음
    2. 자신의 나이만큼 양분을 먹을 수 없으면 양분을 먹지 않고 즉시 죽음.
-여름 : 봄에 죽은 나무가 양분으로 변함. (나이/2)
-가을 : 나무 번식(나이가 5의 배수), 인접한 8개의 칸에 나이가 1인 나무 생성
        땅을 벗어나는 곳엔 X
-겨울 : 땅에 양분 추가(A[r][c])

# 출력
K년이 지난 후 땅에 살아있는 나무 개수 출력
*/
#include<cstdio>
#include<queue>
#include<algorithm>
#define p pair<int,int>
using namespace std;
int N, M, K;

int A[12][12]; // 추가되는 양분
int map[12][12]; // 땅
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
deque<pair<int, p>> tree;
deque<pair<int, p>> dead;
deque<pair<int, p>> growth;

void spring() {
    int s = tree.size();
    for (int i = 0; i < s; i++) {
        int y = tree.front().second.first;
        int x = tree.front().second.second;
        int age = tree.front().first;
        tree.pop_front();

        // 양분 섭취 가능
        if (map[y][x] >= age) {
            map[y][x] -= age;
            tree.push_back({ age + 1, {y,x} });
            /*if ((age + 1) % 5 == 0) {
                growth.push_back({ age + 1,{y,x} });
            }*/
        }
        else { // 불가능
            dead.push_back({ age,{y,x} });
        }
    }
    return;
}

void summer() {
    // 죽은 나무 자리에 양분 추가
    while (!dead.empty()) {
        int y = dead.front().second.first;
        int x = dead.front().second.second;
        int age = dead.front().first;
        dead.pop_front();

        map[y][x] += age / 2;
    }
    return;
}

void autumn() {
    while (!growth.empty()) {
        int y = growth.front().second.first;
        int x = growth.front().second.second;
        int age = growth.front().first;
        growth.pop_front();

        for (int k = 0; k < 8; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny<1 || ny>N || nx<1 || nx>N) continue;
            tree.push_front({ 1,{ny,nx} });
        }
    }
    return;
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] += A[i][j];
        }
    }
    return;
}

int simulation() {
    sort(tree.begin(), tree.end());
    while (K--) {
        spring(); // 봄
        summer(); // 여름
        autumn(); // 가을
        winter(); // 겨울
    }

    // 나무 개수 구하기
    return tree.size();
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            map[i][j] = 5;
        }
    }
    for (int i = 1; i <= M; i++) {
        int r, c, z;
        scanf("%d %d %d", &r, &c, &z);
        tree.push_back({ z,{r,c} });
    }

    printf("%d",simulation());
    return 0;
}
