
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    work = []
    for _ in range(N):
        s,e = map(int, input().split())
        work.append((s,e))

    work = sorted(work, key=lambda x:(x[1])) # 종료시간이 빠른 순으로 정렬
    time = 0
    cnt = 0
    for start, end in work:
        if start >= time: # 종료 시간이 시작 시간 이하이면
            time = end
            cnt += 1
    print('#%d'%test_case, cnt)


