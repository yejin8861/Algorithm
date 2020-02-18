from collections import defaultdict
import heapq

def find_small(number):
    global room_check
    start = 0
    end = len(room_check)
    check = list(room_check.keys())
    print('number',number)
    while (start < end):
        mid = (start+end) // 2
        print('check[mid]',check[mid])
        print(start, end, mid)
        if check[mid] > number: # number보다 큰 수면
            end = mid - 1
        else:
            start = mid
    print('s',start)
    return check[start]


room_check = defaultdict()
def solution(k, room_number):
    global room_check
    for i in range(k):
        room_check[i+1] = True
    # room_check = [False] * (k + 1)  # 빈 방 체크 리스트
    print(room_check)
    answer = []

    for number in room_number:
        # 원하는 번호 배정 가능
        print(number)
        # print(room_check[number])
        print(room_check.keys())
        if number in set(room_check.keys()):
            answer.append(number)
            del room_check[number]

        # 불가능
        else:
            small_room = find_small(number)
            print(small_room)
            answer.append(small_room)
            del room_check[small_room]

    print(room_check)
    print(answer)
    return answer

if __name__ == '__main__':
    solution(10, [1,3,4,1,3,1])