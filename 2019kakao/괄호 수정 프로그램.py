def isbalance(u):
    a = u.count('(')
    b = u.count(')')
    if a == b:
        return True
    else:
        return False

def isRight(u):
    stack = []
    for s in u:
        if s == '(':
            stack.append(s)
        else:
            if len(stack) == 0:
                return False
            else:
                stack.pop(-1)
    if len(stack) == 0:
        return True
    else:
        return False

result = ""
def procedure(p):
    global result
    u = ""
    if len(p) == 0:
        return ""
    for i, s in enumerate(p):
        u += s
        if isbalance(u):
            print('u',u)
            if isRight(u):
                #result += u
                v = p[i+1:]
                print('v',v)
                v = procedure(v)
                return u + v
            else:
                v = p[i+1:]
                print('v',v)
                v = procedure(v)
                v = "(" + v + ")"
                # print('return',v)
                u = u[1:len(u)-1] # 앞뒤문자 제거
                # print(u)
                #괄호 방향 뒤집
                ret = ""
                for j in range(len(u)):
                    if u[j] == '(':
                        ret += ')'
                    else:
                        ret += '('
                # print(ret)
                ret = v + ret
                return ret


def solution(p):
    answer = procedure(p)
    print(answer)


if __name__ == '__main__':
    solution("()))((()")
    #solution("(()())()")