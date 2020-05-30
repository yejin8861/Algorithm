def solution(skill, skill_trees):
    answer = 0
    for skills in skill_trees:
        li = list(skill)
        for s in skills:
            if s in li:
                if s != li.pop(0):
                    break
        else:
            answer += 1
    return answer

if __name__ == '__main__':
    solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"])