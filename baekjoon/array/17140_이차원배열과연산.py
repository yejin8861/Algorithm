from collections import Counter

r,c,k = map(int, input().strip().split())
array = []
MAX_LEN = 3
time = 0
for _ in range(MAX_LEN):
    array.append(list(map(int, input().strip().split())))


def row_function(array):
    global MAX_LEN
    new_array = []
    MAX_LEN = 0
    for row in array:
        count = sorted(Counter(row).items(), key=lambda x: (x[1], x[0]))
        temp = []
        for c in count:
            if c[0] != 0:
                temp.extend([*c])
        MAX_LEN = max(MAX_LEN, len(temp))
        new_array.append(temp)

    # 0으로 채우기
    for row in new_array:
        for _ in range(MAX_LEN-len(row)):
            row.append(0)
    return new_array

def col_function():
    global MAX_LEN
    MAX_LEN = 0
    eval_list = []
    # 가로,세로 바꾸기
    for i in range(len(array)):
        eval_list.append(eval('array'+'['+str(i)+']'))
    col_list = list(zip(*[eval_list[i] for i in range(len(eval_list))]))

    new_array = row_function(col_list)

    # 다시 가로,세로 바꾸기
    eval_list = []
    for i in range(len(new_array)):
        eval_list.append(eval('new_array'+'['+str(i)+']'))
    new_array = list(map(list, zip(*[eval_list[i] for i in range(len(eval_list))])))

    return new_array


def solution():
    global time, array
    while time < 101:
        for row in array:
            print(row)
        print(time)
        print('*'*20)
        n_row = len(array)
        n_col = len(array[0])
        if n_row > 100:
            array = array[:100][:]
            n_row = 100
        if n_col > 100:
            array = array[:][:100]
            n_col = 100

        if n_row > r-1 and n_col > c-1:
            if array[r - 1][c - 1] == k:
                print(time)
                return

        if n_col <= n_row: # 행이 더 길 때 행에 대해 정렬
            new_array = row_function(array)

        else: # 열에 대해 정렬
            new_array = col_function()

        array = new_array
        time += 1

    print(-1)


solution()