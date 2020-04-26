#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    float fail;
    int stage;
};
bool compare(node a, node b) {
    if (a.fail != b.fail) return a.fail > b.fail;
    else return a.stage < b.stage;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<node> result;
    int stage[502] = {};
    for (int n : stages) stage[n]++;
    
    int total = stages.size();
    for (int i = 1; i <= N; i++) {
        if (total <= 0) result.push_back({ 0, i });
        else result.push_back({ float(stage[i]) / float(total), i });
        total -= stage[i];
    }
    sort(result.begin(), result.end(), compare);
    for (auto r : result) answer.push_back(r.stage);
    return answer;
}
int main() {
    //solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
    solution(4, {3,3,3});
}
