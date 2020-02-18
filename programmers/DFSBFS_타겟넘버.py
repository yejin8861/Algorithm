def recursive(numbers, idx, SUM, target):
    if len(numbers) == idx: # 마지막 숫자까지 돌았을 때 sum이 target과 같으면 return 1, 아니면 0
        return 1 if SUM == target else 0
    # SUM에 다음 숫자를 더한 값과 뺀 값으로 재귀
    return recursive(numbers, idx + 1, SUM + numbers[idx], target) + recursive(numbers, idx + 1, SUM - numbers[idx], target)


def solution(numbers, target):
    return recursive(numbers, 1, numbers[0], target) + recursive(numbers, 1, -numbers[0], target)

if __name__ == '__main__':
    # solution([0,1,2,3,4,5], 5)
    solution([1,1,1,1,1], 3)