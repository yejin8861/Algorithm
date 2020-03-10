from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque(maxlen=cacheSize)
    for city in cities:
        city = city.lower() # 전부 소문자로 만들기
        # 1. hit일 경우
        if city in cache:
            # cache update
            cache.remove(city)
            cache.append(city)
            answer += 1
        # 2. miss일 경우
        else:
            cache.append(city)
            answer += 5
    print(answer)
    return answer

if __name__ == '__main__':
    solution(3, ['Newyork','Jeju', 'Pangyo', 'Seoul', 'Jeju', 'Pangyo', 'Seoul', 'Jeju', 'Pangyo', 'Seoul'])
