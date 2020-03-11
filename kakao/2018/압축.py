def solution(msg):
    # 1. 사전 초기화
    dic = {chr(i + 64): i for i in range(1, 27)}
    dic_idx = 27

    answer = []
    start = 0
    for i in range(2, len(msg) + 1):
        find = msg[start:i]
        # 사전에 없는 경우
        if find not in dic.keys():
            w = msg[start:i - 1]  # 현재 입력과 일치하는 가장 긴 문자열
            answer.append(dic[w])
            dic[find] = dic_idx  # find를 사전에 등록
            dic_idx += 1
            start = i - 1  # w 제거

    find = msg[start:]
    if find in dic.keys():
        answer.append(dic[find])
    else:
        answer.append(dic_idx)
    print(answer)
    return answer


if __name__ == '__main__':
    solution("ABABABABABABABAB")
