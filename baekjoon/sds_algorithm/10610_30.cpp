[200~#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 10^5
using namespace std;
int cnt[MAX] = { 0 };
bool compare(int a, int b) {
		return a > b;
}

int main() {
		string N;
			cin >> N;
				int s = N.size();
					int sum = 0;
						for (int i = 0; i < s; i++) {
									cnt[N[i] - '0']++;
											// 1. 3의 배수인가? (각 자리수 더해서 3의 배수)
											// 		sum += (N[i] - '0');
											// 			}
											// 				if (sum % 3) {
											// 						printf("-1");
											// 								return 0;
											// 									}
											// 										// 2. 0이 있는가?
											// 											if (cnt[0] == 0) {
											// 													printf("-1");
											// 															return 0;
											// 																}
											// 																	for (int i = MAX-1; i >= 0; i--) {
											// 																			for (int k = 0; k < cnt[i]; k++) {
											// 																						printf("%d", i);
											// 																								}
											// 																									}
											// 																										
											// 																											return 0;
											// 																											}
