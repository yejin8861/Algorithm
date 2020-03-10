
#include <string>
#include <vector>

using namespace std;
int map[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);

    // arr1 이진화
    for (int k = 0; k < n; k++) {
        int num = arr1[k] | arr2[k];
        for (int i = n - 1; i >= 0; i--) {
            if (num / (1 << i)) {
                map[k][n - 1 - i] = 1;
                num %= (1 << i);
            }
        }
    }
    // or 연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) answer[i].push_back('#');
            else answer[i].push_back(' ');
        }
    }
    return answer;
}
int main() {

    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}
