from collections import deque

N, M = map(int, input().strip().split())
board = []
for _ in range(N):
    board.extend(map(list, input().split()))

def up(p1,p2):
    _row, _col = p1
    row, col = _row, _col
    while board[row-1][col] != '#' and (row-1,col) != p2:
        row -= 1
        if board[row][col] == 'O':
            row = col = -1
            break
    return (row, col)
def down(p1,p2):
    _row, _col =  p1
    row, col = _row, _col
    while board[row + 1][col] != '#' and (row+1,col) != p2:
        row += 1
        if board[row][col] == 'O':
            row = col = -1
            break
    return (row, col)
def left(p1,p2):
    _row, _col = p1
    row, col = _row, _col
    while board[row][col-1] != '#' and (row,col-1) != p2:
        col -= 1
        if board[row][col] == 'O':
            row = col = -1
            break
    return (row, col)
def right(p1,p2):
    _row, _col = p1
    row, col = _row, _col
    while board[row][col + 1] != '#' and (row,col+1) != p2:
        col += 1
        if board[row][col] == 'O':
            row = col = -1
            break
    return (row, col)

def BFS(red, blue, hole):
    visited = []
    red_queue = deque(list())
    blue_queue = deque(list())
    red_queue.append(red)
    blue_queue.append(blue)
    print(red_queue, blue_queue)

    cnt = 0
    r_result, b_result = [], []
    # r_result, b_result = 999, 999

    # 빨간 구슬
    while cnt <= 10:
        print('r_result', r_result, 'b_result', b_result)

        SIZE = len(red_queue)
        for _ in range(SIZE):
            print(red_queue)
            print(blue_queue)
            red = red_queue.popleft()
            blue = blue_queue.popleft()
            print(red, blue)

            if red == (-1,-1):
                if blue == (-1,-1):
                    r_result.append(cnt)
                    b_result.append(cnt)
                else:
                    r_result.append(cnt)
                    b_result.append(999)
            if blue == (-1,-1):
                b_result.append(cnt)
                r_result.append(999)
            print('v',visited)
            if (red, blue) not in visited:
                visited.append((red, blue))
                if red[1] == blue[1]: # 같은 col에 있고
                    if red[0] < blue[0]: # red가 높게 있으면
                        new_red = up(red, blue)
                        new_blue = down(blue, red)
                        # up
                        red_queue.append(new_red)
                        blue_queue.append(up(blue, new_red))
                        # down
                        red_queue.append(down(red, new_blue))
                        blue_queue.append(new_blue)
                    else:
                        new_red = down(red, blue)
                        new_blue = up(blue, red)
                        # up
                        red_queue.append(up(red, new_blue))
                        blue_queue.append(new_blue)
                        # down
                        red_queue.append(new_red)
                        blue_queue.append(down(blue, new_red))
                    # left
                    red_queue.append(left(red, blue))
                    blue_queue.append(left(blue, red))
                    # right
                    red_queue.append(right(red, blue))
                    blue_queue.append(right(blue, red))
                else: # 다른 col인데
                    if red[1] < blue[1]: # red가 더 좌측에 있으면
                        new_red = left(red, blue)
                        new_blue = right(blue, red)
                        # left
                        red_queue.append(new_red)
                        print('new_red',new_red)
                        blue_queue.append(left(blue, new_red))
                        print('blue',left(blue, new_red))
                        # right
                        red_queue.append(right(red, new_blue))
                        blue_queue.append(new_blue)
                    else:
                        new_red = right(red, blue)
                        new_blue = left(blue, red)
                        # left
                        red_queue.append(left(red, new_blue))
                        blue_queue.append(new_blue)
                        # right
                        red_queue.append(new_red)
                        blue_queue.append(right(blue,new_red))
                    # up
                    print('up red blue',red, blue)
                    red_queue.append(up(red, blue))
                    blue_queue.append(up(blue, red))
                    #down
                    red_queue.append(down(red, blue))
                    blue_queue.append(down(blue, red))
        cnt += 1
    if r_result:
        if min(r_result) < 999:
            for i in range(len(r_result)):
                if r_result[i] < b_result[i]:
                    return r_result[i]
            return -1
        else:
            return -1
    else:
        return -1


def solution():
    for idx, row in enumerate(board):
        print(row)
        if 'R' in set(row):
            r_row, r_col = idx, row.index('R')
        if 'B' in set(row):
            b_row, b_col = idx, row.index('B')
        if 'O' in set(row):
            o_row, o_col = idx, row.index('O')
    print('R:',(r_row, r_col))
    print('B:',(b_row, b_col))
    print('O:',(o_row, o_col))
    print(BFS((r_row,r_col), (b_row, b_col), (o_row, o_col)))

solution()