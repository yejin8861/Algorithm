// 정수론 - 4375_1
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n)!=EOF) {
		int num = 1;
		int cnt = 1;
		while (1) {
			if (num%n == 0) {
				printf("%d\n", cnt);
				break;
			}
			num = (num * 10 + 1) % n; // 만약 n=3, 11 = 1*10+1 = 2(mod3) -> gcd(11,3) = gcd(2,3)
			cnt++;
		}
	}
	return 0;
}
