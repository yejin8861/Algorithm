/*
O(n^2*logn) - 이분탐색
[문제]
정수로 이루어진 크기가 같은 배열 A,B,C,D가 있다.
A[a], B[b], C[c], D[d]의 합이 0인 (a,b,c,d) 쌍의 개수를 구하라.

[출력]
합이 0이 되는 쌍의 개수를 출력한다.

*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A, B, C, D;
vector<int> AB, CD;
int n;
long long ans;

void find_zero(int num) {
    // D에서 -num 찾기
    int lb = lower_bound(CD.begin(), CD.end(), -num) - CD.begin();
    int ub = upper_bound(CD.begin(), CD.end(), -num) - CD.begin();
    ans += (long long)ub - lb;
}

int main() {
    scanf("%d", &n);
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    for (int i = 0; i < n*n; i++) {
        find_zero(AB[i]);
    }
    printf("%lld", ans);
    return 0;
}

