def getMinimumDifference(a, b):
    # Write your code here
    answer = []
    print(a,b)
    for i in range(len(a)):
        if len(a[i]) != len(b[i]):
            answer.append(-1)
        elif sorted(a[i]) == sorted(b[i]):
            answer.append(0)
        else:
            w_count = {}
            for w in a[i]:
                try: w_count[w] += 1
                except: w_count[w] = 1
            for w in b[i]:
                try: w_count[w] -= 1
                except:
                    # print(w_count.keys())
                    if w not in w_count.keys():
                        w_count[w] = -1
            cnt = sum([i for i in w_count.values() if i>0 ])
            answer.append(cnt)
            print(cnt)
    print(w_count)
    print(answer)
    # print(w_count)
if __name__ == '__main__':
    # a = ['a', 'jk', 'abb', 'mn', 'abc']
    # b = ['bb', 'kj', 'bbc', 'op', 'efg']
    a = ['abc', 'aaa']
    b= ['bba', 'bbb']
    getMinimumDifference(a,b)