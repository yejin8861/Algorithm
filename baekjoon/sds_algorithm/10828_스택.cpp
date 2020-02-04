#include<iostream>
#include<string>
using namespace std;
int N;
int stack[10000];
int top = -1;

bool Is_empty() {
	if (top == -1)
		return true;
	else
		return false;
}

int main() {
	
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			stack[++top] = n;
		}
		else if (s == "pop") {
			if (!Is_empty()) { // 스택이 비어있지 않다면
				printf("%d\n",stack[top]);
				top--;
			}
			else
				printf("-1\n");
		}
		else if (s == "size") {
			printf("%d\n", top+1);
		}
		else if (s == "empty") {
			if (top == -1) printf("1\n");
			else printf("0\n");
		}
		else if (s == "top") {
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
		}
	}
	return 0;
}
