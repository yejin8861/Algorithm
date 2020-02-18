from itertools import combinations
from collections import deque
import copy

N, M = map(int, input().strip().split())
lab = []
active = []
INF = 99999
for i in range(N):
    row = list(map(int, input().strip().split()))
    lab.append(row)
    if 2 in set(row):
        active.extend([(i,j) for j in range(N) if row[j] == 2])

def is_full(lab):
    for row in lab:
        if 0 in set(row):
            return False
    return True

def BFS(act_virus):
    _lab = copy.deepcopy(lab)
    visited = [[False]*N for _ in range(N)]
    queue = deque()
    inactive = set(active) - set(act_virus)
    queue.extend(act_virus)
    print(act_virus)
    time = 0
    while queue:
        for rr in _lab:
            print(rr)
        print('*'*20)
        size = len(queue)
        for _ in range(size):
            row, col = queue.popleft()
            if not(visited[row][col]):
                visited[row][col] = True
                for r,c in [(row-1,col),(row+1,col), (row,col-1), (row,col+1)]:
                        if 0 <= r < N and 0 <= c < N and _lab[r][c] != 1 and not(visited[r][c]):
                            queue.append((r,c))
                            if _lab[r][c] == 0:
                                _lab[r][c] = 1
        time += 1

    if is_full(_lab):
        return time - 1
    else:
        return INF


def solution():
    combis = list(combinations(active, M))
    time = INF
    if is_full(lab):
        print(0)
        return

    for combi in combis:
        t = BFS(combi)
        if t < time:
            time = t
    if time == INF:
        print(-1)
    else:
        print(time)

solution()