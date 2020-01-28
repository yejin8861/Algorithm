def solution(record):
    answer = []
    namespace = {}
    printer = {'Enter':'님이 들어왔습니다.', 'Leave':'님이 나갔습니다.'}
    for r in record:
        rr = r.split()
        if rr[0] in ['Enter', 'Change']:
            namespace[rr[1]] = rr[2]

    for r in record:
        if r.split()[0] != 'Change':
            answer.append(namespace[r.split()[1]]+printer[r.split()[0]])

    #print(answer)
    return answer

if __name__ == '__main__':
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Enter uid789 yejin", "Change uid789 sooyeon", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]
    solution(record)
