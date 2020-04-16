/*
간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때,
정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
*/
#include<cstdio>
#include<vector>
#define MAX 100005
using namespace std;
int N, R, Q;
int cnt[MAX];
vector<vector<int>> graph;
vector<vector<int>> tree;

void make_tree(int cur, int parent) {
    for (int node : graph[cur]) {
        if (node != parent) {
            tree[cur].push_back(node);
            make_tree(node, cur);
        }
    }
}

void count_SubTree(int cur) {
    cnt[cur] = 1;
    for (int node : tree[cur]) {
        count_SubTree(node);
        cnt[cur] += cnt[node];
    }
}

int main() {
    scanf("%d %d %d", &N, &R, &Q);
    graph.resize(N + 1);
    tree.resize(N + 1);
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    make_tree(R, -1);
    count_SubTree(R);

    // quary
    int q;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q);
        printf("%d\n", cnt[q]);
    }
    return 0;
}
