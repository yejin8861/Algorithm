/*
각 숫자는 s+2가로와 2s+3의 세로로 이루어 진다.

    0
    -
1 l 6 l 5
    -
2 l   l 4
    -
    3
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int s;
string n;
int R, C;
char map[25][150];
vector<vector<int>> num = { {0,1,5,2,4,3},{5,4},{0,5,6,2,3},{0,5,6,4,3},
{1,5,6,4},{0,1,6,4,3},{0,1,6,2,4,3},{0,5,4},{0,1,5,6,2,4,3},{0,1,5,6,4,3} };

void zero(int x) {  
    for (int c = 0; c < C; c++) {
        if (c == 0 || c == C - 1) continue;
        map[0][x + c] = '-';
        //map[0][x + c] = 1;
    }
}
void one(int x) {
    for (int r = 0; r < R; r++) {
        if (0 < r && r < R / 2) 
            map[r][x + 0] = '|';
            //map[r][x + 0] = 1;
    }
}
void two(int x) {
    for (int r = 0; r < R; r++) {
        if (R / 2 < r && r < R - 1) 
            map[r][x + 0] = '|';
            //map[r][x + 0] = 1;
    }
}
void three(int x) {
    for (int c = 0; c < C; c++) {
        if (c == 0 || c == C - 1) continue;
        map[R-1][x + c] = '-';
        //map[R - 1][x + c] = 1;
    }
}
void four(int x) {
    for (int r = 0; r < R; r++) {
        if (R / 2 < r && r < R - 1) 
            map[r][x + C - 1] = '|';
            //map[r][x + C - 1] = 1;
    }
}
void five(int x) {
    for (int r = 0; r < R; r++) {
        if (0 < r && r < R / 2) 
            map[r][x + C - 1] = '|';
            //map[r][x + C - 1] = 1;
    }
}
void six(int x) {
    for (int c = 0; c < C; c++) {
        if (c == 0 || c == C - 1) continue;
        map[R/2][x + c] = '-';
        //map[R / 2][x + c] = 1;
    }
}

void Print() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < (C+1)*n.size(); c++) {
            if (map[r][c]) cout << map[r][c];
            else cout << ' ';
            //cout << map[r][c];
        }
        cout << '\n';
    }
}

int main() {
    cin >> s >> n;
    C = s + 2;
    R = 2 * s + 3;
    int y = 0, x = 0;
    for (int i = 0; i < n.size(); i++) {
        for (int next : num[n[i] - '0']) {
            switch (next) {
            case 0: zero(x); break;
            case 1: one(x); break;
            case 2: two(x); break;
            case 3: three(x); break;
            case 4: four(x); break;
            case 5: five(x); break;
            case 6: six(x); break;
            }
        }
        x += C + 1;
    }
    Print();
    
    return 0;
}
