def solution(words, queries):
    import re
    string = ""
    for word in words:
        string += word + ','
    print(string)
    new_dict = {}
    for query in queries:
        new_dict[query] = [len(query), 0]
    print(new_dict)
    for key in new_dict.keys():
        cnt = 0
        print(key)
        query = key.replace('?', "\D")
        print(query)
        a = len(re.findall(query+'\W', string))
        print(a)
        new_dict[key] = a
        a = 0

    print(new_dict)
    result = []
    for query in queries:
        result.append(new_dict[query])
    print(result)
    return list(new_dict.values())

if __name__ == '__main__':
    solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],["fro??", "????o", "fr???", "fro???", "pro?"])