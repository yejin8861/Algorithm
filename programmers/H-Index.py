def solution(citations):
    citations.sort(reverse=True)
    print(citations)
    for i in range(len(citations), 0, -1):
        cnt = 0
        for j in range(len(citations)):
            if citations[j] >= i:
                cnt += 1
                if len(citations) == cnt: # 전부 i번 이상 인용되었을 때, H-Index=i
                    return i
            else: # i보다 적게 인용된것만 남았을 때
                if cnt >= i:
                    # i번 이상 인용된 논문이 i편 이상이고
                    # 남아있는 논문이 i번 이하로 인용되었으면
                    return i # i는 H-Index
                else: # i번 이상 인용된 논문이 i 미만이면 break.
                    break
    return cnt


if __name__ == '__main__':
    # solution([3, 0, 6, 1, 5])
    # solution([2])
    solution([4,3,3,3])