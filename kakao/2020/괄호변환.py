def separate(string):
    cnt = 0
    for i,s in enumerate(string):
        if s is '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt == 0:
            return string[:i+1], string[i+1:]

def is_right(string):
    cnt = 0
    for s in string:
        if s is '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            return False
    return cnt == 0

def recursion(string):
    if string == '':  # 1. 빈 문자열이면 반환
        return ''
    u, v = separate(string) # 2. u(균형잡힌 문자열), v로 분리
    if is_right(u): # 3. u가 올바른 문자열이면
        u += recursion(v)
        return u
    else: # 4. u가 올바른 문자열이 아니면
        ret = '('
        ret += recursion(v) + ')'
        u = u[1:-1]
        for c in u:
            if c is '(':
                ret += ')'
            else:
                ret += '('
        return ret

def solution(p):
    if p == '':
        return ''
    answer = recursion(p)
    print(answer)
    return answer

if __name__ == '__main__':
    solution("()))((()")