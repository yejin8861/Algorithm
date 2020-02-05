#include<iostream>
#include<queue>
using namespace std;
int main() {
	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf_s("%d", &x);
		if (x > 0) {
			pq.push(x);
		}
		else {
			if (!pq.empty()) { // pq가 비어있지 않으면
				printf("%d\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
	}
	return 0;
}
