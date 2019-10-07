from functools import cmp_to_key

def compare(a,b):
    print(a,b)
    if a+b > b+a:
        print('a+b',a+b)
        return a+b
    else:
        print('b+a',b+a)
        return b+a


def solution(numbers):
    answer = ''
    string = list(map(str, numbers))
    print(string)
    print(sorted(string, key=cmp_to_key(compare)))
    # for i in range(len(string)-1):
    #     print(sorted(string, key=cmp_to_key(compare)))



if __name__ == '__main__':
    # solution([6, 10, 2])
    solution([3, 30, 34, 5, 9])
    # solution([10,100,1,1000])