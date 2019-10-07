# 시간복잡도 O(n^2)
def solution(phone_book):
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