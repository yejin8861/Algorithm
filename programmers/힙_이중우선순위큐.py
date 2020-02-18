
def solution(operations):
    queue = []
    for string in operations:
        command, number = string.split()
        number = int(number)
        if command == 'I':
            queue.append(number)
        elif command == 'D':
            if queue:
                if number == 1: # 최댓값 삭제
                    queue.remove(max(queue))
                else: # 최솟값 삭제
                    queue.remove(min(queue))
    if queue:
        return [max(queue),min(queue)]
    else:
        return [0,0]

if __name__ == '__main__':
    solution(['I 7','I 5','I -5','D -1', 'D -1'])
    # solution(['1 16','D 1'])