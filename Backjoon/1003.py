# 피보나치 수를 구하는 함수를 호출했을 때,
# 0과 1이 각각 몇 번 출력되는지 구하시오.

zero = 0
one = 0
def fibonacci(n):
    global zero
    global one
    if n==0:
        zero+=1
        return 0
    elif n==1:
        one+=1
        return 1
    else:
        return fibonacci(n-2) + fibonacci(n-1)

def loop(n):
    global zero
    global one
    for i in range(n):
        zero = 0
        one = 0
        data = int(input())
        fibonacci(data)
        print(zero, one)

if __name__ == '__main__':
    n = int(input())
    loop(n)