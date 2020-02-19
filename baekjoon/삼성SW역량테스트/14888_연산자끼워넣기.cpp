#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1000000005
using namespace std;
int N;
int A[102];
int oper[4];
int MAX = -INF, MIN = INF;

void dfs(int idx, int sum, int op) {
    if (op == 0) sum += A[idx]; // + 덧셈
    else if (op == 1) sum -= A[idx]; // - 뺄셈
    else if (op == 2) sum *= A[idx]; // * 곱셈
    else if (op == 3) sum /= A[idx]; // / 나눗셈

    if (idx == N - 1) {
        MAX = max(MAX, sum);
        MIN = min(MIN, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i]) { // 연산자가 있으면
            oper[i]--;
            dfs(idx+1, sum, i);
            oper[i]++;
        }
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", &A[i]);

    for (int i = 0; i < 4; i++) 
        scanf("%d", &oper[i]);

    for (int i = 0; i < 4; i++) {
        if (oper[i]) { // 연산자가 있으면
            oper[i]--;
            dfs(1, A[0], i);
            oper[i]++;
        }
    }
    printf("%d\n", MAX);
    printf("%d", MIN);
    return 0;
}
