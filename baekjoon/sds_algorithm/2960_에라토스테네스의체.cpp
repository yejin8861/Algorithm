#include<iostream>
using namespace std;
int arr[1001] = { 0 };
int main() {
	int N, K;
	int ans = 0;
	scanf("%d %d", &N, &K);
	for (int i = 2; i <= N; i++) {
		arr[i] = 1;
	}

	for (int p = 2; p <= N; p++) {
		
		if (arr[p] == 1) { // 지우지 않은 수 중 가장 작은 수
			K--;
			if (K == 0) {
				printf("%d", p);
				return 0;
			}
			
			arr[p] = 0;
			for (int k = p + 1; k <= N; k++) {
				if (k%p == 0 && arr[k]==1) {// k가 p의 배수이고 아직 숫자가 남아있으면
					arr[k] = 0;
					K--;
					if (K == 0) {
						printf("%d", k);
						return 0;
					}
				}
			}
		}
		
	}
}
