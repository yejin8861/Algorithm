

def Is_triplet(numbers):
    return True if 3 in numbers else False

def Is_run(numbers):
    card = [i for i in range(len(numbers)) if numbers[i] > 0]
    for i in range(2,len(card)):
        if card[i] - card[i-2] == 2:
            return True
    return False

def who_Is_Winner(first, second):
    # 플레이어1이 이기는 경우
    if (Is_triplet(first) or Is_run(first)) and (not (Is_triplet(second)) and not (Is_run(second))):
        return 1
    # 플레이어2가 이기는 경우
    elif (Is_triplet(second) or Is_run(second)) and (not (Is_triplet(first)) and not (Is_run(first))):
        return 2
    else:
        return 0


T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    number = list(map(int, input().split()))
    first = [0]*10
    second = [0]*10
    winner = 0
    for i in range(len(number)):
        if i > 5:
            winner = who_Is_Winner(first, second)
            if winner > 0:
                break
        if i % 2:
            second[number[i]] += 1
        else:
            first[number[i]] += 1
    winner = who_Is_Winner(first, second)
    print('#%d'%test_case, winner)