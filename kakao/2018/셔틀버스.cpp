/*
셔틀은 09:00부터 총 n회, t분 간격으로 도착. 하나의 셔틀엔 m명 탑승 가능.
09:00셔틀엔 09:00에 도착한 사람도 탈 수 있음.
도착시간 = 00:01 ~ 23:49
제일 늦은 도착 시각 출력

! 시간 표현 주의 (900 - 1 => 859가 되어야 함.)
처음에 전부 다 분으로 계산하고
마지막에 /60, %60으로 나타내는 게 나을듯.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int at; // 도착시간
    int cnt; // 탑승 최대 인원
};
deque<int> Time;
vector<node> shuttle;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    // 시간 벡터
    for (int i = 0; i < timetable.size(); i++) {
        timetable[i].erase(2,1);
        Time.push_back(stoi(timetable[i]));
    }
    sort(Time.begin(), Time.end()); // 시간 순 정렬

    // 셔틀 벡터
    for (int i = 0; i < n; i++) {
        int time = 900 + 100*((i*t)/60) + (i*t) % 60;
        shuttle.push_back({ time, m });
    }
    int LAST = shuttle.back().at;
    int flag = 0;
    int num = LAST;
    for (int i = 0; i < shuttle.size(); i++) {
        while (!Time.empty()) {
            // 1. 셔틀에 탈 수 없으면 다음 차 타기
            if (Time.front() > shuttle[i].at || shuttle[i].cnt == 0) {
                flag = 1;
                break;
            }
            else if (Time.front() <= shuttle[i].at) {
                // 2. 막차인데 한자리 남은 경우 (콘이 타야함.)
                if (shuttle[i].at == LAST && shuttle[i].cnt==1) { 
                    // Time의 1초 이전 시간
                    if (Time.front() % 100 == 0) { // HH:00 정각일 때
                        num = Time.front() - 41;
                    }
                    else num = Time.front() - 1;
                    flag = 1;
                    break;
                }
                Time.pop_front();
                shuttle[i].cnt--;
            }
        }
        // 3. 크루가 전부 탔는데 차가 남아있으면 막차 시간에 타기
        if(flag==0) num = LAST;
    }
    int zero = 4 - to_string(num).size();
    for (int i = 0; i < zero; i++)
        answer += "0";
    answer += to_string(num);
    answer.insert(2, ":");
    
    cout << answer;
    return answer;
}
int main() {
    //solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
    //solution(2, 10, 2, { "09:10", "09:09", "08:00" });
    //solution(2, 1, 2, { "09:00","09:00","09:00","09:00" });
    solution(10, 60, 45, { "23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59" });
}
