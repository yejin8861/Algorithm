/*
[문제]
산선 용액의 특성값은 1 ~ 1,000,000,000까지 양의 정수로 나타내고,
알칼리성 용액의 특성값은 -1 ~ -1,000,000,000까지의 음의 정수로 나타낸다.

주어진 용액 중 세가지를 혼합하여 특성값이 0에 가장 가까운 용액을 만들려 한다.

[출력]
특성값이 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값을 출력한다.
세 용액은 특성값의 오름차순으로 출력한다.
여러 경우가 있다면 그 중 아무것이나 하나 출력한다.

[풀이]
하나의 수를 고정하고 두 개의 수를 움직이며 합이 0과 가까운 수를 찾는다.
*/
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int N;
long long ans[3];
vector<long long> v;
int main() {
    scanf("%d", &N);
    long long n;
    for (int i = 0; i < N; i++) {
        scanf("%lld",&n);
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    int l, r;
    long long sum = 3000000000;
    for (int i = 0; i < N-2; i++) {
        l = i + 1;
        r = N - 1;
        while (l < r) {
            long long temp = v[i] + v[l] + v[r];
            // 절댓값이 작으면 update
            if (abs(temp) < abs(sum)) {
                ans[0] = v[i];
                ans[1] = v[l];
                ans[2] = v[r];
                sum = temp;
            }
            if (temp < 0) l++;
            else if (temp > 0) r--;
            else {
                for (int k = 0; k < 3; k++) {
                    printf("%lld ", ans[k]);
                }
                return 0;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        printf("%lld ", ans[k]);
    }
    return 0;
}
