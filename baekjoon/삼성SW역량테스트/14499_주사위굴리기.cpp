/*
주사위를 굴렸을 때
1. 이동한 칸에 숫자가 0이면, 주사위의 바닥면 숫자가 칸에 복사
2. 0이 아니면 칸에 쓰여있는 수가 주사위 바닥면으로 복사, 칸의 수는 0
주사위가 이동할 때 마다 상단에 쓰여있는 값 출력
! (x,y) 좌표 주의
*/
#include<cstdio>
#include<deque>
using namespace std;
int N, M, x, y, K;
int map[22][22];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
deque<int> col(4); // col[1]이 윗면, col[3]이 아랫면
deque<int> row(3);

void dice_rotate(int d) {
    if (d == 1) { // 동쪽
        // col.back -> row.front, row.back -> col.back, col[1] = row[1]
        int temp = col.back(); col.pop_back();
        row.push_front(temp);
        temp = row.back(); row.pop_back();
        col.push_back(temp);
        col[1] = row[1];
    }
    else if (d == 2) { // 서쪽
        // col.back -> row.back, row.front->col.back, col[1]=row[1]
        int temp = col.back(); col.pop_back();
        row.push_back(temp);
        temp = row.front(); row.pop_front();
        col.push_back(temp);
        col[1] = row[1];
    }
    else if (d == 3) { // 북쪽
        // col.front -> col.back, row[1]=col[1]
        int temp = col.front(); col.pop_front();
        col.push_back(temp);
        row[1] = col[1];
    }
    else { // 남쪽
        // col.back->col.front, row[1]=col[1]
        int temp = col.back(); col.pop_back();
        col.push_front(temp);
        row[1] = col[1];
    }
    // 윗면 출력
    printf("%d\n", col[1]);
    return;
}

int main() {
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        // 1:동쪽, 2:서쪽, 3:북쪽, 4:남쪽
        int d;
        scanf("%d", &d);

        // 1. 범위를 벗어나면 무시
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;

        // 2. 주사위 회전
        dice_rotate(d); 

        // 3. 칸의 수가 0이면 주사위 바닥면을 칸에 복사
        if (map[nx][ny] == 0) map[nx][ny] = col[3];
        else { // 4. 0이 아니면 칸의 수를 주사위 바닥면에 복사, 칸은 0
            col[3] = map[nx][ny];
            map[nx][ny] = 0;
        }
        y = ny, x = nx;
    }
    
    return 0;
}
