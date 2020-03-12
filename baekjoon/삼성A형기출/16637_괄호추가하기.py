from collections import deque

def cal_Seq(temp):
    SUM = temp.pop(0)
    while len(temp) > 0:
        op, n = temp.pop(0), temp.pop(0)
        if op == '+' : SUM += n
        elif op == '-' : SUM -= n
        else : SUM *= n
    return SUM


def cal_bracket():
    temp = [num[0]]
    # 1. 괄호 먼저 계산하기
    for i in range(1,N,2):
        if i in bracket: # 괄호에 들어가면 num[i-1], num[i+1]계산
            temp.pop() # 중복 제거
            if num[i] == '+':
                temp.append(num[i-1] + num[i+1])
            elif num[i] == '-':
                temp.append(num[i-1] - num[i+1])
            else:
                temp.append(num[i-1]*num[i+1])
        else: # 괄호에 안 들어가면 temp에 그대로 넣기
            temp.append(num[i])
            temp.append(num[i+1])
    return cal_Seq(temp)


def dfs(start, cnt):
    global ans
    if len(bracket) == cnt:
        ans = max(ans, cal_bracket())
        return

    for i in range(start+2, N, 2):
        if i-2 == bracket[-1]: continue # 괄호가 겹치면 continue
        bracket.append(i)
        dfs(i, cnt)
        bracket.pop()


def solution(N, string):
    global num, oper
    for s in string:
        if s.isdigit():
            num.append(int(s))
        else:
            num.append(s)

    if len(num)==1:
        print(num[0])
        return

    for k in range(1, N // 2 + 1):
        for i in range(1, N, 2):
            bracket.append(i)
            dfs(i, k)
            bracket.pop()
    print(ans)
    return


N = int(input().strip())
string = input().strip()

ans = -2^31
num = []
oper = []
bracket = deque() # 괄호 안에 들어가는 연산자의 인덱스

solution(N, string)
