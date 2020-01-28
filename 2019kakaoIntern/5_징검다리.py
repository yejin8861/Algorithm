
def solution(stones, k):
    MAX_DIST = 0
    flag = 0
    answer = 0
    while True:
        dist = 0
        print(stones)
        # 건널 수 있는지 검사
        for i in range(len(stones) - 1):
            if stones[i+1] == 0: # 다음 칸이 0이면
                dist += 1
                flag = 1
            else:
                if flag:
                    if MAX_DIST < dist:
                        MAX_DIST = dist
                        print('MAX',MAX_DIST)
                        if MAX_DIST > k:
                            print(answer)
                            return answer
                        flag = 0
        # 한 개씩 줄이기
        for i in range(len(stones)):
            if stones[i] != 0:
                stones[i] -= 1
        answer += 1


if __name__ == '__main__':
    solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1],3)