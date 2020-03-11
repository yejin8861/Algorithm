num = {10: 'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'}

def convert(n, i):
    # i를 n진수로 변경
    s = ''
    while i > 0:
        mod = i % n
        if 0 <= mod < 10:
            s = str(mod) + s
        elif 10 <= mod:
            s = num[mod] + s
        i = i//n
    return s

def solution(n, t, m, p):
    string = '0'
    for i in range(t*m):
        string += convert(n, i)
        if len(string) > t*m:
            break

    answer = ''
    for i in range(len(string)):
        if len(answer) == t:
            # print(answer)
            return answer
        if p == i % m + 1:
            answer += string[i]

if __name__ == '__main__':
    # solution(2,4,2,1)
    # solution(16, 16, 2, 1)
    solution(16,1000,100,100)