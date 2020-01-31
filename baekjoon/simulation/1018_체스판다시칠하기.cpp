#include<iostream>
using namespace std;
char board[51][51];
int ans = 99999;

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	char color;
	int cnt = 0;
	for(int i = 0;i <= N - 8 ; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for (int k = 0; k < 2; k++) { // 맨 처음 컬러 그대로 1번, 바꿔서 1번
				if (k == 0) color = board[i][j];
				else {
					if (color == 'W') color = 'B';
					else color = 'W';
				}
				for (int r = i; r < i + 8; r++) {
					for (int c = j; c < j + 8; c++){
						if ((r + c) % 2 == 0) {  // (r+c)가 짝수이면 맨 처음 컬러와 같아야 함
							if (board[r][c] != color) cnt++;
						}
						else {// (r+c)가 홀수이면 맨 처음 컬러와 달라야 함
							if (board[r][c] == color) cnt++;
						}
					}
					if (cnt > ans) break;
				}
				if (ans > cnt)
					ans = cnt;
				cnt = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
