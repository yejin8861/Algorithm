import re

def solution(N, computers):
    distance = 0
    INDEX = [m.start() for m in re.finditer('1', computers)]
    if len(INDEX) == 0:
        return 0, N

    # group 초기화
    group = [0 for _ in range(N)]
    for idx in INDEX:
        group[idx] = idx
    # print(group)

    for idx in INDEX:
        cnt = 0
        for j in range(idx-1, -1, -1):
            if cnt > 4:
                break
            if computers[j] == '0':
                cnt += 1
                distance += (idx - j)
                # 아무 그룹에 포함되지 않은 경우
                if group[j] == 0:
                    group[j] = idx
                else:
                # 이미 그룹에 포함된 경우
                    near = group[j]
                    for i in range(idx,-1,-1):
                        if group[i] == near or group[i] == idx:
                            group[i] = idx
                        else:
                            break

    zeros = group.count(0)

    group_num = zeros + len(set(group))
    return [distance, group_num-1] if zeros else [distance, group_num]




T = int(input())
for i in range(T):
    N = int(input())
    computers = ''.join(map(str, input().strip().split()))
    distance, group = solution(N, computers)

    print('#%d'%(i+1), distance, group)