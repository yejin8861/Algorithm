// 1010_다리놓기
 //순서가 정해져있기 때문에
 //m개 중 n개만 뽑으면 됨 . = mCn

#include<iostream>
using namespace std;
int N, M;

int  combi(int n, int r) {
	if (r == 1)
		return n;
	else if (n == r)
		return 1;
	return combi(n - 1, r - 1) + combi(n - 1, r);
}

int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> N >> M;
		printf("%d\n", combi(M, N));
	}
	return 0;
}
