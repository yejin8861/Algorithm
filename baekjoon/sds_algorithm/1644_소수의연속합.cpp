
#include<iostream>
#include<vector>
#define MAX 4000001
using namespace std;
int arr[MAX] = {0};


int main() {
	int N;
	vector<int> v;
	scanf("%d", &N);
	if (N == 1) {
		printf("0\n");
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		arr[i] = 1;
	}

	// N 이하의 소수 구하기
	for (int i = 2; i <= N; i++) {
		// 에라토스테네스의 체
		if (arr[i] == 1) {
			v.push_back(i);
			arr[i] = 0;
			for (int k = i + i; k <= N; k+=i) {
				if (k%i == 0 && arr[k]==1) { // k가 i의 배수이면
					arr[k] = 0;
				}
			}
		}
	}


	int v1 = 0, v2 = 0;
	int sum = v[0];
	int ans = 0;
	while (1) {
		if (sum > N) {
			sum -= v[v1];
			v1++;
		}
		else if (sum < N) {
			v2++;
			if (v2 >= v.size()) {
				break;
			}
			sum += v[v2];
		}
		else {
			ans++;
			v2++;
			if (v2 >= v.size()) {
				break;
			}
			sum += v[v2];
		}
	}
	printf("%d\n", ans);
	return 0;
}
