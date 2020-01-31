#include<iostream>
#include<algorithm>

using namespace std;

int place[50][50];
int cleaner[3]; // r,c,d
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 북,동,남,서
int ans = 0;
int cnt = 0;

int main() {
	int N, M;
	cin >> N >> M;
	cin >> cleaner[0] >> cleaner[1] >> cleaner[2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> place[i][j];
		}
	}

	while (1) {
		// 3. 네 방향 모두 청소 되었거나 벽인 경우
		if (cnt == 4) {
			int new_d = (cleaner[2] + 2) % 4; // 후진 방향
			int new_r = cleaner[0] + dir[new_d][0];
			int new_c = cleaner[1] + dir[new_d][1];
			// d. 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우
			if (place[new_r][new_c] == 1)
				break;
			// c. 바라보는 방향 유지한 채로 한 칸 후진
			cleaner[0] = new_r;
			cleaner[1] = new_c;
			cnt = 0;
		}

		// 1. 현재 위치 청소
		if (place[cleaner[0]][cleaner[1]] == 0) { // 청소가 되어있지 않으면
			ans++;
			cnt = 0;
			place[cleaner[0]][cleaner[1]] = 2; // 청소=2 (1)
		}

		// 2. 왼쪽 방향 탐색
		int new_d = (cleaner[2] + 3) % 4;
		int new_r = cleaner[0] + dir[new_d][0];
		int new_c = cleaner[1] + dir[new_d][1];

		// 왼쪽방향에 청소하지 않은 공간이 있다면(a)
		if (place[new_r][new_c] == 0) { 
			cleaner[0] = new_r; // 회전하고 한 칸 전진
			cleaner[1] = new_c;
			cleaner[2] = new_d;
		}
		else { // 왼쪽방향에 청소할 공간이 없다면
			cleaner[2] = new_d; // 그 방향으로 회전
			cnt++;
		}
		
	}
	
	cout << ans;

	return 0;
}
