#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 13
using namespace std;
struct node {
    int y, x, d;
};
int N, K;
int color[MAX][MAX];
int dy[] = { 0,0,0,-1,1 }; // 우,좌,상,하
int dx[] = { 0,1,-1,0,0 };
vector<int> map[MAX][MAX];
vector<node> horse;

vector<int> find_upper(int k) {
    int y = horse[k].y, x = horse[k].x;
    int i = 0;
    for (i = 0; i < map[y][x].size(); i++) {
        if (map[y][x][i] == k) break;
    }
    vector<int> temp(map[y][x].begin() + i, map[y][x].end());
    map[y][x].erase(map[y][x].begin() + i, map[y][x].end());
    return temp;
}

void move(vector<int> temp, int y, int x) {
    for (int n : temp) {
        map[y][x].push_back(n);
        horse[n].y = y, horse[n].x = x; // update
    }
    return;
}

bool simulation(int k) {
    int y = horse[k].y, x = horse[k].x, d = horse[k].d;
    int ny = y + dy[d], nx = x + dx[d];
    // 1. 파란색(2)인 경우 or 범위 벗어난 경우 방향 전환
    if (color[ny][nx] == 2 || ny < 1 || ny > N || nx < 1 || nx > N) {
        if (d % 2) d++;
        else d--;
        horse[k] = { y,x,d };
        // 반대 칸도 파란색인 경우
        ny = y + dy[d], nx = x + dx[d];
        if (color[ny][nx] == 2 || ny < 1 || ny > N || nx < 1 || nx > N) {
            return true;
        }
    }
    vector<int> temp = find_upper(k);
    if (color[ny][nx] == 1) reverse(temp.begin(), temp.end()); // 빨간색이면 reverse
    move(temp, ny, nx);

    // 말이 4개 이상 쌓이는지 확인
    if (map[ny][nx].size() >= 4) return false;
    else return true;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &color[i][j]);
        }
    }
    int y, x, d;
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d", &y, &x, &d);
        horse.push_back({ y,x,d });
        map[y][x].push_back(i);
    }

    int turn = 0;
    while (++turn) {
        if (turn > 1000) {
            printf("-1");
            return 0;
        }
        for (int i = 0; i < horse.size(); i++) {
            if (!simulation(i)) {
                printf("%d", turn);
                return 0;
            }
        }
    }
}
