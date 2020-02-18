def solution(food_times, k):
    food_dict = {}
    for i in range(len(food_times)):
        food_dict[i+1] = food_times[i]

    time = 0
    rm_key=[]
    while True:
        if len(food_dict) == 0:
            print(-1)
            return -1
        min_time = min(food_dict.values())

        key_list = list(food_dict.keys())
        print(key_list)
        if time + len(food_dict)*min_time > k:
            print(key_list[(k-time)%len(key_list)])
            return key_list[(k-time)%len(key_list)]

        time = time + len(food_dict) * min_time
        print('time', time)
        for key in key_list:
            food_dict[key] = food_dict[key] - min_time
            if food_dict[key] == 0:
                del food_dict[key]




if __name__ == '__main__':
    #solution([3,3,3,3],10)
    #solution([100230,200,3000,45123,32234,234832,45834,500000,30000,200000,300000,23,41234,1234,2134,234,1234,1234,123,423,423,42,3,34,53,265,67,548],105003)
    solution([1,1,1,1,1,1],2)