from collections import deque

def solution(bridge_length, weight, truck_weights):
    if sum(truck_weights) <= weight:
        return bridge_length + len(truck_weights)

    bridge = deque([0]*bridge_length)
    time = 0
    i = 0
    total = 0
    while i < len(truck_weights):
        time += 1
        n = bridge.popleft()
        total -= n
        if total + truck_weights[i] <= weight:
            bridge.append(truck_weights[i])
            total += truck_weights[i]
            i += 1
        else:
            bridge.append(0)
    return time + bridge_length


if __name__ == '__main__':
    solution(2,10,[7,4,5,6])
    # solution(100,100,[10])
    # solution(100,100,[10,10,10,10,10,10,10,10,10,10])