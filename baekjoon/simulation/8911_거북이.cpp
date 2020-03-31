/*
[문제]
F: 한 눈금 앞으로
B: 한 눈금 뒤로
L: 왼쪽으로 90도 회전
R: 오른쪽으로 90도 회전

거북이는 처음에 (0,0)에 있고, 북쪽을 쳐다보고 있다.

[출력]
거북이가 이동한 영역을 포함하는 가장 작은 직사각형의 넓이를 출력한다.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int y, x, d;
int minY, minX, maxY, maxX;
int dy[] = { -1,0,1,0 }; // 북,동,남,서
int dx[] = { 0,1,0,-1 };

void forward() {
    y += dy[d];
    x += dx[d];
    return;
}
void back() {
    y += dy[(d + 2) % 4];
    x += dx[(d + 2) % 4];
    return;
}
void left() {
    d = (d + 3) % 4;
    return;
}
void right() {
    d = (d + 1) % 4;
    return;
}

void simulation() {
    for (int c : s) {
        switch (c) {
        case 'F': forward(); break;
        case 'B': back(); break;
        case 'L': left(); break;
        case 'R': right(); break;
        }
        minY = min(minY, y);
        minX = min(minX, x);
        maxY = max(maxY, y);
        maxX = max(maxX, x);
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        simulation();
        // 직사각형 넓이 출력
        cout << (maxY - minY)*(maxX - minX) << '\n';
        maxY = minY = maxX = minX = 0;
        x = y = d = 0;
    }
    return 0;
}
