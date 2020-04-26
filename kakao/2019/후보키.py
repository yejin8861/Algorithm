from itertools import combinations

def solution(relation):
    answer = 0
    R, C = len(relation), len(relation[0])
    n = [i for i in range(C)]
    keys = []
    for i in range(1, C+1):
        keys.extend(combinations(n, i))

    while keys:
        key = keys.pop(0)
        # 후보 키인지 확인
        temp = [tuple(row[i] for i in key) for row in relation]
        if len(set(temp)) == R: # 후보 키이면 키 집합에서 현재 키 포함하는 키 제거
            answer += 1
            extra = [k for k in keys if set(key) <= set(k)]
            keys = list(set(keys) - set(extra))
            # keys 갯수 오름차순 정렬
            keys = sorted(keys, key=lambda x: len(x))
    print(answer)
    return answer

if __name__ == '__main__':
    solution([["100","ryan","music","2"],
              ["200","apeach","math","2"],
              ["300","tube","computer","3"],
              ["400","con","computer","4"],
              ["500","muzi","music","3"],
              ["600","apeach","music","2"]])