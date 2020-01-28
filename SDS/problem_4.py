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
    print(group)

    for idx in INDEX:
        cnt = 0
        for j in range(idx-1, -1, -1):
            if cnt > 4:
                break
            if computers[j] == '0':
                cnt += 1
                distance += (idx - j)
                # print('d', distance)
                # 아무 그룹에 포함되지 않은 경우
                # print('group j',group,j)
                if group[j] == 0:
                    group[j] = idx
                else:
                # 이미 그룹에 포함된 경우
                    str_group = ''.join(map(str, group)) # 배열을 문자열로 변환
                    print('str',str_group)
                    update_group = str_group.replace(str(idx), str(group[j])) # 같은 그룹으로 묶기
                    print('update',update_group)
                    group = list(map(int, update_group)) # 문자열을 배열로 변환
                    print('group',group)
            # print(group)


    zeros = group.count(0)
    print(zeros)

    group_num = zeros + len(set(group))
    print(distance, group_num)

    return distance, group_num




T = int(input())
for i in range(T):
    N = int(input())
    computers = ''.join(map(str, input().strip().split()))
    distance, group = solution(N, computers)

    print('#%d'%i, distance, group)