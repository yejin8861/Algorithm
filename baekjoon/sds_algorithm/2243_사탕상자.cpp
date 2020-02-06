#include<iostream>
#include<algorithm>
#define MAX 1000000

using namespace std;
long long int tree[4*MAX];
int n;

void update(int index, long long int value, int node, int nodeL, int nodeR) {

	if (index < nodeL || index > nodeR) return; // 범위를 벗어나면
	tree[node] += value;
	if (nodeL != nodeR) {
		// 이분 탐색으로 범위를 절반씩 나눈다. 현재 node의 값은 nodeL~nodeR까지의 합
		int mid = (nodeL + nodeR) / 2;
		// 자식노드 left는 [nodeL, mid], right는 [mid+1,nodeR]
		update(index, value, node * 2, nodeL, mid);
		update(index, value, node * 2 + 1, mid + 1, nodeR);
	}
	return;
}

int pop_candy(int value, int node, int nodeL, int nodeR) {
	if (nodeL == nodeR) return nodeL;
	int mid = (nodeL + nodeR) / 2;
	if (tree[node * 2] >= value) {
		return pop_candy(value, node * 2, nodeL, mid);
	}
	else {
		return pop_candy(value - tree[node * 2], node * 2 + 1, mid + 1, nodeR);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int A, B;
		long long int C;
		scanf("%d", &A);
		if (A == 1) {
			scanf("%d", &B); // B:꺼낼 사탕 순위
			int ans = pop_candy(B, 1, 1, MAX);
			printf("%d\n", ans);
			update(ans, -1, 1, 1, MAX);
		}
		else {
			scanf("%d %lld", &B, &C); // B:넣을 사탕의 맛, C:사탕의 개수
			update(B, C, 1, 1, MAX);
		}
	}
	return 0;
}
