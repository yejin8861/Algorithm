#include<iostream>
#include<vector>
#include<math.h>
#define MAX 1000000+1
using namespace std;

int arr[MAX];
vector<int> prime;

void eratosthenes(void) {
	for (int i = 2; i < MAX; i++)
		arr[i] = 1;

	for (int i = 2; i*i < MAX; i++) {
		if (arr[i] == 1) {
			for (int j = i * i; j < MAX; j += i) {
				if (arr[j] == 1)
					arr[j] = 0;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (arr[i] == 1)
			prime.push_back(i);
	}
}


int main() {
	int N;
	scanf("%d", &N);

	eratosthenes(); // MAX까지의 소수 구하기
	vector<int> usedPrime(prime.size(), 0); // 소수가 사용된 개수
	vector<vector<int>>factor(N, vector<int>(prime.size(), 0));

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		// 소인수분해
		int num = a;
		for (int j = 0; j < prime.size(); j++) {
			while (!(num%prime[j])) {
				usedPrime[j]++;
				factor[i][j]++;
				num /= prime[j];
				// num이 1이 되면
				if (num == 1)
					break;
			}
			if (num == 1)
				break;
		}
	}
	int gcd= 1, cnt=0;
	for (int i = 0; i < prime.size(); i++) {
		int mid = usedPrime[i] / N;
		for (int j = 0; j < N; j++) {
			if (factor[j][i] < mid) {
				cnt += mid - factor[j][i];
			}
		}
		if(mid>0)
			gcd *= pow(prime[i], mid);
	}
	printf("%d %d", gcd, cnt);
	

	return 0;
}
