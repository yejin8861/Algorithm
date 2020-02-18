
from itertools import chain, combinations

def powerset(s):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    #s = list(iterable)
    #return list(combinations(s,r) for r in range(1,len(s)+1))
    return chain.from_iterable(combinations(s, r) for r in range(1,len(s)+1))

def solution(relation):
    result = 0
    n_row = len(relation)
    n_col = len(relation[0])
    meta = []

    combination = list(range(n_col))
    print(combination)
    keys = list(powerset(combination))
    print(keys)

    while len(keys) > 0:
        print('keys', keys)
        min_lengh = 999
        for key in keys:
            if len(key) < min_lengh:
                min_lengh = len(key)
                k = key
        temp = [tuple(row[i] for i in k) for row in relation]
        print(temp)
        print('key',k)
        if len(set(temp)) == n_row:
            result += 1
            extra = [i for i in keys if set(k) <= set(i)]
            print('e',extra)
            before = len(keys)
            keys = list(set(keys) - set(extra))
            print('k',keys)
        else:
            keys.remove(k)
    print(result)



if __name__ == '__main__':
    solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]])
    #solution([["100"]])