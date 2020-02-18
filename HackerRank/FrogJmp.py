# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import math

def solution(X, Y, D):
    answer = math.ceil((Y-X)/D)
    print(answer)
    return answer


if __name__ == '__main__':
    d = eval(input())
    X = d[0]
    Y = d[1]
    D = d[2]
    solution(X,Y,D)