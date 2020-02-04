#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>> max_heap;


int main() {
	int N;
	int mid;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (i == 0) {
			mid = n;
		}
		else {
			if (n > mid) // n이 mid보다 같거나 크면
				min_heap.push(n);
			else
				max_heap.push(n);
		}

		// 두 heap 사이즈 비교
		int s1 = max_heap.size();
		int s2 = min_heap.size();

		if (s1 != s2) { // 크기가 1이상 차이 났을 때
			// 밸런스가 맞지 않으면
			if (s1 > s2) {
				min_heap.push(mid);
				mid = max_heap.top();
				max_heap.pop();
			}
			else if (s2 - s1 >= 2) {
				max_heap.push(mid);
				mid = min_heap.top();
				min_heap.pop();
			}
		}
		printf("%d\n", mid);
	}
	return 0;
}
