#include<iostream>
#include<vector>
#include<string>
#define MAX 1000005

using namespace std;
int arr[MAX] = { 0 };
vector<int> v;
string P;
int K;

bool is_divide(long long int n) {
	int ret = 0;
	for (int i = 0; P[i]; i++ ) {
		int x = ret + (P[i]-'0');
		if (x % n) {
			ret = (x%n) * 10;
		}
		else
			ret = 0;
	}
	if (ret == 0)
		return true;
	else
		return false;
}

int main() {
	
	cin >> P >> K;
	for (int i = 2; i < K; i++)
		arr[i] = 1;
	
	// K보다 작은 소수 구하기
	for (int i = 2; i < K; i++) {
		if (arr[i] == 1) {
			v.push_back(i);
			arr[i] = 0;
			for (int k = i * i; k < K; k += i) {
				if (k%i == 0 && arr[k] == 1) {
					arr[k] = 0;
				}
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= K) break;
		// 소수가 K보다 작을 때
		if (is_divide(v[i])) {
			printf("BAD %d", v[i]);
			return 0;
		}
	}
	printf("GOOD");
	return 0;
}
