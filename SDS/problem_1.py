
import copy


def rotate_270(num):
    global DICE
    ret = [[0]*3 for _ in range(3)]
    for r in range(3):
        for c in range(3):
            ret[2-c][r] = DICE[num][r][c]
    DICE[num] = ret
    # print(DICE[num])

def rotate_90(num):
    global DICE
    ret = [[0]*3 for _ in range(3)]
    for r in range(3):
        for c in range(3):
            ret[c][2-r] = DICE[num][r][c]
    DICE[num] = ret



def rotate_code(num):
    global DICE
    if num < 4: # 1,2,3
        A = copy.deepcopy(DICE[0]) # A면 저장
        for n in range(1, 5):
            for row in range(3):
                if n < 4:
                    DICE[n-1][row][num-1] = DICE[n][row][num-1]
                else:
                    # A -> D
                    DICE[3][row][num-1] = A[row][num-1]
        if num == 1:
            # E가 반시계 방향으로 회전
            rotate_270(4)
        elif num == 3:
            # F가 시계 방향으로 회전
            rotate_90(5)

    elif 4 <= num <= 6:
        D = copy.deepcopy(DICE[3])  # D면 저장
        for n in range(2,-2,-1):
            for row in range(3):
                if n > -1:
                    DICE[n+1][row][num-4] = DICE[n][row][num-4]
                else:
                    # D->A
                    DICE[0][row][num - 4] = D[row][num - 4]

        if num == 4:
            # E가 시계 방향으로 회전
            rotate_90(4)
        elif num == 6:
            # F가 반시계 방향으로 회전
            rotate_270(5)

    elif 7 <= num <= 9:
        E = copy.deepcopy(DICE[4])  # E면 저장
        dice_list = [4,1,5,3]
        for i in range(1,5):
            for col in range(3):
                if i < 3:
                    DICE[dice_list[i-1]][num-7][col] = DICE[dice_list[i]][num-7][col]
                elif i == 3: # D->F
                    DICE[dice_list[i-1]][num-7][col] = DICE[dice_list[i]][2 - (num-7)][2-col]
                elif i == 4: # E -> D
                    DICE[dice_list[3]][2-(num-7)][2-col] = E[num-7][col]
        if num == 7:
            # A가 시계방향으로 회전
            rotate_90(0)
        elif num == 9:
            # C가 반시계방향으로 회전
            rotate_270(2)
    else:
        F = copy.deepcopy(DICE[5])  # F면 저장
        dice_list = [5, 1, 4, 3]
        for i in range(1, 5):
            for col in range(3):
                if i < 3:
                    DICE[dice_list[i-1]][num-10][col] = DICE[dice_list[i]][num-10][col]
                elif i == 3: # D->E
                    DICE[dice_list[i-1]][num-10][col]=DICE[dice_list[i]][2 - (num-10)][2-col]
                elif i == 4: # F -> D
                    DICE[dice_list[3]][2 - (num-10)][2-col] = F[num-10][col]
        if num == 10:
            # A가 반시계방향으로 회전
            rotate_270(0)
        elif num == 12:
            # C가 시계방향으로 회전
            rotate_90(2)


def Print(n, P):
    # 출력
    global DICE
    answer = []
    for r in range(3):
        for c in range(3):
            answer.append(DICE[P-1][r][c])
    # answer = str(answer)
    answer = str(answer).replace(',', '')
    print('#%d '%(n+1) + answer[1:-1])


# input

T = int(input())
for n in range(T):
    l = list(map(int, input().strip().split()))
    DICE = [[[i + (j * 3) + (k * 9) for i in range(1, 4)] for j in range(3)] for k in range(6)]
    M, P = l[0], l[-1]
    for i in range(1, M+1):
        num = l[i]
        rotate_code(num)
    Print(n, P)