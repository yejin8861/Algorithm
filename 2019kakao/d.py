a = [(0,),(1,),(0,1),(0,1,2)]
b = (0,1)
#c3 = [ list(set(b).intersection(i)) for i in a]
#c = [list(i) for i in a if list(b) in list(i)]
c = [i for i in a if set(b).intersection(set(i))]
print(set(a) - set(c))
print(c)