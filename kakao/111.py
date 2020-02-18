def findMax(num):
    if num[0] != '9':
        if len(num) == 1:
            return '9'
        Max = num.replace(num[0], '9')
        return Max
    else:
        for i in range(1, len(num)):
            if num[i] != '9':
                Max = num.replace(num[i], '9')
                return Max


def findMin(num):
    if num[0] != '1':
        if len(num) == 1:
            return '1'
        Min = num.replace(num[0], '1')
        return Min
    else:
        
        for i in range(1, len(num)):
            if num[i] != '0' and num[0] != num[i]:
                Min = num.replace(num[i], '0')
                return Min
            elif num[i] == '0':
                Min = num.replace(num[i], '1')
                return Min


def findRange(num):
    # Write your code here
    num = str(num)
    print(int(findMax(num)))
    print(int(findMin(num)))
    answer = int(findMax(num)) - int(findMin(num))

    print(answer)
    return answer


if __name__ == '__main__':
    findRange(1111)