from collections import Counter


def solution(participant, completion):
    a = Counter(participant) - Counter(completion)
    return list(a.keys())[0]

if __name__ == '__main__':
    # solution(['leo', 'kiki', 'eden'], ['eden', 'kiki'])
    solution(['marina', 'josipa', 'nikola', 'vinko', 'filipa'],['josipa', 'filipa', 'marina', 'nikola'])