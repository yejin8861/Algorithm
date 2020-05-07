# [1,5,6,10] -> [5,6,10,13] -> [6,10,13,17] -> [10,13,17,18] ..
# 이런식으로 weak를 한 칸씩 밀면서 dist가 닿을 수 있는 거리인지 확인.
# dist는 permutation으로 가능한 모든 순열(친구를 투입할 순서) [4,3,2] -> [4,2,3] -< [3,4,2]..

from collections import deque
from itertools import permutations

def solution(n, weak, dist):
    dist.sort(reverse=True)
    weak = deque(weak, maxlen=len(weak))
    for k in range(1, len(dist)+1):
        temp = dist[:k]
        perms = list(permutations(temp))
        # 취약 지점 확인
        for perm in perms:
            perm = list(perm)
            for _ in range(len(weak)):
                idx = 0
                i = 0
                cnt = perm[0]
                while True:
                    if weak[i+1] - weak[i] <= cnt:
                        cnt -= (weak[i+1] - weak[i])
                    else:
                        idx += 1
                        if idx >= len(perm): # 더이상 이동할 친구가 없으면 break.
                            break
                        cnt = perm[idx]
                    i += 1
                    if i == len(weak)-1: # 취약 지점 전부 점검한 경우 그 때의 친구 수 return.
                        print(k)
                        return k
                # weak 밀기
                weak.append(weak[0]+n)
    print(-1)
    return -1 # 친구를 전부 투입해도 점검할 수 없는 경우 -1.


if __name__ == '__main__':
    # solution(12,[1, 5, 6, 10],[1, 2, 3, 4])
    solution(12,[1, 3, 4, 9, 10],[3, 5, 7])