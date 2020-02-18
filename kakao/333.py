def teamFormation(score, team, m):
    # Write your code here
    # first = max(score[0:m])
    # last = max(score[len(score)-m:])
    # print(score,team,m)
    Sum = 0
    for i in range(team):
        left = score[0:m]
        right = score[len(score)-m:]
        # print(left, right)
        if max(left) >= max(right):
            idx = left.index(max(left))
            Sum += score.pop(idx)
        else:
            idx = right.index(max(right))
            Sum += score.pop(len(score)-m+idx)
    #     print(left, right)
    #     print(score)
    #     print(Sum)
    print(Sum)
    return Sum

if __name__ == '__main__':
    teamFormation([6,18,8,14,10,12,18,9],8,3)