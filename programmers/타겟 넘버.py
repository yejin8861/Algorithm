
def recursive(sum, idx, target):
    global numbers
    global cnt
    if idx == len(numbers):
        if sum == target:
            cnt += 1
        return
    recursive(sum+numbers[idx], idx+1, target)
    recursive(sum-numbers[idx], idx+1, target)

numbers = []
cnt = 0
def solution(n, target):
    global numbers
    global cnt
    numbers = n
    sum = idx = 0
    recursive(sum + numbers[0], idx+1, target)
    recursive(sum - numbers[0], idx+1, target)
    print(cnt)
    return cnt

if __name__ == '__main__':
    solution([1,2,3,4], 5)