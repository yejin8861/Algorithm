/*
[문제]
1. 임의의 양의 정수 n에 대해, 
'w' n번, 그 다음 'o' n번, 'l' n번, 'f' n번 나온 단어는 올바른 단어이다.
2. 올바른 단어 두 개를 이은 단어도 올바른 단어이다.

[출력]
입력으로 주어진 단어가 올바른 단어인 경우 1, 아니면 0을 출력한다.
*/
#include<iostream>
#include<string>
using namespace std;
string s;
char word[] = { 'w','o','l','f' };
int cnt = 1;

bool is_correct(int start) {
    int idx = -1;
    for (int i = 0; i < 4 * cnt; i++) {
        if (i%cnt == 0) idx++;
        if (s[start + i] != word[idx]) return false;
    }
    return true;
}

int main() {
    cin >> s;
    int i = 0;
    int start = 0;
    int flag = 0;

    while(i < s.size()){
        char cur = s[i];
        char next = s[i+1];
        if (cur != next) {
            if (!is_correct(start)) {
                cout << 0;
                return 0;
            }
            flag = 1;
            start += 4 * cnt;
            i = start - 1;
            cnt = 1;
        }
        else cnt++;
        i++;
    }
    if(flag) cout << 1;
    else cout << 0;
    return 0;
}
