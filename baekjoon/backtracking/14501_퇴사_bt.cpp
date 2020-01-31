#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int T[16], P[16];
int ans = 0;

void dfs(int start, int pay) {
	if (start >= N-1) {
		if (start == N - 1 && T[start]!=1) ans = max(ans, pay - P[start]);
		else ans = max(ans, pay);
		return;
	}

	for (int i = start; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (i + T[i] <= j) 
				dfs(j, pay + P[j]);
		}
		pay = P[i+1];
	}
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	dfs(0,P[0]);
	cout << ans;
	return 0;
}
