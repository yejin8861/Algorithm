,D,T는 점수마다 하나씩 존재
스타상, 아차상은 점수마다 둘 중 하나만 존재 or 존재X
# 출력
총 점수 반환
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
map<char, int> m;
vector<int> v;

void perform_option(char c) {
    if (c == '*') {
        if (v.size() >= 2) {
            int sec = v.back(); v.pop_back();
            int fir = v.back(); v.pop_back();
            v.push_back(fir*2);
            v.push_back(sec*2);
        }
        else {
            int fir = v.back(); v.pop_back();
            v.push_back(fir*2);
        }
    }
    else {
        int fir = v.back(); v.pop_back();
        v.push_back(-fir);
    }
    return;
}

int solution(string dartResult) {
    m['S'] = 1; m['D'] = 2; m['T'] = 3;
    int answer = 0;
    string num;
    for (char next : dartResult) {
        if (next == 'S' || next == 'D' || next == 'T') {
            int n = atoi(num.c_str());
            v.push_back(pow(n,m[next]));
            num.clear();
        }
        else if (next == '*' || next == '#') perform_option(next);
        else num += next;
    }
    // 점수 합 구하기
    for (int n : v) answer += n;
    printf("%d", answer);
    return answer;
}

int main() {
    string s;
    cin >> s;
    solution(s);
}
