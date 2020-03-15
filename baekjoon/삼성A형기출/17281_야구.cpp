/*
9명으로 이루어진 두 팀이 공격, 수비를 번갈아 하는 게임.
총 N이닝 (한 이닝은 공격과 수비로 이루어짐.)
한 이닝 종료 : 3아웃 발생 -> 공격 수비 체인지.

경기 전 타순 정함.
9번 타자까지 공을 쳤는데 3아웃이 발생하지 않으면 다시 1번부터.
1번 선수를 4번 타자로 미리 결정.

타자 : 안타, 2루타, 3루타, 홈런, 아웃 중 하나
[진행]
- 안타 : 타자와 모든 주자가 1씩 진루
- 2루타 : 타자와 모든 주자가 2씩 진루
- 3루타 : 타자와 모든 주자가 3씩 진루
- 홈런 : 타자와 모든 주자가 홈까지 진루
- 아웃 : 모든 주자는 진루X, 아웃 하나 증가


# 출력
가장 많은 득점을 하는 타순을 찾고, 그 때의 득점 구하기.
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N;
int score[52][9];
vector<int> v = { 0,1,2,3,4,5,6,7,8 };
deque<int> base;
int ans;

void simulation() {
    // 1. 타순 정하기
    do {
        // 4번 타자가 1번 선수가 아니면 pass.
        if (v[3] != 0) continue;
        int result = 0;
        int inning = 1;
        int index = 0;
        int out = 0;
        while (inning <= N) {
            // 3아웃이면 종료 -> 다음 이닝
            if (out == 3) {
                inning++;
                out = 0;
                base.clear();
            }
            int n = score[inning][v[index]];
            // 안타, 2루타, 3루타인 경우
            if (1 <= n && n <= 3) {
                base.push_back(1);
                for (int i = 0; i < n - 1; i++) {
                    base.push_back(0);
                }
                int cnt = base.size() - 3;
                while (cnt>0) {
                    int p = base.front(); base.pop_front();
                    if (p) result++;
                    cnt--;
                }
            }
            else if (n == 4) { // 홈런인 경우
                for (int n : base) { // 루에 있는 주자 수만큼 증가
                    if (n) result++;
                }
                result++;
                base.clear();
            }
            else { // 아웃인 경우
                out++;
            }
            index = (index + 1) % 9;
        }
        ans = max(ans, result);

    }while(next_permutation(v.begin(), v.end()));

    printf("%d", ans);
    return;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &score[i][j]);
        }
    }
    simulation();
    return 0;
}
