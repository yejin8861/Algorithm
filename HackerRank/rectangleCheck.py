
def solution(v):
    answer = []
    X = [x[0] for x in v]
    Y = [y[1] for y in v]
    for i in range(len(X)):
        if X.count(X[i])==1:
            answer.append(X[i])
            break
    for j in range(len(Y)):
        if Y.count(Y[j])==1:
            answer.append(Y[j])
            break
    return answer


solution([[1, 4], [3, 4], [3, 10]])