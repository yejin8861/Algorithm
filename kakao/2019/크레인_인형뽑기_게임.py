def find_num(board, size, col):
    row = 0
    while row < size:
        if board[row][col] != 0:
            ret = board[row][col]
            board[row][col] = 0
            return ret
        row += 1
    return -1


def solution(board, moves):
    answer = 0
    stack = []
    size = len(board)
    for col in moves:
        num = find_num(board, size, col-1)
        if num != -1: # 인형이 있는 경우
            # 1. stack에 다른 인형이 있거나 비어있는 경우
            if len(stack) == 0 or stack[-1] != num:
                stack.append(num)
            # 2. stack에 같은 인형이 있는 경우 제거 후 count
            else:
                stack.pop(-1)
                answer += 2
    
    return answer
