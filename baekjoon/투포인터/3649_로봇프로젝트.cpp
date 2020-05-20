#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int x, n, d;
    vector<int> v;
    while (scanf("%d %d", &x, &n)==2) {
        int ans[2] = { 0,0 };
        v.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &d);
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        int l = 0, r = n - 1;
        x *= 10000000;
        while (l < r) {
            if (v[l] + v[r] < x) l++;
            else if (v[l] + v[r] > x) r--;
            else {
                if (ans[1] - ans[0] <= v[r] - v[l]) {
                    ans[0] = v[l], ans[1] = v[r];
                    break;
                }
            }
        }
        if (ans[0] == 0 && ans[1] == 0) printf("danger");
        else printf("yes %d %d", ans[0], ans[1]);
        printf("\n");
    }
    return 0;
}
