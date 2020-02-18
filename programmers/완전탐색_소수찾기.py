from itertools import permutations
def make_perm(n, numbers):
    string = []
    perms = permutations(numbers, n)
    for perm in perms:
        string.append("".join([str(perm[i]) for i in range(len(perm))]))
    return list(map(int, string))  # 문자열 순열을 int형으로 변환

def is_prime(num):
    for i in range(2, int(num**0.5)+1):  # 루트 num까지만 비교, 그 이상의 케이스는 중복.
        if num % i == 0:
            return False
    return True


def solution(numbers):
    answer = 0
    numbers = list(map(int, numbers))  # string을 int로 변환

    # 조합 가능한 모든 순열 생성 #
    perms = []
    for i in range(len(numbers)):
        perms.extend(make_perm(i+1, numbers))
    perms = set(perms)  # 중복제거

    # 소수 판별 #
    for num in perms:
        if num > 1:  # 소수가 될 수 없는 0, 1 제거
            if is_prime(num):
                answer += 1
        else:
            continue

    print(answer)
    return answer


if __name__ == '__main__':
    solution("17")
    # solution("100110")