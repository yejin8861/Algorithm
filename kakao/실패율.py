def solution(N, stages):
    answer = []
    user = [0]*(N+1)
    fail = []
    for stage in stages:
        user[stage-1] += 1
    #print(user)
    for i in range(N):
        be = sum(user[i:])
        yet = user[i]
        if be != 0:
            fail.append((i+1, yet/be))
        else:
            fail.append((i+1, 0))
    #print(fail)
    for item in sorted(fail, key=lambda x:x[1], reverse=True):
        answer.append(item[0])
    #print(answer)
    return answer

if __name__ == '__main__':
    solution(5, [2, 1, 2, 6, 2, 4, 3, 3])