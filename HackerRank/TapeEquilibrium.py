# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
# returns the minimal difference that can be achieved.
    minimum = 100000
    for i in range(1,len(A)):
        d = abs(sum(A[0:i]) - sum(A[i:]))
        if minimum > d:
            minimum = d
    return minimum


if __name__ == '__main__':
    data = eval(input())
    solution(data)