from collections import defaultdict, deque
def BFS(num, network):
    computers = list(range(num))
    visited = []
    queue = deque(network[0])
    cnt = 0
    while True:
        while queue:
            n = queue.popleft()
            if n not in visited:
                visited.append(n)
                queue += network[n] - set(visited)
        cnt += 1
        # 들리지 않은 computer 집합
        computers = set(computers) - set(visited)
        if computers: # 남은 computer가 있으면 다시 queue에 넣고 반복
            n = computers.pop()
            queue = deque(network[n])
            visited = []
        else: # 남은 computer가 없으면 return.
            return cnt

def solution(n, computers):
    network = defaultdict(set)
    for idx, computer in enumerate(computers):
        for i in range(n):
            if computer[i]:
                network[idx] |= {i}

    return BFS(n, network)



if __name__ == '__main__':
    # solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]])
    # solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]])
    solution(1, [[1]])