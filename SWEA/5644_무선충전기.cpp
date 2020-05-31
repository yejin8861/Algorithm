#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, ans; // M:이동시간, N:BC개수
int dy[] = { 0,-1,0,1,0 };
int dx[] = { 0,0,1,0,-1 };
struct node {
    int y, x, c, p; // (좌표, 범위, 충전량)
};
vector<int> A, B;
vector<node> battery;

void simulation() {
    int ay = 1, ax = 1, by = 10, bx = 10;
    for (int t = 0; t <= M; t++) {
        vector<int> A_BC, B_BC;
        // A, B가 충전할 수 있는 곳
        for (int j = 0; j < battery.size(); j++) {
            if (abs(ay - battery[j].y) + abs(ax - battery[j].x) <= battery[j].c) {
                A_BC.push_back(j);
            }
            if (abs(by - battery[j].y) + abs(bx - battery[j].x) <= battery[j].c) {
                B_BC.push_back(j);
            }
        }

        // 최대합 구하기
        // 1. A만 충전하는 경우
        if (B_BC.empty()) {
            int MAX = 0;
            for (int n : A_BC) {
                if (MAX < battery[n].p) MAX = battery[n].p;
            }
            ans += MAX;
        }
        // 2. B만 충전하는 경우
        else if (A_BC.empty()) {
            int MAX = 0;
            for (int n : B_BC) {
                if (MAX < battery[n].p) MAX = battery[n].p;
            }
            ans += MAX;
        }
        // 3. 둘 다 충전하는 경우
        else {
            int MAX = 0;
            for (int n1 : A_BC) {
                for (int n2 : B_BC) {
                    if (n1 == n2) {
                        if (MAX < battery[n1].p) MAX = battery[n1].p;
                    }
                    else {
                        if (MAX < battery[n1].p + battery[n2].p) MAX = battery[n1].p + battery[n2].p;
                    }
                }
            }
            ans += MAX;
        }
        ay += dy[A[t]], ax += dx[A[t]], by += dy[B[t]], bx += dx[B[t]];
    }
    return;
}

void input() {
    int n;
    cin >> M >> N;
    A.clear(); B.clear(); battery.clear();
    for (int i = 0; i < M; i++) {
        cin >> n;
        A.push_back(n);
    }
    A.push_back(0);
    for (int i = 0; i < M; i++) {
        cin >> n;
        B.push_back(n);
    }
    B.push_back(0);
    for (int i = 0; i < N; i++) {
        node temp;
        cin >> temp.x >> temp.y >> temp.c >> temp.p;
        battery.push_back(temp);
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        input();
        simulation();
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
