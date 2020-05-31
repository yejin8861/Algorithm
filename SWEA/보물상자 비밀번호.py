def simulation(s, N, K):
    result = set()
    l = len(s)//4
    for _ in range(l+1):
        for i in range(4):
            result.add(int(s[i*l:(i+1)*l], 16))
        end = s[-1]
        s = end + s[:-1]
    return sorted(list(result), reverse=True)[K-1]


T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, K = map(int, input().strip().split())
    print('#%d'%test_case,'%d'%simulation(input(), N, K))