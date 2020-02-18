# 괄호 검사 알고리즘
# 문자열에 있는 괄호를 차례대로 조사
# 왼쪽 괄호를 만나면 push, 오른쪽 괄호를 만나면 pop한 뒤 짝이 맞는지 확인
# 1. 스택이 비어있음, 2. 괄호의 짝이 맞지 않음, 3. 문자열 끝까지 조사한 후에도 스택에 괄호가 남아있음

v = []
result = ""
def pop(s):
    global v
    global result
    if len(s) == 0:
        v.append(')')
        result += '('
        return
    else:
        result += ')'
        return s.pop(-1)

def solution(p):
    global v
    global result
    if len(p) == 0:
        return ""
    s = []
    print(p)
    for i in range(len(p)):
        if p[i] == '(':
            if len(v) > 0:
                v.pop()
                result += ')'
            else:
                s.append(p[i])
                result += '('
        elif p[i] == ')':
            pop(s)
        else:
            pass

    print(result)
    return result
if __name__ == '__main__':
    #solution("()))((()")
    #solution(")(")
    #solution("(()())()")
    solution("))(())((")