# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    #_A = set(A)
    # for num in _A:
    #     print(num)
    #     idx = A.index(num)
    #     print(idx)
    #     if A.count(num) % 2 == 1:
    #         return num
    A.sort()
    print(A)
    for i in range(0, len(A), 2):
        if i == len(A)-1 or A[i] != A[i+1]:
            print(A[i])
            return A[i]

if __name__ == '__main__':
    d = eval(input())
    solution(d)
