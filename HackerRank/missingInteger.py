# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


# returns the smallest positive integer
def solution(A):
    smallest = 1
    A.sort()
    for i in range(len(A)):
        if A[i] == smallest:
            smallest += 1
    print(smallest)
    return smallest

if __name__ == '__main__':
    data = eval(input())
    solution(data)