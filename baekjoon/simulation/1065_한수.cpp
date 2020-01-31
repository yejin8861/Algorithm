#include<iostream>
using namespace std;

int main() {
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i < 100) cnt++;
		else if (100 <= i && i < 1000) {
			int a1 = i / 100;
			int a2 = (i - (100*a1)) / 10;
			int a3 = i - (100 * a1 + 10 * a2);
			if ((a1 - a2) == (a2 - a3)) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
