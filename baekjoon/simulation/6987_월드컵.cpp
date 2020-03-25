/*
[문제]
6개국으로 구성된 각 조에서 서로 한 번씩, 각 국가별로 총 5번의 경기를 치른다.
각 나라의 승, 무승부, 패의 수가 가능한 결과인지 판별한다.

[출력]
네 가지의 결과가 주어질 때 각 결과에 대해 가능하면 1, 불가능하면 0 출력.
*/
#include<cstdio>
#include<vector>
#include<cstring>
#define WIN 0
#define DRAW 1
#define LOSE 2
using namespace std;
int num[6][3]; // input
int result[6][3]; // result[A][1]=A가 이긴 수, result[A][2]=A가 비긴 수, result[A][3]=A가 진 수
int ans[4];

void dfs(int t, int t1, int t2, int cnt) {
    
    if (cnt == 15) {
        // count가 맞는지 확인
        if (ans[t]) return;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (result[i][j] != num[i][j]) return;
            }
        }
        // 경기 결과가 일치하면 결과테이블에 저장.
        ans[t] = 1;
        return;
    }

    if (t2 == 6) {
        t1++;
        t2 = t1 + 1;
    }

    // 1. t1이 이긴 경우
    result[t1][WIN]++;
    result[t2][LOSE]++;
    dfs(t, t1,t2+1,cnt + 1);
    result[t1][WIN]--;
    result[t2][LOSE]--;
        
    // 2. 비긴 경우
    result[t1][DRAW]++;
    result[t2][DRAW]++;
    dfs(t, t1,t2+1,cnt + 1);
    result[t1][DRAW]--;
    result[t2][DRAW]--;

    // 3. t1이 진 경우
    result[t1][LOSE]++;
    result[t2][WIN]++;
    dfs(t, t1,t2+1,cnt + 1);
    result[t1][LOSE]--;
    result[t2][WIN]--;
    
}


int main() {
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &num[i][j]);
            }
        }

        dfs(t, 0, 1, 0);
        
    }
    for (int n : ans) printf("%d ",n);
    return 0;
}
