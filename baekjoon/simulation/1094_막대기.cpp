
#include<iostream>

using namespace std;

int main() {
	int X;
	int cnt = 0;
	cin >> X;
	while (X > 0) {
		if (X % 2) cnt++;
		X /= 2;
	}
	cout << cnt;
	return 0;
}
