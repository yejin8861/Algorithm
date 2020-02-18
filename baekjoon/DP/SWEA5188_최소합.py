
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    DP = [list(map(int, input().strip().split())) for _ in range(N)]
    minimum = [[0 for _ in range(N)] for _ in range(N)]
    minimum[0][0] = DP[0][0]
    for r in range(N):
        for c in range(N):
            temp = 0
            if r == 0 and c > 0:
                minimum[r][c] = minimum[r][c-1] + DP[r][c]
            elif c == 0 and r > 0:
                minimum[r][c] = minimum[r-1][c] + DP[r][c]
            else:
                if minimum[r-1][c] > minimum[r][c-1]:
                    minimum[r][c] = minimum[r][c-1] + DP[r][c]
                else:
                    minimum[r][c] = minimum[r-1][c] + DP[r][c]
    print('#%d'%test_case, minimum[N-1][N-1])