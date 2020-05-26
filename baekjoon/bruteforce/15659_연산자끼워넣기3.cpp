#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1000000005
using namespace std;
int N, MAX = -INF, MIN = INF;

void calculate(deque<int> num, deque<int> oper) {
    for (int i = 0; i < 2; i++) {
        deque<int> new_num;
        deque<int> new_oper;
        new_num.push_back(num.front()); num.pop_front();

        while (!oper.empty()) {
            int op = oper.front(); oper.pop_front();
            int n = num.front(); num.pop_front();
            if (i==0) {
                if (op == 2) { // 곱셈
                    int prev = new_num.back(); new_num.pop_back();
                    new_num.push_back(prev * n);
                }
                else if (op == 3) { // 나눗셈
                    int prev = new_num.back(); new_num.pop_back();
                    new_num.push_back(prev / n);
                }
                else {
                    new_num.push_back(n);
                    new_oper.push_back(op);
                }
            }
            else {
                int prev = new_num.back(); new_num.pop_back();
                if (op == 0) new_num.push_back(prev + n); // 덧셈
                else if(op == 1)new_num.push_back(prev - n); // 뺄셈
            }
        }
        if (i == 0) {
            num = new_num;
            oper = new_oper;
        }
        else {
            // 최대, 최소 구하기
            MAX = max(MAX, new_num.front());
            MIN = min(MIN, new_num.front());
        }
    }
}

int main() {
    deque<int> num;
    deque<int> oper; // +:0, -:1, *:2, /:3
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        num.push_back(n);
    }
    int cnt[4] = {};
    for (int i = 0; i < 4; i++) scanf("%d", &cnt[i]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            oper.push_back(i);
        }
    }

    do {
        calculate(num, oper);

    } while (next_permutation(oper.begin(), oper.end()));

    printf("%d\n%d", MAX, MIN);
    return 0;
}
