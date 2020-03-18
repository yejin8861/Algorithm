
def simulation(string):
    types = []
    name = []
    for s in string[1:]:
        temp = ''
        i = 0
        for i in range(len(s)):
            if s[i] in ["#","&","*"]: break

        name.append(s[:i])
        type = reversed(s[i:-1])
        for c in type:
            temp += c
        types.append(temp)

    prime = string[0].replace("#","[]")
    for i, type in enumerate(types):
        type = type.replace("#","[]")
        print(prime+type+' '+name[i]+';')
    return


string = input().strip()
string = string.replace("[]", "#").split(' ')
simulation(string)
