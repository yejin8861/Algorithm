import math

def solution(prince_X, prince_Y, princess_X, princess_Y):
    x_time = 1000001
    y_time = 1000001
    if prince_Y[0] == princess_Y[0] or prince_X[0] == princess_X[0]:  # 바로 메세지 보내기 가능
        return 1

    prince_X_max, prince_X_min = max(prince_X), min(prince_X)
    princess_X_max, princess_X_min = max(princess_X), min(princess_X)
    prince_Y_max, prince_Y_min = max(prince_Y), min(prince_Y)
    princess_Y_max, princess_Y_min = max(princess_Y), min(princess_Y)
    # print(prince_X_min, prince_X_max, princess_X_min,princess_X_max)


    # x좌표 중에 교차 되는 점이 있는지 확인
    if prince_X[0] > princess_X[0]: # 왕자의 시작 위치가 오른쪽에 있을 때
        if princess_X_max <= prince_X_min:
            for i in range(len(prince_X)):
                if prince_X[i] <= princess_X[i]: # 교차되는 구간
                    break
            x_time = i + math.ceil(abs(prince_X[i] - prince_X[i-1])//2) + 1
    else:
        if princess_X_min <= prince_X_max:
            for i in range(len(prince_X)):
                if prince_X[i] >= princess_X[i]:  # 교차되는 구간
                    break
            x_time = i + math.ceil(abs(prince_X[i] - prince_X[i - 1]) // 2) + 1

    # y좌표 중에 교차 되는 점이 있는지 확인
    if prince_Y[0] > princess_Y[0]: # 왕자의 시작 위치가 위에 있을 때
        if prince_Y_min <= princess_Y_max:
            for i in range(len(prince_Y)):
                if prince_Y[i] <= princess_Y[i]: # 교차되는 구간
                    break
            y_time = i + math.ceil(abs(prince_Y[i] - prince_Y[i-1])//2) + 1
    else: # 왕자의 시작 위치가 아래에 있을 때
        if princess_Y_min <= prince_Y_max:
            for i in range(len(prince_Y)):
                if prince_Y[i] >= princess_Y[i]: # 교차되는 구간
                    break
            y_time = i + math.ceil(abs(prince_Y[i] - prince_Y[i-1])//2) + 1

    if x_time == 1000001 and y_time == 1000001:
        return -1

    # print(x_time, y_time)
    return min(x_time, y_time)


T= int(input())
for k in range(T):
    N = int(input())
    prince_X = []
    prince_Y = []
    princess_X = []
    princess_Y = []
    for _ in range(N+1):
        x, y = list(map(int, input().strip().split()))
        prince_X.append(x)
        prince_Y.append(y)
    for _ in range(N + 1):
        x, y = list(map(int, input().strip().split()))
        princess_X.append(x)
        princess_Y.append(y)
    time = solution(prince_X, prince_Y, princess_X,princess_Y)
    print('#%d'%(k+1), time)