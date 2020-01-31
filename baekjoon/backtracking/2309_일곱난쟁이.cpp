#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int dwarf[9];
vector<int> v;

void dfs(int start, int sum) {
	
	if (v.size() == 7) {
		if (sum == 100) {
			sort(v.begin(), v.end());
			for (int j = 0; j < 7; j++) {
				cout << v[j] << endl;
			}
			exit(0);
		}
		return;
	}
	for (int i = start; i < 9; i++) {
		v.push_back(dwarf[i]);
		dfs(i + 1, sum + dwarf[i]);
		int n = v.back();
		v.pop_back();
	}
	
}
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
	}
	dfs(0,0);
	return 0;
}
