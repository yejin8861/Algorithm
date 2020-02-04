
#include<iostream>
#include<string>
#define SIZE 10000
using namespace std;
int N;
int queue[SIZE];
int front = 0, rear = 0;

bool Is_empty() {
	if (front==rear) return true;
	else return false;
}

int main() {

	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			queue[rear] = n;
			rear = (rear + 1) % SIZE;
		}
		else if (s == "pop") {
			if (!Is_empty()) {
				printf("%d\n", queue[front]);
				front = (front + 1) % SIZE;
			}
			else printf("-1\n");
		}
		else if (s == "size") {
			printf("%d\n", abs(rear-front));
		}
		else if (s == "empty") {
			if (Is_empty()) printf("1\n");
			else printf("0\n");
		}
		else if (s == "front"){
			if (!Is_empty()) {
				printf("%d\n", queue[front]);
			}
			else printf("-1\n");
		}
		else if (s == "back"){
			if(!Is_empty()) printf("%d\n", queue[(rear-1)%SIZE]);
			else printf("-1\n");
		}
	}
	return 0;
}
