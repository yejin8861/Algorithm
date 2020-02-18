# Binary Search 는 오름차순으로 정렬된 리스트에서 특정값의 위치를 찾는 알고리즘
# 처음 중간의 임의 값을 선택하여, 그 값의 크고 작음을 비교
# 시간복잡도는 O (log N) 이다.

def binary_search(arr, value):
    low = 0
    high = len(arr) - 1
    while (low <= high):
        mid = (low + high) // 2

        if arr[mid] > value:
            high = mid - 1
        elif arr[mid] < value:
            low = mid + 1
        else:
            return mid

    return -1


arr = [1, 5, 7, 10, 25, 32, 79, 80, 125]

print(binary_search(arr, 25))
print(binary_search(arr, 8))