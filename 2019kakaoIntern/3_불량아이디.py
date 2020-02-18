import re
from itertools import combinations, product


def solution(user_id, banned_id):
    answer = 0
    ban_list = [[] for _ in range(len(banned_id))]
    print(ban_list)
    for idx, id in enumerate(banned_id):
        id = id.replace('*','\w')
        print(id)
        for user in user_id:
            if re.findall('^'+id+'$',user):
                ban_list[idx].append(user)
    print(ban_list)
    set_list = []
    for x in product(*ban_list):
        # print(x)
        if len(set(x)) == len(banned_id):
            if set(x) not in set_list:
                set_list.append(set(x))
    print(len(set_list))
    # print(len(set(set_list)))



    # query = key.replace('?', "\D")
    # print(query)
    # a = len(re.findall(query+'\W', string))
    # print(a)
    return len(set_list)

if __name__ == '__main__':
    solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "abc1**"])
    # solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["fr*d*", "*rodo", "******", "******"])