# map[x][y][2] : map[x][y][0] = (0:기둥 X, 1이상:기둥 O), map[x][y][1] = (0:보X, 1이상:보O)
map = [[[0 for _ in range(102)] for _ in range(102)] for _ in range(2)]

def is_possible(x,y,a):
    if a==0: # 기둥을 설치할 수 있는 경우 (바닥 위 or 보의 한쪽 끝 위 or 다른 기둥 위)
        if y == 0 or map[1][x][y] == 1 or map[0][x][y] == 1:
            return True
        else:
            return False
    else: # 보를 설치할 수 있는 경우 (한쪽 끝 부분이 기둥 위 or 양쪽 끝이 다른 보와 연결)
        if map[0][x][y] == 1 or map[0][x + 1][y] == 1 or (map[1][x][y] and map[1][x + 1][y]):
            return True
        else:
            return False

def is_removable(x,y,a):
    if a==0:
        for nx, ny in [(x-1, y), (x, y)]:
            # 기둥 좌우의 보를 삭제하고 다시 세울 때 가능한지 확인
            map[1][nx][ny] -= 1; map[1][nx+1][ny] -= 1
            if not is_possible(nx, ny, 1):
                map[1][nx][ny] += 1; map[1][nx+1][ny] += 1
                return False
            map[1][nx][ny] += 1; map[1][nx+1][ny] += 1
        return True
    else:
        # 양 옆 보 확인
        for nx, ny in [(x-1, y),(x+1,y)]:
            map[1][nx][ny] -= 1; map[1][nx+1][y] -= 1
            if not is_possible(nx, ny, 0):
                map[1][nx][ny] += 1; map[1][nx+1][ny] += 1
                return False
            map[1][nx][ny] += 1; map[1][nx+1][ny] += 1
        map[1][nx][ny] -= 1; map[1][nx+1][ny] -= 1

        # 자기 위에 있는 기둥 확인
        for nx, ny in [(x, y), (x+1, y)]:
            map[0][nx][ny] -= 1; map[0][nx][ny+1] -= 1
            if is_possible(nx, ny, 0) == False:
                map[0][nx][ny] += 1; map[0][nx][ny+1] += 1
                return False
            map[0][nx][ny] += 1; map[0][nx][ny+1] += 1
        return True

def solution(n, build_frame):
    answer = []
    # build_frame[x,y,a,b] : (x,y), a=(0:기둥 1:보), b=(0:삭제 1:설치)
    for x,y,a,b in build_frame:
        # 1. 기둥인 경우
        if a == 0:
            if b == 1: # 기둥을 설치할 수 있는 경우
                if is_possible(x,y,a):
                    map[0][x][y] += 1
                    map[0][x][y+1] += 1
                    answer.append([x,y,0])
            else: # 기둥을 삭제할 수 있는 경우
                # 기둥 삭제
                map[0][x][y]-=1; map[0][x][y+1]-=1
                if is_removable(x,y,0):
                    answer.remove([x,y,0])
                else:
                    map[0][x][y] += 1; map[0][x][y + 1] += 1 # 기둥 복구
        else: # 2. 보인 경우
            if b == 1: # 보를 설치할 수 있는 경우
                if is_possible(x,y,a):
                    map[1][x][y] += 1
                    map[1][x+1][y] += 1
                    answer.append([x,y,1])
            else: # 보를 삭제할 수 있는 경우
                # 보 삭제
                map[1][x][y] -=1; map[1][x+1][y]-=1
                if is_removable(x,y,1):
                    answer.remove([x,y,1])
                else:
                    map[1][x][y] += 1; map[1][x+1][y] += 1  # 보 복구


    print(sorted(answer, key=lambda x:(x[0],x[1],x[2])))
    return sorted(answer, key=lambda x:(x[0],x[1],x[2]))

if __name__ == '__main__':
    solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]])