from collections import defaultdict

def replace_flat(s):
    s = s.replace('A#', 'H')
    s = s.replace('C#', 'I')
    s = s.replace('D#', 'J')
    s = s.replace('F#', 'K')
    s = s.replace('G#', 'L')
    return s

def solution(m, musicinfos):
    # musicinfo = [음악 시작 시간, 끝난 시각, 제목, 악보정보]
    m = replace_flat(m)
    dic = defaultdict(list)  # dic[title] = [악보정보, play]
    # 1. 재생시간만큼 재생한 악보 딕셔너리 만들기
    for music in musicinfos:
        start, end, title, info = music.split(',')
        info = replace_flat(info)
        # 재생시간 (end - start)
        play = (int(end[:2]) * 60 + int(end[3:])) - (int(start[:2]) * 60 + int(start[3:]))
        index = len(info)
        sheet = ''.join([info[i % index] for i in range(play)])
        dic[title].append(sheet)
        dic[title].append(play)

    # 2. 악보에서 멜로디 찾기
    answer = defaultdict(int)  # answer[title] = play
    for key, value in dic.items():
        if m in value[0]:
            answer[key] = value[1]
    if len(answer):
        return sorted(answer.items(), key=lambda x: x[1], reverse=True)[0][0]
    else:
        return '(None)'


if __name__ == '__main__':
    # solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"])
    # solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"])
    solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"])
