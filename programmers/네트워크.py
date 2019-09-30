
def DFS(graph, root):
    cnt = 0
    while True:
        stack = [root]
        visited = []
        while stack:
            n = stack.pop()
            if n not in visited:
                visited.append(n)
                stack += graph[n] - set(visited)
        visited = set(visited)
        for node in visited:
            del graph[node]
        cnt += 1
        print(graph)
        if graph:
            root = list(graph.keys())[0]
            print(root)
        else:
            return cnt


def solution(n, computers):
    graph = {}
    for i in range(n):
        graph[i+1] = set()

    print(graph)
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1 and i != j:
                graph[i+1] = {j+1} | graph[i+1]

    print(graph)
    answer = DFS(graph, 1)
    print('answer',answer)

if __name__ == '__main__':
    # solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]])
    solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]])