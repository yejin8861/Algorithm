import itertools

def arrangements(n):
    answer = 0
    # for i in range(n):
    #     mylist = [r for r in range(1,n+1)]
    mylist = range(1,n+1)
    print(mylist)

    # for myperm in myperms:
    #     cnt = 0
    #     # print(myperm)
    #     for j, num in enumerate(myperm, 1): # [1,2,3,4]
    #         # print(j,num)
    #         if num % j and j % num:
    #             # print(j,num)
    #             # print('break')
    #             break
    #         else:
    #             cnt += 1
    #     if cnt == len(myperm):
    #         answer += 1
    # print(answer)


    #
    #
    # answer.append(myperms[0])
    # for i in range(1, len(myperms)):
    #     cnt = 0
    #     for j, num in enumerate(myperms[i]):
    #         #print('myperms[i]:',myperms[i])
    #         if num % (j+1) and (j+1) % num:
    #             # print(num % (j+1))
    #             # print((j+1) % num)
    #             # print('break')
    #             break
    #         else:
    #             cnt += 1
    #     if cnt == len(myperms[i]):
    #         answer.append(myperms[i])
    #
    # print(len(answer))


if __name__ == '__main__':
    n = 10
    arrangements(n)