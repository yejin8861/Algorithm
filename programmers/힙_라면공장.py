def solution(stock, dates, supplies, k):
    dates.append(k-1)
    print(dates, supplies)
    result = 0
    stock -= dates[0] # 0
    print(stock)
    for i in range(1, len(dates)):
        if stock > dates[i] - dates[i-1]:  # 다음 공급되는 날짜까지 stock이 충분한 경우
            print('1stock', stock, stock - (dates[i] - dates[i - 1]))
            stock -= (dates[i] - dates[i-1])

        else:  # stock이 충분하지 않은 경우 사용하는 날짜만큼 빼고 공급받는 supplies만큼 더함.
            print('2stock', stock, stock + supplies[i - 1] - (dates[i] - dates[i - 1]))
            stock += supplies[i-1] - (dates[i] - dates[i-1])

            result += 1
    print(result)
    return result



if __name__ == '__main__':
    solution(5,[4,10,15],[20,5,10],30)