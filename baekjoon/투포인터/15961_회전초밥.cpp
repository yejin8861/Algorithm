/*
[문제]
벨트 위에 초밥이 놓여있을 때,
k개의 접시를 연속해서 먹을 경우 무료 초밥 쿠폰을 준다.

[출력]
주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값을 출력한다.

[풀이]
슬라이딩 윈도우
*/
#include<cstdio>
#include<algorithm>
#define MAX 3000005
using namespace std;
int N, d, k, c;
int sushi[MAX];
int kind[3001];
int ans;

int main() {
    scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i = 0; i < N; i++) scanf("%d", &sushi[i]);

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (!kind[sushi[i]]) cnt++;
        kind[sushi[i]]++;
    }
    ans = max(ans, cnt);

    for (int i = 0; i < N-1; i++) {
        int first = sushi[i], next = sushi[(i + k)%N];
        // 1. 맨 앞 스시를 빼면 종류가 작아지는 경우
        if (!(--kind[first])) cnt--;

        // 2. 다음 스시를 추가하면 종류가 늘어나는 경우
        if (!(kind[next])++) {
            cnt++;
        }

        // 3. 쿠폰 스시가 포함된 경우 or 포함되지 않은 경우
        if (!kind[c]) ans = max(ans, cnt + 1);
        else ans = max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}
