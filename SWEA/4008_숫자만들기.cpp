#include<cstdio>
#include<algorithm>
#include<vector>
#define INF 100000001
using namespace std;
int T, N;
int cnt[4];
int MAX, MIN;
vector<int> num;
vector<int> oper; // '+':0, '-':1, '*':2, '/':3

void simulation() {
    int ans = 0;
    MAX = -INF, MIN = INF;
    do {
        for (int i = 0; i < N; i++) {
            if (i == 0) ans = num[i];
            else {
                switch (oper[i-1]) {
                case 0: ans += num[i]; break;
                case 1: ans -= num[i]; break;
                case 2: ans *= num[i]; break;
                case 3: ans /= num[i]; break;
                }
            }
        }
        MAX = max(MAX, ans);
        MIN = min(MIN, ans);
    } while (next_permutation(oper.begin(), oper.end()));
}

int main(int argc, char** argv) {
    scanf("%d", &T);
    int n;
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);
        // 연산자
        oper.clear();
        for (int i = 0; i < 4; i++) scanf("%d", &cnt[i]);
        for (int i = 0; i < 4; i++) {
            switch (i) {
            case 0: for (int k = 0; k < cnt[i]; k++) oper.push_back(0); break;
            case 1: for (int k = 0; k < cnt[i]; k++) oper.push_back(1); break;
            case 2: for (int k = 0; k < cnt[i]; k++) oper.push_back(2); break;
            case 3: for (int k = 0; k < cnt[i]; k++) oper.push_back(3); break;
            }
        }
        num.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &n);
            num.push_back(n);
        }
        simulation();
        printf("#%d %d\n", test_case, MAX - MIN);
    }
    
    return 0;
}
