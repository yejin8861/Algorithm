/*
크레인 N대, 1분에 박스 하나씩 배에 실을 수 있다.
모든 박스를 배로 옮기는데 드는 시간의 최솟값 구하기.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> crane, box;
int check[10001];
int N, M, cnt;

bool movable() {
    bool flag = false;
    int i = 0, idx = 0;
    while (i < N) {
        // 이미 옮겼거나 옮기지 못하는 무게인 경우
        while (check[idx] || crane[i] < box[idx]) {
            idx++;
            if (idx >= M) return flag;
        }
        check[idx] = 1;
        cnt--;
        flag = true;
        i++;
    }
    return flag;
}

int main() {
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        crane.push_back(n);
    }
    scanf("%d", &M);
    cnt = M;
    for (int j = 0; j < M; j++) {
        scanf("%d", &n);
        box.push_back(n);
    }
    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());
    
    int time = 0;
    while (movable()) time++;
    if (cnt > 0) return !printf("-1"); // 아직 박스가 남아있는 경우
    else return !printf("%d", time);
}
