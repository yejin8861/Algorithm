from collections import Counter

def operation():
    size = 0
    ret = []
    for r in range(len(A)):
        new = []
        temp = sorted(Counter(A[r]).items(), key=lambda x:(x[1],x[0]))
        for a,b in temp:
            if a == 0: continue
            new.append(a)
            new.append(b)
        ret.append(new)
        size = max(size, len(new))

    # 가장 긴 행 길이에 맞춰 0 붙이기
    for r in range(len(ret)):
        ret[r] += [0]*(size - len(ret[r]))
    return ret

def simulation():
    global A
    # R연산
    if len(A) >= len(A[0]):
        A = operation()
    # C연산
    else:
        A = list(zip(*A))
        A = list(zip(*operation()))
    return

R,C,K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(3)]
time = 0
while True:
    if time > 100:
        time = -1
        break
    if R-1 < len(A) and C-1 < len(A[0]):
        if A[R-1][C-1]==K:
            break
    simulation()
    time += 1
print(time)