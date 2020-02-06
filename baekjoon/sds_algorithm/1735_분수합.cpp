#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int As, Am, Bs, Bm;
	cin >> As >> Am;
	cin >> Bs >> Bm;
	
	int Nm = Am * Bm;
	int Ns = As * Bm + Am * Bs;

	int a, b, r, G;

	if (Nm >= Ns) {
		a = Nm, b = Ns, r = a % b;
	}
	else
		a = Ns, b = Nm, r = a % b;

	while (1) {
		if (b == 1 || r == 0) {
			G = b;
			break;
		}
		a = b, b = r, r = a % b;
	}
	
	printf("%d %d", Ns / G, Nm / G);
	
	return 0;
}
