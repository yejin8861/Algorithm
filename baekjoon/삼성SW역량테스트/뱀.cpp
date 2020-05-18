#include<iostream>
#include<queue>
using namespace std;
int N, K, L;
int dir = 1;
int map[101][101]; // map = 1(뱀), 2(사과)
int dy[] = { -1,0,1,0 }; // 상,우,하,좌(시계방향)
int dx[] = { 0,1,0,-1 };
queue< pair<int,int> > q;
deque< pair<int,int> > snake;

bool move() {
    // 몸길이 늘리기
    int y = snake.front().first, x = snake.front().second;
    int ny = y + dy[dir], nx = x + dx[dir];
    // 벽 또는 자기자신의 몸과 부딪히면 종료
    if (ny<1 || ny>N || nx<1 || nx>N || map[ny][nx] == 1) return false;
    
    // 사과가 없으면 몸길이 줄이기
    if (!map[ny][nx]) {
        map[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
    snake.push_front(make_pair(ny,nx));
    map[ny][nx] = 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    int r, c;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        map[r][c] = 2;
    }
    cin >> L;
    int t;
    char d;
    for (int i = 0; i < L; i++) {
        cin >> t >> d;
        if(d=='D') q.push(make_pair(t,1));
        else q.push(make_pair(t,3));
    }
    snake.push_back(make_pair(1,1));
    map[1][1] = 1;
    int time = 0;
    while (++time) {
        if (!move()) {
            cout << time;
            break;
        }
        if (!q.empty()) {
            if (time == q.front().first) { // 방향전환
                dir = (dir + q.front().second) % 4;
                q.pop();
            }
        }
    }
    return 0;
}
