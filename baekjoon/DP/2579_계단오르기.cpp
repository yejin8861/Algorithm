#include<iostream>
#include<algorithm>

using namespace std;
int T;
int stairs[301];
int dp[301][2];

int main() {
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> stairs[i];
	}
	// dp[*][0]은 이전 계단을 밟고 온 것(즉, 다음에 2칸만 가능)
	// dp[*][1]은 이전 계단을 밟지 않은 것(즉, 다음에 1칸, 2칸 모두 가능)
	dp[1][0] = stairs[1];
	dp[1][1] = stairs[1];
	dp[2][0] = stairs[1] + stairs[2];
	dp[2][1] = stairs[2];
	dp[3][0] = stairs[2] + stairs[3];
	dp[3][1] = stairs[1] + stairs[3];

	for (int i = 4; i <= T; i++) {
		dp[i][0] = dp[i - 1][1] + stairs[i];
		dp[i][1] = max(dp[i - 2][0] + stairs[i], dp[i - 2][1] + stairs[i]);
	}
	cout << max(dp[T][0], dp[T][1]);
	return 0;
}
