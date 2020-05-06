class Node:
    def __init__(self, val, leaf=False):
        self.val = val
        self.leaf = leaf
        self.cnt = 0
        self.child = {}

class Trie:
    def __init__(self):
        self.root = Node(None)

    def insert(self, string):
        cur = self.root

        for c in string:
            # 문자가 없었으면 새로운 노드 추가
            if c not in cur.child:
                cur.child[c] = Node(c)
            # 문자 count + 1
            cur.cnt += 1
            cur = cur.child[c]
        # leaf node
        cur.cnt += 1
        # cur.leaf = True

    def search(self, prefix):
        ret = 0
        cur = self.root

        for c in prefix:
            # 찾는 문자가 있으면
            if c in cur.child:
                cur = cur.child[c]
            else:
                return 0

        # 자식 노드 카운트
        for c in cur.child:
            ret += cur.child[c].cnt
        return ret


def solution(words, queries):
    answer = []
    trie = [Trie() for _ in range(10000)]
    Rtrie = [Trie() for _ in range(10000)]

    for w in words:
        trie[len(w)-1].insert(w)
        Rtrie[len(w)-1].insert(w[::-1])

    for query in queries:
        if query[0] == '?':
            query = query[::-1]
            answer.append(Rtrie[len(query)-1].search(query.split('?')[0]))
        else:
            answer.append(trie[len(query)-1].search(query.split('?')[0]))
    print(answer)
    return answer


if __name__ == '__main__':
    solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
             ["fro??", "????o", "fr???", "fro???", "pro?","?????"])