def check(result):
    for x,y,a in result:
        if a == 0: # 기둥을 설치할 수 있는 경우 (바닥 위 or 보의 한쪽 끝 위 or 다른 기둥 위)
            if y==0 or (x-1,y,1) in result or (x,y,1) in result or (x,y-1,0) in result:
                continue
            else:
                return False
        else: # 보를 설치할 수 있는 경우 (한쪽 끝 부분이 기둥 위 or 양쪽 끝이 다른 보와 연결)
            if (x,y-1,0) in result or (x+1,y-1,0) in result or ((x-1,y,1) in result and (x+1,y,1) in result):
                continue
            else:
                return False
    return True

def solution(n, build_frame):
    result = set()
    for x,y,a,b in build_frame:
        if b == 1: # 설치
            result.add((x,y,a))
            if check(result):
                continue
            else:
                result.remove((x,y,a))
        else: # 삭제
            result.remove((x,y,a))
            if check(result):
                continue
            else:
                result.add((x,y,a))

    result = [list(t) for t in result]
    print(sorted(result, key=lambda x:(x[0],x[1],x[2])))
    return sorted(result, key=lambda x:(x[0],x[1],x[2]))


if __name__ == '__main__':
    solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]])
