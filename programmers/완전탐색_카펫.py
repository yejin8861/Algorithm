def solution(brown, red):
    # brown + red = width*height인데 width >= height이고 height >= 3이어야 하므로
    # width >= (brown + red) // 3 이다.
    for width in range(3, (brown+red)//3 + 1):
        for height in range(3, width+1):
            if red == (width-2) * (height-2) and brown == (width*height-red):
                return [width, height]

if __name__ == '__main__':
    solution(24,24)