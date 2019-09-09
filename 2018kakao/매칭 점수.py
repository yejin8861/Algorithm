
def Count_baseScore(word, str):
    import re
    return re.sub('[^a-z]+', '.', str.lower()).split('.').count(word.lower())

    '''
    cnt = 0
    str = str.lower()
    crop = str
    i=0
    # print(word)
    # print(str)
    while len(str) > len(word):
        idx = crop.find(word)
        # print('idx',idx)
        # print('i',i)
        if idx == -1:
            # print('cnt',cnt)
            return cnt
        else:
            try:
                if str[i+idx - 1].isalpha() is False and str[i+idx + len(word)].isalpha() is False:
                    cnt += 1
            except:
                if i+idx == 0:
                    if str[i+idx + len(word)].isalpha() is False:
                        cnt += 1
                else:
                    if str[i+idx - 1].isalpha() is False:
                        cnt += 1
        crop = str[i+idx+len(word):]
        #print('crop',crop)
        i += idx + len(word)
    '''

def find_link(body):
    result = []
    while True:
        a = body.find('href="')
        if a == -1:
            return result
        b = body[a:].find('">')
        print(body[a+6:a+b])
        result.append(body[a+6:a+b])
        body = body[a+b:]


def solution(word, pages):
    newdict = {}
    word = word.lower()
    for i in range(len(pages)):
        print(pages)
        a = pages[i].find('content="')
        b = pages[i][a:].find('"/>')
        print(pages[i][a+9:a+b]) # url
        url = pages[i][a+9:a+b]


        a = pages[i].find('<body>')
        b = pages[i][a:].find('</body>')
        print(pages[i][a+7:a+b]) # body
        body = pages[i][a+7:a+b]
        base = Count_baseScore(word, body)
        print(base)
        link = find_link(body)
        newdict[url] = [i, base, link]
        print(newdict)

    matching = []
    link_score = 0
    for key in newdict.keys():
        print(key)
        for value in newdict.values():
            # link_score = [(value[1] / len(value[2])) for l in value[2] if l == key]
            for l in value[2]:
                if l == key:
                    link_score += (value[1] / len(value[2]))
        matching.append(newdict[key][1] + link_score)
        link_score = 0
    print(matching.index(max(matching)))

    return matching.index(max(matching))


if __name__ == '__main__':
    #solution("blind",["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"])
    solution("Muzi", ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"])