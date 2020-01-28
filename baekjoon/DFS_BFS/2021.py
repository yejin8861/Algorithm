# 어떤 도시의 지하철 노선에 대한 정보가 주어졌을 때,
# 출발지에서 목적지까지의 최소 환승 경로를 구하는 프로그램을 작성하시오.
# 실제 경로를 구할 필요는 없고, 환승 회수만을 구하면 된다.
import sys
from collections import defaultdict, deque


def BFS(graph, start, destination):
    queue = deque(graph[start])
    print(queue)
    visited = []
    lines = []

    while queue:
        n, line = queue.popleft()
        lines.append(line)
        print(n, line)
        if n == destination:
            print(visited)
            print(len(set(lines))-1)
            return len(set(lines))-1

        if n not in visited:
            visited.append(n)
            print('v',visited)
            queue.extend(list(set(graph[n]) - set(visited)))
            print('q', queue)
    return -1


N, L = map(int, sys.stdin.readline().strip().split())
graph = defaultdict(list)
transfer = defaultdict(list)
for i in range(L):
    lines = list(map(int, sys.stdin.readline().strip().split('-1')[0].split()))
    print(lines)
    for j in range(len(lines)-1):
        graph[lines[j]].append((lines[j+1], i+1))
        graph[lines[j+1]].append((lines[j], i+1))
    transfer[i+1] = lines
print(graph)
print(transfer)
#
start, destination = map(int, sys.stdin.readline().strip().split())
print(start, destination)
result = BFS(graph, start, destination)
print(result)