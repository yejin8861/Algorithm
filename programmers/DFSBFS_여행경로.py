from collections import defaultdict

def DFS(routes):
    visited = []
    stack = []
    result = ['ICN']
    stack.extend(sorted(routes['ICN'], reverse=True))
    print(stack)
    prev = 'ICN'
    while stack:
        print('stack',stack)
        n = stack.pop()
        print('n',n)
        print('pop stack',stack)
        if routes: # 남아있는 경로가 존재하는 경우
            if n not in visited:
                visited.append(n)
                stack.extend(routes[n])

            if routes[n]:
                result.append(n)
                print('n', n, 'result', result)

            else:  # 자신의 공항에서 더이상 갈 곳이 없는 경우 딕셔너리에서 키 삭제
                routes.pop(prev)
            print(routes)
            prev = n
        else:
            print(result)
            return result
    print(result)



def solution(tickets):
    routes = defaultdict(list)
    for start, end in tickets:
        routes[start].append(end)
    print(routes)
    return DFS(routes)


if __name__ == '__main__':
    # solution([['ICN', 'JFK'], ['HND', 'IAD'], ['JFK', 'HND']])
    solution([['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['SFO', 'ICN'], ['ATL','SFO']])