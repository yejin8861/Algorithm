ans = 0
def dfs(numbers, target, n, sum):
    global ans
    if n == len(numbers):
        if target == sum:
            ans += 1
        return
    dfs(numbers, target, n + 1, sum + numbers[n])
    dfs(numbers, target, n + 1, sum - numbers[n])

def solution(numbers, target):
    dfs(numbers, target, 0, 0)
    return ans

if __name__ == '__main__':
    solution([1,1,1,1,1],3)