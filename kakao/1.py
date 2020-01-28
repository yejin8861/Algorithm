price = [4,9,2,3]
cost = []
cost.append(price[0])
minimum = price[0]
for i in range(1, len(price)):
    if price[i-1] < minimum:
        minimum = price[i-1]
    diff = max(price[i] - minimum, 0)
    #diff = max(price[i] - min(price[:i+1]), 0)
    cost.append(diff)
    # print('price[i]:',price[i])
    # print('price[:i]:',price[:i+1])
    # print('min(price[:i])',min(price[:i+1]))
    # print('price[i] - min(price[:i]',price[i] - min(price[:i+1]))
    # print('diff',diff)
    # print('---------------------')
print(sum(cost))