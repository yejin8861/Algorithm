
class Node(object):
    def __init__(self, _id=None, _x=None, _left=None, _right=None):
        self.id = _id
        self.x = _x
        self.left = _left
        self.right = _right

root = None
def addToBST(i, node):
    global root
    if root is None:
        root = Node(i, node[0])
        return
    else:
        temp = Node(i, node[0])
        cnt = root
        while True:
            if cnt.x < temp.x:
                if cnt.right is None:
                    cnt.right = temp
                    return
                cnt = cnt.right
            else:
                if cnt.left is None:
                    cnt.left = temp
                    return
                cnt = cnt.left

pre_result = []
def preorder(cnt):
    global pre_result
    if cnt is None:
        return
    pre_result.append(cnt.id)
    preorder(cnt.left)
    preorder(cnt.right)

post_result=[]
def postorder(cnt):
    global post_result
    if cnt is None:
        return
    postorder(cnt.left)
    postorder(cnt.right)
    post_result.append(cnt.id)

def solution(s):
    import sys
    sys.setrecursionlimit(10 ** 6)  # 재귀길이 설정
    global root, pre_result, post_result
    newdict = {}
    for i in range(len(s)):
        newdict[i+1] = s[i]
    print(newdict)
    #s.sort(key=lambda x:(x[1],x[0]), reverse=True)
    s = sorted(newdict.items(), key=lambda x:x[1][1], reverse=True)
    for node in s:
        addToBST(node[0], node[1])
    preorder(root)
    postorder(root)
    print(pre_result,post_result)
    return [pre_result,post_result]

if __name__ == '__main__':
    #solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]])
    solution([[1,3],[3,5]])