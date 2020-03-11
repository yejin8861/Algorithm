from collections import defaultdict

def make_dictionary(files):
    dic = defaultdict(list)
    for f in files:
        HEAD = ''
        NUMBER = ''
        flag = 0
        for c in f:
            if '0' <= c <= '9':
                NUMBER += c
                flag = 1
            else:
                if flag:
                    break
                HEAD += c
        dic[f].append(HEAD.lower())
        dic[f].append(int(NUMBER))
    return dic

def solution(files):
    # dic[file] = [index, HEAD, NUMBER]
    dic = make_dictionary(files)
    dic = sorted(dic.items(), key = lambda x: (x[1][0],x[1][1]))

    return [key for key, value in dic]

if __name__ == '__main__':
    solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])