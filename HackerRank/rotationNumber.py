# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, K):
    if len(A) == 0:
        return 0
    for i in range(K):
        temp = A.pop()
        A.insert(0,temp)
    print(type(A))
    return A


if __name__ == '__main__':
    d = eval(input())
    A=d[0]
    K=d[1]
    solution(A,K)