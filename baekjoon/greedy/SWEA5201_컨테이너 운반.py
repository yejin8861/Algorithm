
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, M = map(int, input().strip().split())
    container = sorted(list(map(int, input().strip().split())), reverse=True)
    truck = sorted(list(map(int, input().strip().split())), reverse=True)

    weight = 0
    i = j = 0
    while True:
        if i == len(container) or j == len(truck):
            break
        if container[i] <= truck[j]:
            weight += container[i]
            j += 1
        i += 1
    print('#%d'%test_case, weight)
