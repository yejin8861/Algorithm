from collections import Counter
import ast
def solution(s):
    s = s.replace('{','[')
    s = s.replace('}',']')
    arr = ast.literal_eval(s)
    print(arr)
    arr = []
    for a in ast.literal_eval(s):
        print(a)
        arr.extend(a)
    print(arr)
    counter = Counter(arr)
    print(counter)
    print(sorted(counter, key=counter.get, reverse=True))
    return sorted(counter, key=counter.get, reverse=True)

if __name__ == '__main__':
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")
    # solution("{{4,2,3},{3},{2,3,4,1},{2,3}}")