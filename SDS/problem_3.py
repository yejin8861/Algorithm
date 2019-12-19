

def is_possible(A, B0, B1, B2, B3):
    # print('possible', max(max(A)), 1.2*min(max((map(max, B0))),max((map(max, B1))),max((map(max, B2))),max((map(max, B3)))))
    # print(max((map(max, B0))))
    # print(max((map(max, B1))))
    # print(max((map(max, B2))))
    # print(max((map(max, B3))))
    if max(map(max, A)) <= 1.2*min(max(map(max, B0)),max(map(max, B1)),max(map(max, B2)),max(map(max, B3))):
        return True
    else:
        return False


def divide_quad(N, A):
    global answer
    if N == 2:
        return
    B0 = [0 for _ in range(N // 2)]
    B1 = [0 for _ in range(N // 2)]
    B2 = [0 for _ in range(N // 2)]
    B3 = [0 for _ in range(N // 2)]

    for row in range(N):
        if row < N//2:
            B0[row] = A[row][:N // 2]
            B1[row] = A[row][N // 2:]
        else:
            B2[row - N // 2] = A[row][:N // 2]
            B3[row - N // 2] = A[row][N // 2:]
    # print(B0)
    # print(B1)
    # print(B2)
    # print(B3)
    if is_possible(A, B0, B1, B2, B3):
        answer += '1'
        divide_quad(N // 2, B0)
        divide_quad(N // 2, B1)
        divide_quad(N // 2, B2)
        divide_quad(N // 2, B3)
        return
    else:
        answer += '0'
        return


T = int(input())
for i in range(T):
    temp = list(map(int, input().strip().split()))
    N = temp[0]
    MATRIX = [0 for _ in range(N)]
    for row in range(N):
        # print(temp[N*row+1:N*(row+1)+1])
        MATRIX[row] = temp[N*row+1:N*(row+1)+1]
    answer = ''
    divide_quad(N,MATRIX)
    print('#%d'%(i+1), answer)