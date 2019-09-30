def solution(N):
    answer = 0
    tile = []
    tile.append(1)
    tile.append(1)
    for i in range(2,N+1):
        tile.append(tile[i-2]+tile[i-1])

    answer = tile[N-1]*2 + tile[N]*2
    print(answer)
    return answer

if __name__ == '__main__':
    solution(6)