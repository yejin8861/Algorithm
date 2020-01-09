import sys
N = int(sys.stdin.readline().strip())

sticks = []
for _ in range(N):
    h = int(sys.stdin.readline().strip())
    sticks.append(h)
MAX = max(sticks)
current = sticks.pop()
cnt = 0
for i in range(N-2,-1, -1):
    if sticks[i] > current:
        cnt += 1
        print('cnt',cnt)
        if sticks[i] == MAX:
            break
        current = sticks[i]
print(cnt+1)