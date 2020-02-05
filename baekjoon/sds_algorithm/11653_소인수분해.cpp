#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	vector<int> v;
	scanf("%d", &N);
	int i = 2;
	while(N!=1 && i<=N){
		if (N%i == 0) {
			N = N / i;
			v.push_back(i);
		}
		else {
			i++;
		}
	}
	if (v.size() == 0) {
		//printf("0\n");
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}
