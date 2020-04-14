/*
[문제]
- 규칙
1. 참가자는 마피아, 시민 두 그룹으로 나뉜다. 참가자의 번호는 0번부터 시작한다.
2. 밤 : 참가자가 짝수 명 남은 경우, 마피아가 죽일 사람 한 명을 고른다.
3. 낮 : 참가자가 홀수 명 남은 경우, 참가자가 유죄지수가 높은 사람 한 명을 죽인다.
4. 게임에 마피아가 한 명도 없으면 시민이 이긴 것, 시민이 한 명도 안 남았다면 마피아가 이긴 것,
게임은 즉시 종료된다.

- 진행
1. 밤에 마피아가 죽일 사람 한 명을 고른다.
만약 참가자 i가 죽었다면, 다른 참가자 j의 유죄 지수는 R[i][j]만큼 변한다.
2. 낮에 현재 게임에 남아있는 사람 중 유죄 지수가 가장 높은 사람을 죽인다.
여러 명인 경우 번호가 가장 작은 사람이 죽는다. 유죄 지수는 바뀌지 않는다.

[출력]
이 게임을 최대한 오래 하고 싶을 때, 몇 번의 밤이 지나는지 출력하라.
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 16
using namespace std;
int N;
int R[MAX][MAX];
int selected[MAX];
int MAFIA, ans;
int people;
vector<int> guilty;

void day() {
    // 유죄 지수가 높은 사람 죽이기
    int _max = 0, idx = 0;
    for (int i = 0; i < N; i++) {
        if (selected[i]) continue;
        if (_max < guilty[i]) {
            _max = guilty[i];
            idx = i;
        }
    }
    selected[idx] = 1;
    people--;
    return;
}

void update(int i) {
    for (int j = 0; j < N; j++) {
        if (selected[j]) continue;
        guilty[j] += R[i][j];
    }
}

void simulation(int cnt) {
    // 마피아가 죽거나 시민이 없는 경우 게임 종료
    if (selected[MAFIA] || people == 1) {
        ans = max(ans, cnt);
        return;
    }

    if (people % 2) {
        day();
        // 마피아가 죽거나 시민이 없는 경우 게임 종료
        if (selected[MAFIA] || people == 1) {
            ans = max(ans, cnt);
            return;
        }
    }

    // 마피아가 죽일 사람 한 명 고르기.
    for (int i = 0; i < N; i++) {
        if (selected[i] || i == MAFIA) continue;

        int backup_people = people;
        vector<int> backup = guilty;
        int backup_selected[MAX];
        memcpy(backup_selected, selected, sizeof(selected));
        
        selected[i] = 1;
        people--;
        update(i); // 유죄 지수 변경
        simulation(cnt + 1);

        // 복원
        guilty = backup;
        people = backup_people;
        memcpy(selected, backup_selected, sizeof(selected));
    }
}

int main() {
    scanf("%d", &N);
    people = N;
    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        guilty.push_back(n);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &R[i][j]);
        }
    }
    scanf("%d", &MAFIA);
    simulation(0);
    printf("%d", ans);
    return 0;
}
