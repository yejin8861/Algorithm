import heapq as hq

def solution(scoville, K):
    cnt = 0
    hq.heapify(scoville)
    if scoville[0] >= K:  # 이미 모든 음식의 스코빌 지수가 K 이상일 때
        return 0
    else:
        while True:
            if scoville[0] >= K:  # 최소 스코빌 지수가 K 이상일 때
                print(cnt)
                return cnt
            if len(scoville) < 2:  # 남은 음식 수가 하나인데 K미만이므로 -1.
                return -1
            first = hq.heappop(scoville)
            second = hq.heappop(scoville)
            hq.heappush(scoville, first + second*2)
            cnt += 1

if __name__ == '__main__':
    solution([1, 2, 3, 9, 10, 12], 7)