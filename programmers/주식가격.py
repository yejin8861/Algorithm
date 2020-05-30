def solution(prices):
    answer = []
    for i in range(len(prices)):
        cnt = 0
        for j in range(i+1, len(prices)):
            if prices[i] > prices[j]:
                answer.append(cnt+1)
                break
            cnt += 1
        else:
            answer.append(cnt)
    return answer

if __name__ == '__main__':
    solution([1,2,3,2,3])