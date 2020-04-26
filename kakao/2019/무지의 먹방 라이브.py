def solution(food_times, k):
    food_times_list = []
    totalTime = 0

    for i in range(0, len(food_times)):
        food_times_list.append([i, food_times[i]])
        totalTime+=food_times[i]

    if totalTime <= k:
        return -1

    food_times_list = sorted(food_times_list, key=lambda x:x[1])
    delTime = food_times_list[0][1]*len(food_times_list)
    i=1
    while delTime < k:
        k-=delTime
        delTime = (food_times_list[i][1]-food_times_list[i-1][1])*(len(food_times_list)-i)
        i+=1

    food_times_list = sorted(food_times_list[i-1:], key=lambda x:x[0])
    # print k
    return food_times_list[k%len(food_times_list)][0]+1


if __name__ == '__main__':
    solution([3,1,2],5)