def solution(n, weak, dist):
    answer = 0
    queue = []
    for i in range(len(weak)-1):
        queue.append([(weak[i],weak[i+1]),weak[i+1]-weak[i]])
    queue.append([(weak[0],weak[-1]),n - (weak[-1]-weak[0])])
    print(queue)
    dist.sort(reverse=True)

    return answer

if __name__ == '__main__':
    solution(12,[1, 3, 4, 9, 10],[3,5,7])