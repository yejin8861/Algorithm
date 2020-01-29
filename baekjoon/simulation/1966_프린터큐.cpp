#include<iostream>
#include<list>

using namespace std;

int main() {
	int T;
	cin >> T;
	int N, M;
	int cnt;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		list<pair<int, int>> q;
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			q.push_back(make_pair(j, n));
		}
		cnt = 1;
		while(!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop_front();

			list<pair<int, int>>::iterator it;
			for (it = q.begin(); it != q.end();it++) {
				if (it->second > val) {// 리스트에 우선순위 높은게 있다면
					q.push_back(make_pair(idx, val)); // 뒤에 재배치
					break;
				}
			}
			if (it == q.end()) { // 우선순위가 제일 높고
				if (idx == M) { // 찾고자 하는 문서였다면
					printf("%d\n", cnt);
					break;
				}
				else
					cnt++;
			}
		}
	}
	return 0;
}
