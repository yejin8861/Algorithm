# 시간복잡도 O(n^3)
def solution(phone_book):
    # 한 문자열이 다른 문자열안에 있는 확인하고
    # index가 0인지, 즉 접두어인지 확인.
    for i in range(len(phone_book)):
        for j in range(len(phone_book)):
            if i == j:
                continue
            else:
                # 접두어 = find의 인덱스가 0
                if phone_book[j].find(phone_book[i]) == 0:
                    return False
    return True

if __name__ == '__main__':
    # solution(['119', '97674223', '1195524421'])
    solution(['123', '97674223', '1195524421'])