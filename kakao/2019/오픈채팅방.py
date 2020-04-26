def solution(record):
    answer = []
    dic = {}
    message = {"Enter":"님이 들어왔습니다.", "Leave":"님이 나갔습니다."}
    for r in record:
        rr = r.split()
        if rr[0] in ['Enter', 'Change']:
            dic[rr[1]] = rr[2]

    for r in record:
        rr = r.split()
        if rr[0] in ['Enter', 'Leave']:
            answer.append(dic[rr[1]] + message[rr[0]])
    # print(answer)
    return answer


if __name__ == '__main__':
    solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])
