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
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
struct node {
    int y, x, z;
};
int A[12][12]; // 추가되는 양분
int map[12][12]; // 땅
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[12][12];
vector<node> growth;
vector<node> dead;

void spring() {
    int age = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (tree[i][j].empty()) continue;

            // [y,x]에 나무가 있으면
            vector<int> temp;
            
            sort(tree[i][j].begin(), tree[i][j].end());
            for (int k = 0; k < tree[i][j].size(); k++) {
                // 양분을 먹을 수 있는지 확인
                age = tree[i][j][k];
                if (map[i][j] >= age) {
                    map[i][j] -= age;
                    temp.push_back(age + 1);
                    if ((age+1) % 5 == 0) { // 가을에 번식할 나무 저장
                        growth.push_back({ i,j,age });
                    }
                }
                else
                    dead.push_back({i,j,age});
            }
            tree[i][j] = temp; // 나무 갱신
        }
    }
    return;
}

void summer() {
    // 죽은 나무 자리에 양분 추가
    for (int i = 0; i < dead.size(); i++) {
        int r = dead[i].y;
        int c = dead[i].x;
        map[r][c] += dead[i].z / 2;
    }
    return;
}

void autumn() {
    for (int i = 0; i < growth.size(); i++) {
        for (int k = 0; k < 8; k++) {
            int ny = growth[i].y + dy[k];
            int nx = growth[i].x + dx[k];

            if (ny<1 || ny>N || nx<1 || nx>N) continue;

            tree[ny][nx].push_back(1);
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
    while (K--) {
        dead.clear();
        growth.clear();
        spring(); // 봄
        summer(); // 여름
        autumn(); // 가을
        winter(); // 겨울
    }

    // 나무 개수 구하기
    int ans = 0;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++)
            ans += tree[i][j].size();
    
    return ans;
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
        tree[r][c].push_back(z);
    }

    printf("%d",simulation());
    return 0;
}
