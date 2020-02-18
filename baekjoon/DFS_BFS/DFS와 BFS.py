# 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
# 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
# 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
from collections import deque
import sys


def perform_DFS(graph, root):
    if root not in graph:
        return root

    visited = []
    result = ''
    stack = [root]

    while stack:
        n = stack.pop()
        if n not in visited:
            result += str(n) + ' '
            visited.append(n)
            stack += sorted(graph[n] - set(visited), reverse=True)
    return result.strip()


def perform_BFS(graph, root):
    if root not in graph:
        return root

    visited = []
    result = ''
    queue = deque([root])

    while queue:
        n = queue.popleft()
        if n not in visited:
            result += str(n) + ' '
            visited.append(n)
            print('v',visited)
            queue += sorted(graph[n] - set(visited))
            print('q',queue)
    return result.strip()

if __name__ == '__main__':
    N, M, V = map(int, sys.stdin.readline().strip().split())
    graph = {}
    # 그래프 구성
    for i in range(M):
        n1, n2 = map(int, sys.stdin.readline().strip().split())
        # if n1 not in graph:
        #     graph[n1] = set([n2])
        # else:
        #     graph[n1].add(n2)
        #
        # if n2 not in graph:
        #     graph[n2] = set([n1])
        # else:
        #     graph[n2].add(n1)
        graph[n1] = {n2} | graph[n1] if n1 in graph else {n2}
        graph[n2] = {n1} | graph[n2] if n2 in graph else {n1}
        print(graph)
    print(perform_DFS(graph, V))
    print(perform_BFS(graph, V))