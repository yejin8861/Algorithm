#include<iostream>
using namespace std;
int DP[41][2] = { { 0 } };

int main() {
	int T;
	cin >> T;
	DP[0][0] = 1;
	DP[0][1] = 0;
	DP[1][0] = 0;
	DP[1][1] = 1;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int j = 2; j < N; j++) {
			DP[j][0] = DP[j - 1][0] + DP[j - 2][0];
			DP[j][1] = DP[j - 1][1] + DP[j - 2][1];
		}
		if (N <= 1) {
			printf("%d %d\n", DP[N][0], DP[N][1]);
		}
		else {
			printf("%d %d\n", DP[N - 1][0] + DP[N - 2][0], DP[N - 1][1] + DP[N - 2][1]);
		}
		
	}
	return 0;
}
