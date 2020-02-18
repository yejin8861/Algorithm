# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# return the length of its longest binary gap
# return 0 if N doesn't contain a binary gap


def solution(N):
    cnt_list = []
    diff = []
    string = list(bin(N))
    for idx,value in enumerate(string):
        if value == '1':
            cnt_list.append(idx-2)
    for i in range(1,len(cnt_list)):
        diff.append(cnt_list[i] - cnt_list[i-1] - 1)
    return 0 if len(cnt_list)==1 else max(diff)


if __name__ == '__main__':
    data = int(input())
    print(solution(data))

