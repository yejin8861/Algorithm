/*
[문제]
목재절단기는 다음과 같이 동작한다.
1. 절단기에 높이 H를 지정한다.
2. 톱날이 땅으로부터 H미터 위로 올라간다.
3. 한 줄에 연속해있는 나무를 모두 절단한다. 
-> 높이가 H보다 큰 나무는 H 위의 부분이 잘리고, 낮은 나무는 잘리지 않는다.
4. 잘린 나무를 들고 집에 간다.

[출력]
적어도 M미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int ans;
vector<int> tree;

long long cutting_tree(int h) {
    long long sum = 0;
    // h보다 큰 높이의 나무 찾기
    int start = upper_bound(tree.begin(), tree.end(), h) - tree.begin();
    for (int i = start; i < tree.size(); i++) {
        sum += tree[i] - h;
    }
    return sum;
}

int binary_search() {
    int start = 0;
    int end = tree.back();
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        long long amount = cutting_tree(mid);
        // 나무의 양이 M인 경우
        if (amount == M) return mid;

        // 나무의 양이 M보다 작으면 높이 낮추기
        if (amount < M) end = mid - 1;
        else { // 나무의 양이 M보다 많으면 최대값 갱신하고 높이 올리기
            ans = max(ans, mid);
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        tree.push_back(n);
    }
    sort(tree.begin(), tree.end());
    printf("%d", binary_search());
    return 0;
}
