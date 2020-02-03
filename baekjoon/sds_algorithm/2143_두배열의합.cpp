#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
using namespace std;

int T, n, m;
int A[MAX], B[MAX];
long long int ans = 0;
vector<int> v1, v2;

int main() {
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	// A의 부분 합
	for (int i = 0; i < n; i++) {
		int sum = A[i];
		v1.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			v1.push_back(sum);
		}
	}
	// B의 부분 합
	for (int i = 0; i < m; i++) {
		int sum = B[i];
		v2.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			v2.push_back(sum);
		}
	}
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++) {
		int diff = T - v1[i];
		auto ub = upper_bound(v2.begin(), v2.end(), diff);
		auto lb = lower_bound(v2.begin(), v2.end(), diff);
		ans += (ub - lb);
	}
	cout << ans;
	return 0;
}
