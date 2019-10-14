from itertools import permutations
def solution(baseball):
    perms = set(permutations([1,2,3,4,5,6,7,8,9], 3))
    print(perms)
    for number, strike, ball in baseball:
        number = list(map(int, str(number)))
        if strike == 0:
            # 전부 자리는 맞지 않지만 볼의 숫자만큼 같은 개수의 숫자가 있는 경우
            perms &= {perm for perm in perms if len(set(perm) & set(number)) == ball
                      and perm[0] != number[0] and perm[1] != number[1] and perm[2] != number[2]}
            # print(len(perms))
        elif strike == 1:
            temp = []
            for i in range(3):
                for perm in perms:
                    # 한 자리만 숫자와 자리가 맞고 나머지는 자리는 맞지 않지만 숫자는 일치하는 경우
                    if perm[i] == number[i] and perm[(i+1)%3] != number[(i+1)%3] \
                            and perm[(i+2)%3] != number[(i+2)%3] \
                            and len((set(perm) - {perm[i]}) & (set(number) - {number[i]})) == ball:
                        temp.append(perm)
            perms &= set(temp)
        elif strike == 2:
            temp = []
            # 두 자리의 숫자가 같고 하나의 숫자는 달라야 함. -> 2S 1B은 존재하지 않음. 무조건 2S 0B
            for perm in perms:
                # 1,2자리 같을 경우
                if perm[0] == number[0] and perm[1] == number[1] and perm[2] != number[2]:
                    # print('1',perm)
                    temp.append(perm)
                # 2,3자리 같을 경우
                elif perm[1] == number[1] and perm[2] == number[2] and  perm[0] != number[0]:
                    temp.append(perm)
                # 1,3자리 같을 경우
                elif perm[0] == number[0] and perm[2] == number[2] and perm[1] != number[1]:
                    temp.append(perm)
            perms &= set(temp)
            # print(perms)
        else:
            return 1
    return len(perms)

if __name__ == '__main__':
    solution([[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]])