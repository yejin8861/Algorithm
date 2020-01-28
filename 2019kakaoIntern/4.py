from collections import deque
import heapq

def find_small(room_number):
    global room_check
    room_check = [(check, idx) for idx, check in enumerate(room_check)]  # (빈 여부, 방의 번호)
    possible_room = room_check[room_number + 1:]  # 원하는 방보다 큰 번호 방의 경우에만 선택
    heapq.heapify(possible_room)  # 최소힙 => 빈 방 순서대로 정렬 & 방 번호가 작은 순서대로 정렬
    check, small_num = heapq.heappop(possible_room)  # 빈 방 중에서 가장 작은 번호의 방의 번호를 알 수 있음

    return small_num


room_check = []
def solution(k, room_number):
    global room_check
    EMPTY, FULL = 0, 1
    room_check = [EMPTY] * (k + 1)  # 빈 방 체크 리스트
    # room_number = deque(room_number)  # 앞에서부터 방 배정을 위한 큐
    answer = []  # 정답 리스트

    for number in room_number:
        # number = room_number.popleft()  # 고객이 원하는 방 번호

        # 원하는 번호 배정 가능
        if room_check[number] == EMPTY:
            answer.append(number)
            room_check[number] = FULL

        # 불가능
        else:
            small_number = find_small(number)
            answer.append(small_number)
            room_check[small_number] = FULL

    return answer


k = 10
room_number = [1, 3, 4, 1, 3, 1]

solution(k, room_number)