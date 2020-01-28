def findCompletePrefixes(names, query):
    # Write your code here
    answer = []
    for q in query:
        cnt = 0
        for name in names:
            # print(name)
            # print(name.find(q))
            if name.find(q) == 0 and len(q) != len(name):
                cnt += 1
        answer.append(cnt)

    return answer
if __name__ == '__main__':
