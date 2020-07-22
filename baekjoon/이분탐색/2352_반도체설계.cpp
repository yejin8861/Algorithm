/*
이분탐색을 통한 LIS 알고리즘 O(nlogn)
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 40001
using namespace std;

int main() {
    int n, num;
    scanf("%d", &n);
    vector<int> dp;
    dp.push_back(0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (dp.back() < num) dp.push_back(num);
        else {
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), num);
            *it = num;
        }
    }
    printf("%d", dp.size() - 1);
    return 0;
}
