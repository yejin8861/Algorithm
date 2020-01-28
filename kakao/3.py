def firstOccurrence(s, x):
    # Write your code here
    if x.find('*') == -1:
        print(s.find(x))
        return s.find(x)
    else:
        a, b = x.split('*')
        print(a, b)
        print(len(a), len(b))
        index = s.find(a)
        print('1 index',index)
        # print(s.find(b, index + len(a)+1))
        # if s.find(b, index + len(a) + 1) == index + len(a) + 1:
        #     print('yes')
        while index < (len(s) - len(x)):
            if s.find(b, index+len(a)+1) == index + len(a) + 1:
                print(index)
                return index
            else:
                index = s.find(a,index)

if __name__ == '__main__':
    s = "juliasamanthantjulia"
    x = 'ant'
    firstOccurrence(s,x)
