# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import re
def solution(A, B, F):
    pass

if __name__ == '__main__':
    s = input()
    s = list(re.findall('\d+',s))
    F = s.pop()
    A=[]
    B=[]
    N = len(s)//2
    for i in range(N):
        A.append(int(s[i]))
        B.append(int(s[i+N]))
        sum_A=0
        sum_B=0
    for i in range(F):
        if F % 2 == 0:
            sum_A += A[i] + A[N-1-i]