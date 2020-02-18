
def solution(m, n, puddles):
    answer = 0
    matrix = [[0 for _ in range(m+1)] for _ in range(n+1)]
    for i,j in puddles:
        matrix[i][j] = True
    print(matrix)

    loc = [[0 for _ in range(m+1)] for _ in range(n+1)]

    for i in range(1,m+1):
        for j in range(1,n+1):
            print(i,j)

            if matrix[i][j] == 0:
                if i-1 < 1 or j-1 < 1:
                    loc[i][j] = 1
                else:
                    loc[i][j] = loc[i-1][j] + loc[i][j-1]

    print(loc[i][j])



    print(answer)
    return answer % 1000000007

if __name__ == '__main__':
    solution(6,4,[[2,2],[3,3]])