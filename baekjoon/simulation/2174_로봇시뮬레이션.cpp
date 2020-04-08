/*
[문제]
로봇 초기 위치는 (x,y)에 있으며 각 로봇은 NWES 중 하나의 방향을 향해 서 있다.

- 명령 세 가지
1. L: 로봇의 방향을 왼쪽으로 90도 회전한다.
2. R: 로봇의 방향을 오른쪽으로 90도 회전한다.
3. F: 로봇의 방향을 기준으로 앞으로 한 칸 움직인다.

- 잘못된 명령 두 가지
1. Robot X crashes into the wall: X번 로봇이 벽에 충돌하는 경우
2. Robot X crashes into robot Y: X번 로봇이 움직이다가 Y번 로봇에 충돌하는 경우

[출력]
문제가 없는 경우엔 "OK"를 그 외의 경우엔 위의 형식대로 출력한다.
만약 충돌이 여러 번 발생하는 경우 가장 먼저 발생하는 충돌을 출력한다.
*/
#include<iostream>
#include<vector>
#define MAX 101
using namespace std;
struct node {
    int y, x, d;
};
int C, R, N, M;
int map[MAX][MAX];
int dy[] = { 0,1,0,-1 }; // 시계 방향(우,하,좌,상)
int dx[] = { 1,0,-1,0 };
vector<node> robot;

bool forward(int n, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int y = robot[n].y, x = robot[n].x, d = robot[n].d;
        int ny = y + dy[d];
        int nx = x + dx[d];

        // 1. 범위를 벗어나는 경우
        if (ny<1 || ny>R || nx<1 || nx>C) {
            cout << "Robot " << n << " crashes into the wall";
            return false;
        }
        // 2. 충돌하는 경우
        for (int j = 1; j <= N; j++) {
            if (ny == robot[j].y && nx == robot[j].x) {
                cout << "Robot " << n << " crashes into robot " << j;
                return false;
            }
        }
        robot[n].y = ny, robot[n].x = nx; // 범위 안에 있으면 update.
    }
    return true;
}

void left(int n, int cnt) { // d+=1
    for (int i = 0; i < cnt; i++)
        robot[n].d = (robot[n].d + 1) % 4;
}

void right(int n, int cnt) { // d+=3
    for (int i = 0; i < cnt; i++) 
        robot[n].d = (robot[n].d + 3) % 4;
}

bool simulation(int n, char c, int cnt) {
    if (c == 'F') {
        if (!forward(n, cnt)) return false;
        else return true;
    }
    else {
        cnt %= 4;
        if (c == 'R') right(n, cnt);
        else left(n, cnt);
        return true;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> C >> R >> N >> M;
    int y, x;
    char d;
    robot.push_back({ 0,0,0 });

    // y축의 방향이 반대이기 때문에 상,하를 반대로 입력받고
    // R: 왼쪽 90도, L: 오른쪽 90도로 설정하면 된다.
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d;
        switch (d) {
        case 'N': d = 1; break;
        case 'E': d = 0; break;
        case 'S': d = 3; break;
        case 'W': d = 2; break;
        }
        robot.push_back({ y,x,d });
    }
    
    int n, cnt;
    char c;
    for (int i = 0; i < M; i++) {
        cin >> n >> c >> cnt;
        if(!simulation(n, c, cnt)) return 0;
    }
    cout << "OK";
    return 0;
}
