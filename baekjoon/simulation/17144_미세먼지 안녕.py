import sys
import copy

R, C, T = map(int, sys.stdin.readline().strip().split())

# 배열 초기화 #
array = [list(map(int, input().split())) for _ in range(R)]
air_cleaner = []
for i in range(R):
    if -1 in set(array[i]):
        col = array[i].index(-1)
        air_cleaner = (i, col)
        break


def diffuse():
    global array
    next_array = [[0 for _ in range(C)] for _ in range(R)]
    for row in range(R):
        for col in range(C):
            amount = array[row][col] // 5  # 확산량
            if amount > 0:
                r, c = row, col
                for r, c in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:  # 상,하,좌,우
                    if 0 <= r < R and 0 <= c < C and array[r][c] != -1:
                        next_array[r][c] += amount
                        array[row][col] -= amount
    for row in range(R):
        for col in range(C):
            array[row][col] += next_array[row][col]

    print('확산 끝')
    ############### print
    for row in array:
        print(row)

def purify():
    # 공기청정기 위쪽 순환
    # 오른쪽으로 이동
    origin_r, origin_c = air_cleaner
    r,c = origin_r, origin_c
    n = array[r][c + 1]
    array[r][c + 1] = 0
    c += 1

    while c + 1 < C:
        temp = array[r][c + 1]
        array[r][c + 1] = n
        n = temp
        c += 1
    # 위쪽으로 이동
    while r - 1 >= 0:
        temp = array[r - 1][c]
        array[r - 1][c] = n
        n = temp
        r -= 1
    # 왼쪽으로 이동
    while c - 1 >= 0:
        temp = array[r][c - 1]
        array[r][c - 1] = n
        n = temp
        c -= 1
    # 아래쪽으로 이동
    while r < origin_r:
        if array[r + 1][c] != -1:
            temp = array[r + 1][c]
            array[r + 1][c] = n
            n = temp
            r += 1
        else:  # 공기청정기
            r += 1
            break

    print('*' * 100)
    print('위쪽순환 끝')
    ############### print
    for row in array:
        print(row)

    # 공기청정기 아래쪽 순환
    origin_r += 1
    r, c = origin_r, origin_c
    n = array[r][c + 1]
    array[r][c + 1] = 0
    # 오른쪽으로 이동
    # 오른쪽으로 이동
    c += 1
    while c + 1 < C:
        temp = array[r][c + 1]
        array[r][c + 1] = n
        n = temp
        c += 1
    # 아래쪽으로 이동
    while r + 1 < R:
        temp = array[r + 1][c]
        array[r + 1][c] = n
        n = temp
        r += 1
    # 왼쪽으로 이동
    while c - 1 >= 0:
        temp = array[r][c - 1]
        array[r][c - 1] = n
        n = temp
        c -= 1
    # 위쪽으로 이동
    while r > origin_r:
        if array[r - 1][c] != -1:
            temp = array[r - 1][c]
            array[r - 1][c] = n
            n = temp
            r -= 1
        else:  # 공기청정기
            r -= 1
            break


    print('*' * 100)
    print('아래쪽순환 끝')
    ############### print
    for row in array:
        print(row)


def solution():
    for _ in range(T):
        diffuse()
        purify()

    print(sum(map(sum, array))+2)

solution()

