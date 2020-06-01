def bfs():
    possible = []
    visited = [[0]*N for _ in range(N)]
    y, x, s = shark
    q = [(y,x)]
    visited[y][x]=1

    dist=0
    flag = False
    while q:
        size = len(q)
        for _ in range(size):
            y, x = q.pop(0)
            for dy, dx in [(-1,0),(1,0),(0,-1),(0,1)]:
                ny, nx = y+dy, x+dx
                if ny<0 or ny>=N or nx<0 or nx>=N or visited[ny][nx] or board[ny][nx]>s: continue

                if 0 < board[ny][nx] < s: # 먹을 수 있는 물고기
                    possible.append((ny,nx))
                    flag = True
                visited[ny][nx]=1
                q.append((ny,nx))
        dist += 1
        if flag:
            break
    return possible, dist

def simulation():
    global eaten, time
    possible, dist = bfs()
    if len(possible) == 0:
        return False
    else: # 물고기를 먹을 수 있다면
        y,x = sorted(possible, key=lambda x:(x[0],x[1]))[0]
        fish.remove((y,x,board[y][x]))
        board[y][x] = 0
        time += dist
        shark[0], shark[1] = y,x
        eaten += 1
        if eaten == shark[2]:
            shark[2] += 1
            eaten = 0
        return True

N = int(input())
board = [[0]*N for _ in range(N)]
fish, shark = [], []
eaten = 0
for i in range(N):
    for j, n in enumerate(map(int,input().split())):
        if 0 < n < 9:
            fish.append((i,j,n))
            board[i][j] = n
        elif n == 9:
            shark = [i,j,2]

time = 0
while fish:
    if not simulation():
        break
print(time)