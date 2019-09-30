#a, b = map(int, input().strip().split(' '))
a = [[1,2], [3,4], [5,6]]
a.sort(key=lambda x: x[0])
print(a)