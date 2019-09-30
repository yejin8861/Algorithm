def solution(s):
    strings = []
    result = ""
    print(len(s)//2+1)
    for idx in range(1,len(s)//2+2):
        cnt = 1
        for i in range(len(s)):
            if idx*(i+1) >= len(s):
                temp = s[idx * i:]
                print('last',temp)
                if cnt == 1:
                    result += temp
                else:
                    result += str(cnt) + temp
                break
            temp = s[idx*i:idx*(i+1)]
            print(temp)
            print(s[idx*(i+1):idx*(i+2)])
            print(idx*(i+2))
            if temp != s[idx*(i+1):idx*(i+2)]:
                if cnt == 1:
                    result += temp
                else:
                    result += str(cnt)+temp
                cnt = 1
            else:
                cnt += 1
        #result = result.replace("1","")
        strings.append(result)
        result = ""
    answer = []
    print(strings)
    for string in strings:
        answer.append(len(string))
    print(answer)
    print(min(answer))
    return min(answer)

if __name__ == '__main__':
    #solution("abcabcabcabcdededededede")
    #solution("xxababcdcdababcdcd")
    solution("ababcdcdababcdcd")
    #solution("aa")