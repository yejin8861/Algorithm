from collections import defaultdict


def solution(genres, plays):
    answer = []
    # create dictionary about genres and play number
    zip_list = list(zip(genres, plays))
    music = defaultdict(list)
    cnt = defaultdict(int)
    for i, li in enumerate(zip_list):
        cnt[li[0]] += li[1]
        music[li[0]].append((li[1], i))

    # Descending order by playing number
    cnt = sorted(cnt.items(), key=lambda x: x[1], reverse=True)

    for genre, num in cnt:
        Count = 0
        # 각 장르마다 play수에 대해 내림차순 정렬
        sorting_genres = sorted(music[genre], key=lambda x:x[0], reverse=True)
        for n, idx in sorting_genres:
            answer.append(idx)
            Count += 1
            # 한 장르의 곡을 두개 넣으면 다음 장르로 넘어감.
            if Count == 2:
                break
    print(answer)
    return answer




if __name__ == '__main__':
    solution(['jazz','pop','classic','classic','jazz','hiphop'],[200, 500, 100, 200,700,800])
    # solution(['classic', 'pop', 'classic', 'classic', 'pop'],[500, 600, 150, 800, 2500])
    # solution(['jazz','pop'],[200, 500])