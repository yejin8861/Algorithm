def solution(N, stages):
    stage = [0]*(N+2)
    for n in stages:
        stage[n] += 1
    total = len(stages)
    failure = []
    for i in range(1, N+1):
        if total > 0:
            failure.append((stage[i]/total, i))
        else:
            failure.append((0,i))
        total -= stage[i]
    answer = [idx for fail, idx in sorted(failure, key=lambda x:x[0], reverse=True)]
    print(answer)
    return answer

if __name__ == '__main__':
    solution(4, [3,3,3])