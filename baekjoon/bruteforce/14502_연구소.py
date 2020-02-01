#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 8
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M;
int lab[MAX][MAX];
int temp[MAX][MAX];
int result=0;

void bfs() {
	int afterSpread[MAX][MAX];
	copy(&temp[0][0], &temp[0][0] + MAX * MAX, &afterSpread[0][0]);

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (afterSpread[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (afterSpread[ny][nx] == 0) {
					afterSpread[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}

		}
	}

	int empty = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (afterSpread[i][j] == 0) empty++;
		}
	}
	result = max(result, empty);
}

void make_wall(int r, int c, int n) {
	if (n == 3) {
		bfs();
		return;
	}
	while (r < N) {
		c++;
		if (c == M) {
			c = 0;
			r++;
			if (r == N)
				return;
		}
		if (temp[r][c] == 0) {
			temp[r][c] = 1;
			make_wall(r,c,n + 1);
			temp[r][c] = 0;
		}
	}
}

 int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
		}
	}
	copy(&lab[0][0], &lab[0][0] + MAX * MAX, &temp[0][0]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				make_wall(i,j,1);
				temp[i][j] = 0;
			}
		}
	}

	cout << result;
	return 0;
}
