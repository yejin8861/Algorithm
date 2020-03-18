/*
동굴은 RxC칸으로 이루어져 있다.
각 칸은 '.': 빈 칸, 'x': 미네랄로 이루어짐.

창영: 동굴의 왼쪽, 상근: 오른쪽
두 사람은 번갈아가며 막대기를 던지는데 땅과 수평을 이루며 날아간다.
막대가 날아가다 미네랄을 만나면, 그 칸에 있는 미네랄은 파괴되고 막대는 그 자리에서 멈춘다.

공중에 떠있는 미네랄은 다른 미네랄을 만나거나 땅에 닿을 때까지 아래로 떨어진다.

[출력]
모든 막대를 던지고 난 이후에 미네랄 모양을 구하라.
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;
struct node {
    int y, x;
};
int R, C, N;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int> bar;
vector<node> Air_cluster;


void bfs(int y, int x) {

    queue<node> q;
    q.push({ y,x });
    visited[y][x] = true;
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny <= 0 || ny > R || nx <= 0 || nx > C ||
                visited[ny][nx] || map[ny][nx] == '.') continue;
            visited[ny][nx] = true;
            q.push({ ny,nx });
        }
    }
}


void clustering() {
    memset(visited, false, sizeof(visited));
    for (int j = 1; j <= C; j++) {
        // 땅과 연결된 클러스터링 체크
        if (map[R][j] == 'x' && !visited[R][j]) {
            bfs(R, j);
        }
    }
    Air_cluster.clear();
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 'x' && !visited[i][j]) {
                Air_cluster.push_back({ i,j });
            }
        }
    }
    return;
}

void LeftToRight(int r) {
    for (int c = 1; c <= C; c++) {
        if (map[r][c]=='x') {
            map[r][c] = '.';
            return;
        }
    }
}

void RightToLeft(int r) {
    for (int c = C; c > 0; c--) {
        if (map[r][c]=='x') {
            map[r][c] = '.';
            return;
        }
    }
}

void down() {
    // map에서 공중에 있는 클러스터 지우기
    for (int i = 0; i < Air_cluster.size(); i++) {
        int y = Air_cluster[i].y, x = Air_cluster[i].x;
        map[y][x] = '.';
    }

    int dist = 1;
    while (1) {
        for (int i = 0; i < Air_cluster.size(); i++) {
            int y = Air_cluster[i].y, x = Air_cluster[i].x;
            // 땅에 닿거나 다른 클러스터링을 만나는 순간의 dist구하기
            if (y + dist > R || map[y + dist][x] == 'x') {
                // dist만큼 내리기
                for (int k = 0; k < Air_cluster.size(); k++) {
                    int y = Air_cluster[k].y, x = Air_cluster[k].x;
                    map[y + dist - 1][x] = 'x';
                }
                return;
            }
        }
        dist++;
    }
    
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
        }
    }

    cin >> N;
    int n;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        bar.push_back(R + 1 - n);
    }

    for (int i = 0; i < bar.size(); i++) {
        // 1. 막대와 가장 가까운 미네랄 지우기
        if (i % 2) RightToLeft(bar[i]);
        else LeftToRight(bar[i]);

        // 2. 클러스터링
        clustering();

        // 3. 공중에 있는 클러스터링 내리기
        if (Air_cluster.size() > 0) {
            down();
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}
