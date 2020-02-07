// 5568_카드놓기
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int n, k, ans=0;
vector<int> original;
vector<int> new_v;
set<string> perm;

void permutation(int k) {
	do {
		if (new_v[0] == 0) continue;
		string s;
		for (int i = 0; i < k; i++) {
			s += to_string(new_v[i]);
		}
		// set에 넣어서 중복제거
		perm.insert(s);
	} while (next_permutation(new_v.begin(), new_v.end()));
	
	return;
}

void dfs(int start, int cnt) {
	if (cnt == k) {
		permutation(k);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		new_v.push_back(original[i]);
		dfs(i, cnt + 1);
		new_v.pop_back();
	}
}

int main() {
	
	cin >> n >> k;
	
	for (int i = 0; i<n; i++) {
		int a;
		scanf("%d", &a);
		original.push_back(a);
	}
	sort(original.begin(), original.end()); // 정렬을 해줘야 nextpermutation에서 모든 경우 가능
	for (int i = 0; i < n; i++) {
		new_v.push_back(original[i]);
		dfs(i, 1);
		new_v.pop_back();
	}
	printf("%d", perm.size());

	
	return 0;
}
