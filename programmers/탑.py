def solution(heights):
    answer = []
    for i, height in enumerate(heights):
        for j in range(i-1,-1,-1):
            if heights[j] > height:
                answer.append(j+1)
                break
        else:
            answer.append(0)
    return answer
