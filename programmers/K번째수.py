def solution(array, commands):
    return [sorted(array[start-1:end])[k-1] for start, end, k in commands]

if __name__ == '__main__':
    solution([1, 5, 2, 6, 3, 7, 4],[[2, 5, 3], [4, 4, 1], [1, 7, 3]])