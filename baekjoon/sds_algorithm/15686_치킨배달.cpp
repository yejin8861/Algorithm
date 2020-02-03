#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 51
using namespace std;
int N, M;
int home_cnt = 0;
int city[MAX][MAX]; int dist[MAX][MAX];
int visited[MAX][MAX];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> v; // 전체 치킨집
vector<int> city_dists; // 도시의 치킨 거리값들
list<pair<int, int>> l; // 선택된 치킨집

void bfs() {
	memset(visited, 0, sizeof(visited));
	int dist = 0, min_dist = 0;
	int s = 0, cnt = home_cnt;
	list<pair<int, int>> lp = l;
	while (1) {
		if (cnt == 0) {
			city_dists.push_back(min_dist);
			return;
		}
		s = lp.size();
		dist++;
		for (int i = 0; i < s; i++) {
			int r = lp.front().first;
			int c = lp.front().second;
			lp.pop_front();
			visited[r][c] = 1;

			for (int k = 0; k < 4; k++) {
				int ny = r + dy[k];
				int nx = c + dx[k];
				if (0 < ny && ny <= N && 0 < nx && nx <= N && visited[ny][nx] == 0) {
					visited[ny][nx] = 1;
					if (city[ny][nx] == 1) { // 집이면 
						min_dist += dist;
						cnt--;
					}
					lp.push_back(make_pair(ny, nx));
				}
			}
		}
	}
}

void select_chicken(int start, int n) {
	if (n == M) {
		bfs();
		return;
	}
	for (int i = start; i < v.size(); i++) {
		l.push_back(v[i]);
		select_chicken(i + 1, n + 1);
		l.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) { // 치킨집이면
				v.push_back(make_pair(i, j));
			}
			else if (city[i][j] == 1) home_cnt++;
		}
	}
	memset(dist, 0, sizeof(dist));

	// 치킨집 M개 고르기
	select_chicken(0, 0);
	cout << *min_element(city_dists.begin(), city_dists.end());


	return 0;
}
