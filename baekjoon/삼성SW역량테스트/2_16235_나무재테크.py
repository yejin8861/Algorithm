from collections import deque

def simulation(tree):
    # 봄: 나이만큼 양분을 먹고 나이 1 증가
    alive = deque()
    dead = []
    spread = []
    while tree:
        x, y, age = tree.popleft()
        if ground[x][y] < age:
            dead.append((x,y,age))
        else:
            ground[x][y] -= age
            alive.append((x,y,age+1))
            if (age+1)%5 == 0: # 가을에 번식할 나무
                spread.append((x,y))

    # 여름 : 죽은 나무가 양분으로 변한다.
    while dead:
        x, y, age = dead.pop(0)
        ground[x][y] += age//2

    # 가을 : 나이가 5인 나무의 번식, 인접한 8개의 칸에 나이가 1인 나무 생성
    while spread:
        x,y = spread.pop(0)
        for dx in [-1,0,1]:
            for dy in [-1,0,1]:
                if dx==0 and dy==0: continue
                nx, ny = x + dx, y + dy
                if nx<1 or nx>N or ny<1 or ny>N: continue
                alive.appendleft((nx,ny,1))

    # 겨울: 양분 추가
    for i in range(1,N+1):
        for j in range(1,N+1):
            ground[i][j] += A[i][j]

    return alive # 다음에 자랄 나무들


N, M, K = map(int, input().strip().split())
ground = [[5]*(N+1) for _ in range(N+1)]
tree = deque()
A = [0]
for i in range(1, N+1):
    A.append([0] + list(map(int, input().split())))
for i in range(M):
    x,y,z = map(int, input().strip().split())
    tree.append((x,y,z))

tree = deque(sorted(tree, key=lambda x: x[2]))  # 나이순 정렬

while K:
    tree = simulation(tree)
    K -= 1
print(len(tree))