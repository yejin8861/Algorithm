def solution(v):
    v = sorted(v, key=lambda x:x[0])
    print(v)
    if v[0][0] == v[1][0]:
        x = v[2][0]
    else:
        if v[1][0] == v[2][0]:
            x = v[0][0]
        else:
            x = v[1][0]
    if v[0][1] == v[1][1]:
        y = v[2][1]
    else:
        if v[1][1] == v[2][1]:
            y = v[0][1]
        else:
            y = v[1][1]
    print([x,y])

if __name__ == '__main__':
    #v = [[1, 4], [3, 4], [3, 10]]
    v = [[1, 1], [2, 2], [1, 2]]
    #v = [[1,1],[1,1000],[2,1000]]
    solution(v)