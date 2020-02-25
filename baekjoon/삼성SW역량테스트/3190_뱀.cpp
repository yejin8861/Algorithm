#include<cstdio>
#include<deque>
#define MAX 102
using namespace std;
int N, K, L;
int map[MAX][MAX]; // 뱀=1, 사과=2;
int time[10002];
int dy[] = { -1,0,1,0 }; // 상,우,하,좌
int dx[] = { 0,1,0,-1 };
int d = 1; // 오른쪽 방향
int ans;
deque<pair<int, int>> snake;

int simulation(int y, int x) {
    while (1) {
        // 1. 시간 증가
        ans++; 
        
        // 2. 뱀 이동
        int ny = y + dy[d];
        int nx = x + dx[d];

        // 3. 끝나는지 확인
        // 뱀이 벽에 닿거나, 자기자신의 몸과 부딪히는 경우
        if (ny<1 || ny>N || nx<1 || nx>N || map[ny][nx] == 1) return ans;
        
        if (map[ny][nx] == 0) { // 이동한 칸에 사과가 없다면
            int ty = snake.front().first;
            int tx = snake.front().second;
            snake.pop_front(); // 꼬리 제거
            map[ty][tx] = 0;
        }
        snake.push_back(make_pair(ny, nx));
        map[ny][nx] = 1;

        // 4. 회전 확인
        if (time[ans]) {
            d = (d+time[ans])%4; // 방향 바꾸기
        }
        y = ny, x = nx; // 이동한 곳에서 다시 진행
    }
}


int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= K; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        map[y][x] = 2; // 사과 존재
    }
    scanf("%d", &L);
    for (int i = 1; i <= L; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        if (c == 'D') time[x] = 1; // 시계 방향 90도
        else time[x] = 3; // 반시계 방향 90도
        scanf("%c", &c); // 줄바꿈 문자 무시
    }
    map[1][1] = 1;
    snake.push_back(make_pair(1, 1));
    printf("%d",simulation(1,1)); // (1,1)에서 시작
    
    return 0;
}
