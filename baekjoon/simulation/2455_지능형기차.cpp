#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int people[4][2];
	vector<int> train;
	for (int i = 0; i < 4; i++) {
		cin >> people[i][0] >> people[i][1];
	}
	train.push_back(people[0][1]);
	for (int i = 1; i < 4; i++) {
		int n;
		n = train[i-1] - people[i][0] + people[i][1];
		train.push_back(min(n, 10000));
	}
	cout << *max_element(train.begin(), train.end());
	return 0;
}
