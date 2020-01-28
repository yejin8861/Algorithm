#include<iostream>
#include<algorithm>

using namespace std;
int L, C;
char password[15];
char combi[15];


void dfs(int start, int depth) {
	if (depth == L) {
		int vowel = 0;
		int consonant = 0;
		for (int i = 0; i < L; i++) {
			// 자음, 모음 개수 세기
			if (combi[i] == 'a' || combi[i] == 'e' || combi[i] == 'i' || combi[i] == 'o' || combi[i] == 'u')
				vowel++;
			else
				consonant++;
		}
		if (vowel >= 1 && consonant >= 2) {
			printf("%s\n", combi);
		}
		return;
	}

	for (int i = start; i < C; i++) {
		combi[depth] = password[i];
		dfs(i + 1, depth + 1);
	}

}


int main() {
	
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> password[i];
	}
	sort(password, password+C);
	dfs(0, 0);
	return 0;
}
