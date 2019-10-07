from collections import defaultdict

def solution(clothes):
    clothes_dict = defaultdict(list)
    # create dictionary
    for name, type in clothes:
        print(name, type)
        clothes_dict[type].append(name)
    print(clothes_dict)

    # count numbers each cloth type
    answer = 1
    for value in clothes_dict.values():
        answer *= (len(value) + 1)
    print(answer-1)
    return answer-1


if __name__ == '__main__':
    solution([['yellow_hat', 'headgear'], ['blue_sunglasses', 'eyewear'], ['green_turban', 'headgear']])
    # solution([['crow_mask', 'face'], ['blue_sunglasses', 'face'], ['smoky_makeup', 'face']])