from collections import defaultdict, deque
def BFS(begin, target, words, word_dict):
    visited = []
    queue = deque(word_dict[begin])
    print(queue)

    cnt = 1
    while queue:
        size = len(queue)
        for _ in range(size):
            n = queue.popleft()
            if n == target:
                print(cnt)
                return cnt
            if n not in visited:
                visited.append(n)
                queue += set(word_dict[n]) - set(visited)
        print(queue)
        cnt += 1
    print(0)
    return 0

def solution(begin, target, words):
    word_dict = defaultdict(set)
    cmp = begin
    if target in words:  # words안에 target이 있는지 확인
        for i in range(len(words)):
            strings = words[i:]
            for string in strings:
                

    else:
        return 0
    print(word_dict)
    # return BFS(begin, target, words, word_dict)

if __name__ == '__main__':
    # solution('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog'])
    solution('hit','cog',['hot','coo','cog'])