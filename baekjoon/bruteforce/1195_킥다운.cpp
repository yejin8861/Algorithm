/*
[문제]
튀어나온 것이 기어의 이(2), 들어간 곳이 홈(1).
이들을 맞물리게 끼우는게 킥다운 장치이다.

[출력]
두 기어가 주어졌을 때 만들 수 있는 가장 짧은 가로 너비를 출력하라.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int cnt;

bool is_possible() {
    cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        int n1 = a[i] - '0';
        int n2 = b[i] - '0';
        if (n1 > 0 && n2 > 0) {
            if (n1 + n2 < 4) cnt++;
            else return false;
        }
    }
    return true;
}

int main() {
    cin >> a >> b;
    if (a.size() > b.size()) swap(a, b);
    // b앞에 a의 길이만큼 0 추가
    int a_len = a.size();
    int b_len = b.size();
    int ans = a_len + b_len;
    for (int i = 0; i < a_len; i++) {
        b = '0' + b;
    }
    for (int i = 0; i < b_len; i++) {
        a += '0';
    }

    int len = a.size();
    // a앞에 0을 하나씩 추가하며 b와 비교

    int n = a_len + b_len;
    while (n--) {
        if (is_possible()) {
            ans = min(ans, a_len + b_len - cnt);
        }
        // a뒤의 0제거, 앞에 0추가
        a = '0' + a.substr(0, a.size() - 1);
    }
    printf("%d", ans);
    return 0;
}
