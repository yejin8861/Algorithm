import sys
from collections import Counter

def is_Palindrome(string):
    N = len(string)
    if N%2 and string[:N // 2] == string[N//2+1:][::-1]:  # string이 홀수일 때
        return 0
    elif N%2==0 and string[:N // 2] == string[N//2:][::-1]:
        return 0
    else:
        return 2


if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())

    for _ in range(N):
        string = sys.stdin.readline().strip()
        if is_Palindrome(string) == 2:
            flag = 0
            s_dict = Counter(string)
            odd_list = [key for key in s_dict.keys() if s_dict.get(key) % 2]
            for s in odd_list:
                idx = [i for i in range(len(string)) if string[i] == s]
                for i in idx:
                    new_string = string[:i] + string[i + 1:]
                    if is_Palindrome(new_string) == 0:
                        print(1)
                        flag = 1
                        break
                if flag:
                    break
            if flag == 0:
                print(2)
        else:
            print(0)