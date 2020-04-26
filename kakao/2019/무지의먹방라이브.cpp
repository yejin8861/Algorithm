#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct info {
    int index;
    ll time;
};
bool cmp1(const info &a, const info &b) {
    return a.time < b.time;
}
bool cmp2(const info &a, const info &b) {
    return a.index < b.index;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<info> tables;
    
    ll size = food_times.size();
    ll total = 0;
    for (int i = 0; i < size; i++) {
        tables.push_back({ i+1, food_times[i] });
        total += food_times[i];
    }
    if (total <= k) return -1;

    sort(food_times.begin(), food_times.end());
    sort(tables.begin(), tables.end(), cmp1);

    ll t = food_times[0];
    ll delTime = (ll)t * size;
    int curIdx, nextIdx;

    while (delTime < k) {
        k -= delTime;
        nextIdx = upper_bound(food_times.begin(), food_times.end(), t) - food_times.begin();
        curIdx = lower_bound(food_times.begin(), food_times.end(), t) - food_times.begin();
        size -= (nextIdx - curIdx);
        delTime = (ll)(food_times[nextIdx] - food_times[curIdx]) * size;
        t = food_times[nextIdx];
    }
    sort(tables.begin() + nextIdx, tables.end(), cmp2);

    answer = tables[nextIdx + (k%size)].index;
    return answer;
}

int main() {
    solution({ 3, 1, 2, 5, 4, 2 }, 10);
    //solution({ 3,1,2 }, 5);
    //solution({ 3,2,3,2,4 }, 12);
    //solution({ 3,1,1,1,2,4,3 }, 12);
}
