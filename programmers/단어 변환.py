from collections import deque, defaultdict
def func(level):
    return level + 1

def BFS(graph, begin, target):
    queue = deque()
    queue.append((begin, 0))
    print(queue)
    visited = []
    while queue:
        n, level= queue.popleft()
        if n == target:
            print(level)
            return level
        print(n, level)
        if n not in visited:
            visited.append(n)
            print('visited', visited)
            print(graph[n])
            graph[n] = list(set(graph[n]) - set(visited))
            for string in graph[n]:
                queue.append((string, level+1))
            print(queue)
    return 0


def solution(begin, target, words):
    graph = defaultdict(list)
    node = begin
    for i in range(len(words)-1):
        strings = words[i:]
        for string in strings:
            arr = list(map(set, zip(node, string)))
            if len([a for a in arr if len(a) == 1]) == len(begin)-1:
                graph[node].append(string)
                graph[string].append(node)
        node = words[i]
    print(graph)
    answer = BFS(graph, begin, target)

    print(answer)

if __name__ == '__main__':
    solution('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog'])