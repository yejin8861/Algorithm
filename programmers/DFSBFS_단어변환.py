from collections import defaultdict, deque

# 최소단계를 구하는 것이기 때문에 BFS 사용
def BFS(begin, target, word_dict):
    visited = []
    queue = deque(word_dict[begin])
    cnt = 1
    while queue:
        size = len(queue)
        # 단계 구분을 위해 queue size 만큼만 for loop
        # loop가 끝나면 다음 단계라는 의미
        for _ in range(size):
            n = queue.popleft()
            if n == target: # target 문자열이 나왔을 때의 cnt값이 최소단계
                return cnt
            if n not in visited:
                visited.append(n)
                queue += set(word_dict[n]) - set(visited)
        cnt += 1
    return 0

def solution(begin, target, words):
    word_dict = defaultdict(set)
    cmp = begin
    if target in words:  # words안에 target이 있는지 확인
        for i in range(len(words)):
            strings = words[i:]  # 자기 다음 애들과 비교
            for string in strings:
                set_lists = list(map(set, zip(cmp, string)))  # 각 자리 한글자씩 set으로 만든 list. (ex. hit,hot -> [{h}, {i,o},{t}]
                # set list에서 set길이가 1이면 두 글자가 같다는 뜻이므로 하나만 다른 글자일 때 딕셔너리에 추가
                if len([set_list for set_list in set_lists if len(set_list) == 1]) == len(begin)-1:
                    word_dict[cmp] |= {string}
                    word_dict[string] |= {cmp}
            cmp = words[i]
    else:
        return 0
    return BFS(begin, target, word_dict)

if __name__ == '__main__':
    # solution('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog'])
    solution('hit','cog',['hot','coo','cog'])