#include<iostream>
#include<malloc.h>
#define MAX 1000001

using namespace std;
int N, M, K;
long long int *tree;


long long int update(int index, long long int value, int node, long long int nodeL, long long int nodeR) {
	
	if (index < nodeL || index > nodeR) return tree[node]; // 범위를 벗어나면
	else if (nodeL == nodeR) { // 말단 노드이면 바꾸고자 하는 숫자로 변경
		tree[node] = value;
		return tree[node];
	}
	// 이분 탐색으로 범위를 절반씩 나눈다. 현재 node의 값은 nodeL~nodeR까지의 합
	long long int mid = (nodeL + nodeR) / 2;
	// 자식노드 left는 [nodeL, mid], right는 [mid+1,nodeR]
	tree[node] = update(index, value, node * 2, nodeL, mid) + update(index, value, node * 2 + 1, mid + 1, nodeR);
	return tree[node];

}

long long int sum(int L, int R, int node, int nodeL, int nodeR) {
	// 범위를 벗어나면 return 0
	if (L > nodeR || R < nodeL) return 0;
	// 범위가 포함되면 해당 노드 값return
	else if (L <= nodeL && R >= nodeR) return tree[node];
	// 포함되지는 않지만 겹치는 부분이 있다면 이분탐색으로 아래 노드로 내려가기
	long long int mid = (nodeL + nodeR) / 2;
	return  sum(L, R, node * 2, nodeL, mid) + sum(L, R, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	// 배열(arr)와 트리에 사용될 배열(tree)를 선언
	
	cin >> N >> M >> K;
	tree = (long long  int *)malloc(sizeof(long long int)*(4 * (N + 1)));


	// 배열 값 초기화
	for (int i = 1; i <= N; i++) {
		long long int n;
		scanf("%lld", &n);
		update(i, n, 1, 1, N);
	}
	// 수 변경 or 구간합
	for (int i = 1; i <= M+K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // 수 변경
			update(b, c, 1, 1, N); // 맨 처음 노드는 1~N까지의 합(L=1, R=1)
		}
		else if (a == 2) {
			printf("%lld\n", sum(b, c, 1, 1, N));
		}
	}

	
	return 0;
}
