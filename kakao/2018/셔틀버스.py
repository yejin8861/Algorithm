# 모든 시간을 분으로 계산하기
class T:
    def __init__(self, time, cnt):
        self.time = time
        self.cnt = cnt

def solution(n, t, m, timetable):
    # 크루 시간 구하기
    crew = [int(s[:2]) * 60 + int(s[3:]) for s in timetable]
    crew.sort()  # 시간 순 정렬

    # 셔틀 버스 시간 구하기
    shuttle = []
    for i in range(n):
        a = T(540+(i*t), m)
        shuttle.append(a)

    LAST = shuttle[-1].time
    con = LAST
    for s in shuttle:
        while len(crew) > 0:
            # 현재 크루가 셔틀에 탈 수 없으면 다음 셔틀 타기
            if s.time < crew[0] or s.cnt == 0: break

            # 마지막 자리인데 현재 크루가 타야한다면 콘은 현재 크루 시각 - 1
            if s.time == LAST and s.cnt == 1:
                con = crew[0] - 1
                break
            # 현재 크루가 셔틀에 타기
            crew = crew[1:]
            s.cnt -= 1

    # 분을 HH:MM형식으로 바꾸기
    return '%02d:%02d' % (con // 60, con % 60)


if __name__ == '__main__':
    # solution(1, 1, 5, ["08:00", "08:01", "08:02", "08:03"])
    solution(2, 10, 2, ["09:10", "09:09", "08:00"])
