stack = []

def perform_option(c):
    if c == '*':
        if len(stack) >= 2:
            second = stack.pop()
            first = stack.pop()
            stack.append(first * 2)
            stack.append(second * 2)
        else:
            first = stack.pop()
            stack.append(first * 2)
    else:
        first = stack.pop()
        stack.append(-first)
    return


def solution(dartResult):
    num = ''
    bonus = {'S': 1, 'D': 2, 'T': 3}
    for c in dartResult:
        # bonus가 나오면 스택에 숫자 넣음
        if c in ['S', 'D', 'T']:
            stack.append(int(num) ** bonus[c])
            num = ''
        elif c in ['*', '#']:
            perform_option(c)
        else:
            num += c

    answer = 0
    # 점수 합 구하기
    for n in stack:
        answer += n

    # print(answer)
    return answer

if __name__ == '__main__':
    solution("1D2S3T*")