from collections import deque
def solution(board, moves):
    answer = 0
    array = []
    for i in range(len(board)):
        array.append(deque())

    for row in range(len(board)):
        for col in range(len(board)):
            if board[row][col] != 0:
                array[col].appendleft(board[row][col])
    print(array)

    basket = []
    for idx in moves:
        print('idx',idx, array[idx-1])
        print(basket)
        if array[idx-1]:
            doll = array[idx-1].pop()
            print('doll',doll)
            if basket:
                if basket[-1] == doll:
                    answer += 1
                    print('answer',answer)
                    basket.pop()
                else:
                    basket.append(doll)
            else:
                basket.append(doll)
    print(basket)
    print(array)
    print(answer*2)
    return answer*2


if __name__ == '__main__':
    solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],[1,5,3,5,1,2,1,4])