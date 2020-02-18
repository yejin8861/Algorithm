from itertools import permutations

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    region = [list(map(int, input().strip().split())) for _ in range(N)]
    temp = [i for i in range(1, N)]
    myperms = list(permutations(temp, N-1))

    minimum = 999999
    for perm in myperms:
        using = region[0][perm[0]]
        for i in range(len(perm)-1):
            using += region[perm[i]][perm[i+1]]
        using += region[perm[-1]][0]
        if minimum > using:
            minimum = using
    print('#%d'%test_case, minimum)

