/*
길이가 N인 수식 -> 정수와 연산자(+,-,x)로 이루어짐.
수식은 왼쪽에서부터 순서대로 계산
문자열은 정수, 연산자가 반복.

괄호를 추가하면 괄호부터 계산
중첩 괄호는 X

식이 주어졌을 때 괄호를 추가해 만들 수 있는 식의 최댓값 구하기
(추가하지 않아도 됨.)
*/
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
deque<int> num;
deque<char> oper; 
int N;
int ans = -pow(2, 31);
deque<int> bracket;

int cal(int a, int b, char oper) {
    switch (oper) {
    case '+': a += b; return a;
    case '-': a -= b; return a;
    case '*': a *= b; return a;
    }
}

int cal_bracket(deque<int> tb){
    deque<int> temp_n;
    deque<char> temp_oper;
    temp_n.push_back(num[0]);

    // 1. 괄호 먼저 계산하기
    for (int i = 0; i < oper.size(); i++) {
        if (tb.size() > 0 && i == tb.front()) {
            tb.pop_front(); // 괄호 제거
            int a = temp_n.back(); temp_n.pop_back();
            // 괄호 안 계산해서 temp_n에 다시 넣기
            temp_n.push_back(cal(a, num[i + 1], oper[i]));
        }
        else {
            temp_n.push_back(num[i+1]);
            temp_oper.push_back(oper[i]);
        }
    }

    // temp 계산
    int sum = temp_n[0];
    for (int i = 0; i < temp_n.size() - 1; i++) {
        sum = cal(sum, temp_n[i + 1], temp_oper[i]);
    }
    return sum;
}

void dfs(int start, int n, int cnt) {
    if (n == cnt) {
        ans = max(ans, cal_bracket(bracket));
        return;
    }

    for (int i = start + 2; i < oper.size(); i++) {
        bracket.push_back(i);
        dfs(i, n+1, cnt);
        bracket.pop_back();
    }
}

int main() {
    string s;
    cin >> N >> s;
    
    for (char c : s) {
        if ('0' <= c && c <= '9') num.push_back(c - '0');
        else oper.push_back(c);
    }

    for (int k = 1; k <= N / 2; k++) {
        for (int i = 0; i < oper.size(); i++) {
            bracket.push_back(i);
            dfs(i, 1, k);
            bracket.pop_back();
        }
    }
    
    if (oper.size() == 0) cout << s;
    else cout << ans;
    return 0;
}

