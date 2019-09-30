#
# import timeit
# start = timeit.default_timer()

a, b = map(int, input().strip().split(' '))
data = list(input().split(' '))
l = []
answer = []
for i in range(a):
    l.append(int(data[i]))
s = []
for x in range(b):
    i,j,k = map(int, input().strip().split(' '))
    s = l[i-1:j]
    s.sort()
    answer.append(s[k-1])

for i in range(len(answer)):
    print(answer[i])
# stop = timeit.default_timer()
# print(stop - start)
