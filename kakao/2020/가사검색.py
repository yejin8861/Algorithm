import re
def solution(words, queries):
    answer = []
    for q in queries:
        size = len(q)
        q = q.replace('?','\w')
        print(q)
        cnt = 0
        for word in words:
            if len(word) == size:
                if re.findall(q, word):
                    cnt += 1
        answer.append(cnt)
    print(answer)
    return answer

if __name__ == '__main__':
    solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
             ["fro??", "????o", "fr???", "fro???", "pro?"])