from collections import deque

queue = deque([{'hit'}, 0])
n = queue.popleft()
s = queue.popleft()
print(n,s)