cityInfo = {}
xy_info = []


def findX(_xy):
    global cityInfo
    global xy_info
    Min = 100000000
    temp = 0
    for xy in xy_info:
        if xy[1] == _xy[1] and xy != _xy:
            if Min > abs(xy[0] - _xy[0]):
                Min = abs(xy[0] - _xy[0])
                temp = xy
    return [item[0] for item in cityInfo.items() if item[1] == temp]

def findY(_xy):
    global cityInfo
    global xy_info
    Min = 100000000
    temp = 0
    for xy in xy_info:
        if xy[0] == _xy[0] and xy != _xy:
            if Min > abs(xy[1] - _xy[1]):
                Min = abs(xy[1] - _xy[1])
                temp = xy
    return [item[0] for item in cityInfo.items() if item[1] == temp]


def checknear(q):
    # print(q)
    global cityInfo
    nearXcity=findX(cityInfo[q])
    nearYcity=findY(cityInfo[q])

    if len(nearYcity) == 0 and len(nearXcity)== 0 :
        # print('NONE')
        return 'NONE'
    elif len(nearXcity) == 0:
        # print(nearYcity[0])
        return nearYcity[0]
    elif len(nearYcity) == 0:
        # print(nearXcity[0])
        return nearXcity[0]
    else:
        a = abs(cityInfo[q][1] - cityInfo[nearXcity[0]][1])
        b = abs(cityInfo[q][0] - cityInfo[nearYcity[0]][0])
        if a>b:
            return nearYcity[0]
        else:
            return nearXcity[0]
        # print(a)
def closestStraightCity(c, x, y, q):
    # Write your code here
    global cityInfo
    global xy_info
    xy_info = list(zip(x, y))
    # print(xy_info)
    for xy in list(zip(c, x, y)):
        cityInfo[xy[0]] = (xy[1], xy[2])
    answer = []
    for i in q:
        answer.append(checknear(i))
    print(answer)
    return answer


if __name__ == '__main__':
    closestStraightCity(['london', 'warsaw', 'hackerland'], [1,10,20],[1,10,10],['london','warsaw', 'hackerland'])