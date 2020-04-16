/*
[문제]
고속도로 위에 N개의 센서를 설치했으며 최대 K개의 집중국을 세울 수 있다.
N개의 센서가 적어도 하나의 집중국과는 통신이 가능해야 하며
각 집중국의 수신 가능 영역의 길이 합을 최소화해야 한다.

[출력]
최대 K개의 집중국의 수신 가능 영역의 길이의 합의 최솟값 출력.

[풀이]
각 센서 거리의 차이값 중 K-1개의 최대값을 제거.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
vector<int> sensor;
vector<int> diff;
long long total;
bool cmp(int &a, int &b){
    return a > b;
}
int main() {
    scanf("%d %d", &N,&K);
    int n;
    for (int i = 0; i < N; i++){
        scanf("%d", &n);
        sensor.push_back(n);
    }
    // 예외 : N <= K인 경우
    if (N <= K) {
        printf("0");
        return 0;
    }
    sort(sensor.begin(), sensor.end());
    for (int i = 1; i < N; i++) {
        diff.push_back(sensor[i] - sensor[i - 1]);
        total += sensor[i] - sensor[i - 1];
    }
    sort(diff.begin(), diff.end(), cmp);
    for (int i = 0; i < K-1; i++) {
        total -= diff[i];
    }
    printf("%lld", total);
    return 0;
}

