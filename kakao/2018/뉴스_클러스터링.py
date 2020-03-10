from collections import defaultdict
from itertools import chain

def make_dict(str):
    dic = defaultdict(int)
    for i in range(len(str)-1):
        # 공백, 숫자, 특수문자가 들어있는 경우 버린다.
        if str[i].isalpha() is False or str[i+1].isalpha() is False:
            continue
        dic[str[i]+str[i+1]] += 1
    return dic

def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    dict1 = make_dict(str1)
    dict2 = make_dict(str2)

    # 1. 합집합 구하기
    union = defaultdict(list)
    for key, value in chain(dict1.items(), dict2.items()):
        union[key].append(value)

    # 2. 합집합, 교집합 개수 구하기
    uni = 0
    inter = 0
    for key, value in union.items():
        uni += max(value)
        if len(value)>1:
            inter += min(value)  # 교집합 개수 중 제일 작은 값

    # 자카드 유사도 * 65536
    if uni == 0: return 65536
    else : return int(inter/uni*65536)