#include<iostream>
#define MAX_SIZE 13

using namespace std;
int k;
int lotto[MAX_SIZE];
int combi[MAX_SIZE];

void dfs(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << combi[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i < k; i++) {
		combi[depth] = lotto[i]; //depth는 깊이 -> 0~5번째 깊이까지 재귀를 통해 새로 탐색한 숫자를 넣음.
		dfs(i + 1, depth + 1);
	}
}

int main() {
	while (cin >> k && k) { //0을 입력 받을 때 까지 무한루프
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << endl;
	}
	return 0;
}
