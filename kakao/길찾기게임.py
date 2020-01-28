class Node(object):
    def __init__(self, _id=None, _x=None, left=None, right=None):
        self.id = _id
        self.x = _x
        self.left = left
        self.right = right

root = None
def addToBST(id, x):
    global root
    temp = Node()
    temp.id = id
    temp.x = x

    if root is None:
        root = temp
        return
    else:
        cur = root
        while True:
            if temp.x < cur.x:
                if cur.left is None:
                    cur.left = temp
                    return
                else:
                    cur = cur.left
            else:
                if cur.right is None:
                    cur.right = temp
                    return
                else:
                    cur = cur.right

pre_list = []
def pre_order(cur):
    global pre_list
    if cur is None:
        return
    pre_list.append(cur.id)
    pre_order(cur.left)
    pre_order(cur.right)

post_list = []
def post_order(cur):
    global post_list
    if cur is None:
        return
    post_order(cur.left)
    post_order(cur.right)
    post_list.append(cur.id)

def solution(nodeinfo):
    import sys
    sys.setrecursionlimit(10 ** 6) # 재귀길이 설정
    global root
    sorted_node = sorted(list(zip(range(1,len(nodeinfo)+1), nodeinfo)),key=lambda x: (x[1][1],-x[1][0]),reverse=True)
    for item in sorted_node:
        addToBST(item[0], item[1][0])

    pre_order(root)
    post_order(root)
    answer = [pre_list,post_list]
    return answer

if __name__ == '__main__':
    solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]])