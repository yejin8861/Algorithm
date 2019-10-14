def solution(answers):
    answer = [0,0,0]
    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]

    for i in range(1, len(answers)+1):
        if answers[i-1] == first[i%len(first)-1]: # 1번 수포자가 맞혔으면
            answer[0] += 1
        if answers[i-1] == second[i%len(second)-1]: # 2번 수포자가 맞혔으면
            answer[1] += 1
        if answers[i-1] == third[i%len(third) - 1]:  # 3번 수포자가 맞혔으면
            answer[2] += 1

    MAX = max(answer)
    # 최대 정답수와 같은 수포자 리스트
    result = [i+1 for i in range(len(answer)) if answer[i] == MAX]
    return sorted(result)

if __name__ == '__main__':
    # solution([1,2,3,4,5])
    solution([1,3,2,4,2])