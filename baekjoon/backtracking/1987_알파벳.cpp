#include<iostream>
#include<algorithm>
using namespace std;
int R, C;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ans = 0;
char board[20][20] = { 0 };
int alphabet[26] = { 0 }; // A~Z

void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		int k = int(board[ny][nx] - 'A');
		if (alphabet[k]) // 이미 방문한 알파벳이라면
			continue;

		alphabet[k] = 1;
		dfs(ny, nx, cnt+1);
		alphabet[k] = 0;

	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	alphabet[int(board[0][0] - 'A')] = 1;
	dfs(0, 0, 1);
	cout << ans;
	return 0;
}
