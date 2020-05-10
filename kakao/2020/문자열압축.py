def solution(s):
    answer = len(s)
    for l in range(1, len(s) // 2 + 1):
        sum = 0
        cnt = 1
        for i in range(0, len(s), l): # l길이씩 문자열 비교
            if s[i:i+l] == s[i+l:i+2*l]:
                cnt += 1
            else:
                if cnt == 1:
                    sum += len(s[i:i+l])
                else:
                    sum += len(str(cnt)) + len(s[i:i+l])
                cnt = 1
        answer = min(answer, sum)
    print(answer)
    return answer


if __name__ == '__main__':
    solution("aabbaccc")
    # solution("ababcdcdababcdcd")
    # solution("abcabcdede")
