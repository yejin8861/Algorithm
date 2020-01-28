from collections import Counter


def check_square(r_index, c_index):
    element = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    num = square_num[r_index][c_index]
    temp = []
    for r in range((num//3)*3, (num//3)*3+3):
        for c in range(num%3*3, num%3*3+3):
            temp.append(sudoku[r][c])
    number = element - set(temp)
    return number

def check_col(r_index, c_index):
    global answer
    global N
    element = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    for c in c_index:
        number = element - set(flip_sudoku[c])
        if number:
            if len(number) > 1: # 바로잡을 수 없음, 한번 더 체크
                number = check_square(r_index, c)
                if len(number) > 1: # 가로 한번 더 체크
                    number = element - set(sudoku[r_index])
            number = list(number)[0]
            sudoku[r_index][c] = number
            answer.append(r_index + 1)
            answer.append(c + 1)
            answer.append(number)
            N -= 1
    return



def solution():
    global answer
    for i, row in enumerate(sudoku):
        if N == 0:
            break
        if len(set(row)) != 9:  # 중복
            c_index = []
            count = Counter(row)
            # 개수가 2개 이상인 숫자 구하기
            duplication = [a[0] for a in count.items() if a[1] > 1]
            for col in range(9):
                if row[col] in duplication:
                    c_index.append(col)
            check_col(i, c_index)


    answer = str(answer).replace(',','')
    # print(answer)
    return answer[1:-1]



T = int(input())
for i in range(T):
    N = int(input())
    answer = []
    sudoku = [[0 for _ in range(9)] for _ in range(9)]
    for j in range(9):
        sudoku[j] = list(map(int, input().strip().split()))
    flip_sudoku = list(map(list, zip(*sudoku)))
    square_num = [[0,0,0,1,1,1,2,2,2],
                  [0,0,0,1,1,1,2,2,2],
                  [0,0,0,1,1,1,2,2,2],
                  [3,3,3,4,4,4,5,5,5],
                  [3,3,3,4,4,4,5,5,5],
                  [3,3,3,4,4,4,5,5,5],
                  [6,6,6,7,7,7,8,8,8],
                  [6,6,6,7,7,7,8,8,8],
                  [6,6,6,7,7,7,8,8,8]]
    result = solution()
    print('#%d'%(i+1),result)