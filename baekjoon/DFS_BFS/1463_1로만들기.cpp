#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int ans=99999;
list<int> q;
int cnt;

int bfs() {
	int n,s;
	while (!q.empty()) {
		s = q.size();
		for (int i = 0; i < s; i++) {
			n = q.front();
			q.pop_front();
			if (n == 1) {
				return cnt;
			}
			if (n % 3 == 0)
				q.push_back(n / 3);
			if (n % 2 == 0)
				q.push_back(n / 2);
			q.push_back(n - 1);
		}
		cnt++;
	}
	
}

int main() {
	int N;
	cin >> N;
	q.push_back(N);
	cout << bfs();
	
	return 0;
}
