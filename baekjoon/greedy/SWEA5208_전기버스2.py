T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    station = list(map(int, input().strip().split()))
    N = station.pop(0)
    prev_idx = 0
    battery = station[0]
    cnt = 0
    while True:
        max_battery = 0
        if prev_idx + battery >= N-1:
            break
        for j in range(prev_idx+1, prev_idx+1+battery):
            if station[j] >= max_battery:
                max_battery = station[j]
                next_idx = j
        cnt += 1
        battery = max_battery
        prev_idx = next_idx
    print('#%d'%test_case, cnt)