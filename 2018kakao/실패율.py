import operator

def solution(N, stages):
    answer = []
    failure = {}
    for n in range(N):
        failure[n+1] = 0

    for s in stages:
        if s == N+1:
            continue
        failure[s] += 1
    sum = 0
    for key, value in failure.items():
        try:
            failure[key] = value / (len(stages) - sum)
        except ZeroDivisionError:
            pass
        sum += value
    failure = sorted(failure.items(), key=operator.itemgetter(1), reverse=True)
    print(failure)
    for n in failure:
        answer.append(n[0])
    print(answer)

    return answer

if __name__ == '__main__':
    solution(5,[2, 1, 2, 6, 2, 4, 3, 3])
    #solution(4,[4,4,4,4,4])