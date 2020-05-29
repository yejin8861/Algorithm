def solution(n):
    paper = [0]
    for i in range(1, n):
        paper = paper + [0] + [bit ^ 1 for bit in paper[::-1]]
    return paper

if __name__ == '__main__':
    solution(3)