# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    A.sort()
    if len(A) == 0 or A[0] != 1:
        return 1
    for i in range(len(A)-1):
        if A[i+1] - A[i] != 1:
            return A[i]+1
    return len(A)+1

if __name__ == '__main__':
    data = eval(input())
    solution(data)