#include<iostream>
#define MAX 10001
using namespace std;
int N, M;
int A[MAX];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int sum = 0, ans = 0;
	int s = 0, e = 0;
	while (e <= N) {
		if (sum < M) {
			sum += A[e];
			e++;
		}
		else if (sum > M) {
			sum -= A[s];
			s++;
		}
		else {
			ans++;
			sum -= A[s];
			s++;
		}
	}
	cout << ans;
	return 0;
}
