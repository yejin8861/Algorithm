#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N;
int flag = 0;
string number;

bool isPossible() {
	string temp = number;
	reverse(temp.begin(), temp.end());
	int cnt = number.size() / 2;
	
	for (int i = 1; i <= cnt; i++) {
		string first = temp.substr(0, i);
		string second = temp.substr(i, i);
		if (temp.substr(0, i) == temp.substr(i, i)) { // 나쁜 순열
			return false;
		}
	}
	return true;
}

void dfs(int depth) {
	
	// 나쁜 수열이면 return
	if (!isPossible())
		return;
	if (depth == N) {
		cout << number;
		exit(0);
	}
	for (int i = 1; i < 4; i++) {
		number += char(i + '0');
		dfs(depth+1);
		number.resize(number.size() - 1);
	}
}


int main() {
	cin >> N;
	dfs(0);

	return 0;
}
