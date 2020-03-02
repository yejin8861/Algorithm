/*
톱니바퀴를 K번 회전시킬 때
서로 맞닿은 극이 같으면 자신만 회전하고
서로 맞닿은 극이 다르면 그 옆의 톱니바퀴도 반대로 회전시킴.

톱니바퀴는 인덱스를 이용하여 회전
시계방향 -> (현재 인덱스 -1)%8
반시계방향 -> (현재 인덱스 +1)%8

1. 회전하는 톱니바퀴 검색
2. 회전(재귀로 연결된 톱니바퀴 찾기)
*/
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
int gear[5][8];
int idx[5];
int pole[5]; //pole[1]:톱니바퀴 1-2 맞닿은 극이 다르면 1, pole[2]:2-3, pole[3]:3-4
int visited[5]; // 톱니바퀴 회전 여부

void search_pole() {
    memset(pole, 0, sizeof(pole));
    for (int i = 1; i < 4; i++) {
        if (gear[i][(idx[i] + 2) % 8] != gear[i + 1][(idx[i + 1] + 6) % 8]) pole[i]++;
    }
    return;
}

void rotate(int n, int d) {
    // 시계방향
    if (d == 1) idx[n] = (idx[n] + 7) % 8;
    // 반시계방향
    else idx[n] = (idx[n] + 1) % 8;
    visited[n] = 1;
    // 연결된 톱니바퀴의 극성이 다르고 회전하지 않은 상태이면 반대로 회전
    if (pole[n - 1] && !visited[n - 1]) rotate(n - 1, -d);
    if (pole[n] && !visited[n + 1]) rotate(n + 1, -d);
    return;
}

void simulation(int n, int d) {
    // 1. 맞닿은 극이 다른 톱니바퀴 찾기
    search_pole();
    // 2. 톱니바퀴 회전
    memset(visited, 0, sizeof(visited));
    rotate(n, d);
    return;
}

int main() {
    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            gear[i][j] = s[j] - '0';
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int n, d;
        cin >> n >> d;
        simulation(n, d);
    }
    // 3. 점수계산
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        if (gear[i][idx[i]]) ans += pow(2, i - 1);
    }
    cout << ans;
    return 0;
}
