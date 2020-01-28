#include<iostream>

using namespace std;
int cnt = 0;
int N;
int col[15];

bool isPossible(int r) {
	for (int i = 1; i < r; i++)
	{
		// 열 검사
		if (col[i] == col[r])
			return false;
		// 대각선 검사
		if (abs(col[i] - col[r]) == abs(i - r))
			return false;
	}
	return true;
}


void dfs(int r) {
	if (r == N) {
		cnt++;
		return;
	}
	else
	{
		for (int i = 1; i <= N; i++) {
			col[r + 1] = i;
			if (isPossible(r + 1))
			{
				dfs(r + 1);
			}
			col[r + 1] = 0;
		}
	}
}


int main() {
	cin >> N;
	//scanf_s("%d", &N);
	dfs(0);
	printf("%d", cnt);
	//cout << cnt;
}
