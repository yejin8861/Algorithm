#include<cstdio>
#include<cstring>
#include<algorithm>
int N, L;
int map[105][105];
int ans;
int visited[105][105];

void check_row() {
    memset(visited, 0, sizeof(visited));
    for (int r = 0; r < N; r++) {
        int cnt = 1, c = 0;
        while (c < N - 1) {
            if (abs(map[r][c] - map[r][c + 1]) == 1) { // 높이가 1차이 날 경우
                if (map[r][c] < map[r][c + 1]) { // 오르막길
                    if (visited[r][c]) break; // 이미 경사로가 있으면 break
                    if (cnt < L) break; // 경사로를 놓을 수 없으면 break
                    for (int i = 0; i < L; i++)
                        visited[r][c - i] = 1; // 경사로 놓기
                }
                else { // 내리막길
                    if (visited[r][c + 1]) break; // 이미 경사로가 있으면 break
                    int i = c + 1, cnt = 1;
                    while (map[r][i] == map[r][i + 1]) {
                        i++;
                        cnt++;
                    }

                    if (cnt < L) break; // 경사로를 놓을 수 없으면 break
                    for (int k = 1; k <= L; k++)
                        visited[r][c + k] = 1; // 경사로 놓기
                    c += L - 1;
                }
                cnt = 1;
            }
            else if (map[r][c] == map[r][c + 1]) {
                if (!visited[r][c]) cnt++;
            }
            else break;
            c++;
        }
        if (c >= N - 1) ans++;
    }
    return;

}

void check_col() {
    memset(visited, 0, sizeof(visited));
    for (int c = 0; c < N; c++) {
        int cnt = 1, r = 0;
        while (r < N - 1) {
            if (abs(map[r][c] - map[r + 1][c]) == 1) { // 높이가 1차이 날 경우
                if (map[r][c] < map[r + 1][c]) { // 오르막길
                    if (visited[r][c]) break; // 이미 경사로가 있으면 break
                    if (cnt < L) break; // 경사로를 놓을 수 없으면 break
                    for (int i = 0; i < L; i++)
                        visited[r - i][c] = 1; // 경사로 놓기
                }
                else { // 내리막길
                    if (visited[r + 1][c]) break; // 이미 경사로가 있으면 break
                    int i = r + 1, cnt = 1;
                    while (map[i][c] == map[i + 1][c]) {
                        i++;
                        cnt++;
                    }

                    if (cnt < L) break; // 경사로를 놓을 수 없으면 break
                    for (int k = 1; k <= L; k++)
                        visited[r + k][c] = 1; // 경사로 놓기
                    r += L - 1;
                }
                cnt = 1;
            }
            else if (map[r][c] == map[r + 1][c]) {
                if (!visited[r][c]) cnt++;
            }
            else break;
            r++;
        }
        if (r >= N - 1) ans++;
    }
    return;
}

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 행 검사
    check_row();
    // 열 검사
    check_col();
    
    printf("%d", ans);
    return 0;
}
