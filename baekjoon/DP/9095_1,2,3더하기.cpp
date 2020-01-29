#include<iostream>
using namespace std;
int DP[11] = { 0, };


int main() {
	int T;
	cin >> T;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	for (int j = 0; j < T; j++) {
		int N;
		cin >> N;
		int i = 3;
		while (i <= N) {
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
			i++;
		}
		cout << DP[N] << endl;
	}
	
	
	return 0;
}
