def solution(s):
    newdict = {}
    for string in s:
        if string[0] != 'L': # Enter, change
            _, id, name = string.split(' ')
            newdict[id] = name
    answer = []
    for string in s:
        if string[0] == 'E':
            _, id, name = string.split(' ')
            answer.append(newdict[id] + "님이 들어왔습니다.")
        elif string[0] == 'L':
            _, id = string.split(' ')
            answer.append(newdict[id]+"님이 나갔습니다.")
    print(answer)

if __name__ == '__main__':
    s = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    solution(s)