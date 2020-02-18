#include<cstdio>
#include<cstring>
#include<deque>
#include<vector>
using namespace std;
int N, M, T;
int dy[4] = { -1,1,0,0 }; // 상,하,좌,우
int dx[4] = { 0,0,-1,1 }; // dq[y][x]
int visited[51][51];
int cnt = 0;
deque<deque<int>> dq;
vector<pair<int, int>> v;

void dfs(int y,int x, int n) { 
	if (visited[y][x]) return;
	visited[y][x] = 1;
	dq[y][x] = 0;
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k], nx = (M + x + dx[k]) % M;
		if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {
			if (dq[ny][nx] == n) {
				cnt++;
				dfs(ny, nx, n); // 인접하면서 dq[y][x]와 같은 수 지우기
			}
		}
	}
	
}
void processing() {
	int sum = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] != 0) {
				total++;
				sum += dq[i][j];
			}
		}
	}
	float avg = float(sum) / float(total);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] > avg && dq[i][j]!=0) dq[i][j]--;
			else if (dq[i][j] < avg && dq[i][j]!=0) dq[i][j]++;
		}
	}
	return;
}
void rotation(int x, int d, int k) {
	// 1. d=0이면(시계 방향)
	if (d == 0) {
		for (int i = 0; i < N; i++) {
			if ((i + 1) % x == 0) { // x의 배수이면
				for (int j = 0; j < k; j++) {
					int temp = dq[i].back();
					dq[i].pop_back();
					dq[i].push_front(temp);
				}
			}
		 }
	}
	else { // 2. d=1이면(반시계 방향)
		for (int i = 0; i < N; i++) {
			if ((i + 1) % x == 0) { // x의 배수이면
				for (int j = 0; j < k; j++) {
					int temp = dq[i].front();
					dq[i].pop_front();
					dq[i].push_back(temp);
				}
			}
		}
	}
	cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!dq[y][x]) continue;
			int n = dq[y][x]; // 비교하는 숫자
			visited[y][x] = 1;
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k], nx = (M + x + dx[k]) % M;
				if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {
					if (dq[ny][nx] == n) {
						dq[y][x] = 0;
						cnt++;
						dfs(ny, nx, n); // 인접하면서 dq[y][x]와 같은 수 지우기
					}
				}
			}
			
		}
	}
	if (cnt == 0) { // 인접한 수가 없다면
		processing();
	}
	return;
	
}

int main() {
	scanf("%d %d %d", &N, &M, &T);
	dq.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			scanf("%d", &n);
			dq[i].push_back(n);
		}
	}
	for (int t = 0; t < T; t++) {
		memset(visited, 0, sizeof(visited));
		int x, d, k; // x:배수, d:방향(0=시계, 1=반시계), k:횟수
		scanf("%d %d %d", &x, &d, &k);
		rotation(x, d, k);
		
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			sum += dq[i][j];
	printf("%d", sum);
	return 0;
}
