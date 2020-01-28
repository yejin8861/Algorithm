import re
import sys

def solution(N, computers):
    distance = 0
    # INDEX = [m.start() for m in re.finditer('1', computers)]
    INDEX = []
    for i in range(len(computers)):
        if computers[i] == 1:
            INDEX.append(i)

    if len(INDEX) == 0:
        return 0, N

    # group 초기화
    group = [0 for _ in range(N)]
    for idx in INDEX:
        group[idx] = idx
    # print(group)

    for idx in INDEX:
        cnt = 0
        flag = 0
        for j in range(idx-1, -1, -1):
            if cnt > 4:
                break
            if computers[j] == 0:
                cnt += 1
                distance += (idx - j)
                # 아무 그룹에 포함되지 않은 경우
                if group[j] == 0:
                    group[j] = idx
                    N -= 1
                else:
                    flag = 1
        if flag == 1:
            N -= 1

    return [distance, N]



T = int(input())
for i in range(T):
    N = int(input())
    # computers = ''.join(map(str, input().strip().split()))
    computers = list(map(int, sys.stdin.readline().strip().split()))
    # computers = list(map(int, sys.stdin.readline()))
    distance, group = solution(N, computers)

    print('#%d'%(i+1), distance, group)