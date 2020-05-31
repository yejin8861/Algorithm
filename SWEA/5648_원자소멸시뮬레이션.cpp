#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#define p pair<int, pair<int, int>>
using namespace std;
int N;
struct info {
    int x, y, d, k;
    int alive;
};
struct node {
    int a, b;
};
int dir[] = { 0,2,3,1 };// 상,우,하,좌
vector<info> element;

int simulation() {
    int ans = 0;
    vector<node> time[4002];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            info a = element[i], b = element[j];
            if (a.d == b.d) continue;
            // 1. 같은 선상 & 반대 방향
            if (a.x == b.x && a.y > b.y) {
                if (a.d == 1 && b.d == 0) {
                    int dist = abs(a.x - b.x) + abs(a.y - b.y);
                    time[dist].push_back({ i,j });
                }
            }
            else if (a.y == b.y && a.x < b.x) {
                if (a.d == 3 && b.d == 2) {
                    int dist = abs(a.x - b.x) + abs(a.y - b.y);
                    time[dist].push_back({ i,j });
                }
            }
            // 2.  (dx == -dy) = 기울기 1 or -1 & 수직방향
            else if (abs(a.x - b.x) == abs(a.y - b.y)) {
                if ((a.x - b.x) / (a.y - b.y) == 1) {
                    if (a.x - b.x > 0) {
                        if ((a.d == 1 && b.d == 3) || (a.d == 2 && b.d == 0)) {
                            int dist = abs(a.x - b.x) + abs(a.y - b.y);
                            time[dist].push_back({ i,j });
                        }
                    }
                }
                else if ((a.x - b.x) / (a.y - b.y) == -1) {
                    if (a.x - b.x < 0) {
                        if ((a.d == 1 && b.d == 2) || (a.d == 3 && b.d == 0)) {
                            int dist = abs(a.x - b.x) + abs(a.y - b.y);
                            time[dist].push_back({ i,j });
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4002; i++) {
        int size = time[i].size();
        set<int> s;
        for (int j = 0; j < size; j++) {
            int a = time[i][j].a, b = time[i][j].b;
            if (element[a].alive && element[b].alive) {
                s.insert(a);
                s.insert(b);
            }
        }
        for (auto it = s.begin(); it!=s.end(); it++) {
            ans += element[*it].k;
            element[*it].alive = 0;
        }
    }
    return ans;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        element.clear();
        for (int i = 0; i < N; i++) {
            info temp;
            cin >> temp.x >> temp.y >> temp.d >> temp.k;
            temp.alive = 1;
            element.push_back(temp);
        }
        cout << '#' << test_case << ' ' << simulation() << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
