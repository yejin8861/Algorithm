# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
#import numpy as np

def solution(X, A):
    check = A.copy()
    check = list(set(sorted(check)))
    trans = []
    for i in range(len(check)):
        trans.append([check[i],0])

    newdict = dict(trans)
    #print(newdict)
    for i in range(1,len(A)+1):
        newdict[A[i-1]] = 1
        if i >= X:
            cnt = [value for value in newdict.values()]
            #print(cnt)
            if sum(cnt[0:X]) == X:
                #print(i-1)
                return i-1
    #print('-1')
    return -1


if __name__ == '__main__':
    X, A = eval(input())
    solution(X,A)