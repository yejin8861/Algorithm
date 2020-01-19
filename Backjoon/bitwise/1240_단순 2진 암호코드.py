
secure_code = ['0001101','0011001','0010011',
               '0111101','0100011','0110001',
               '0101111','0111011','0110111',
               '0001011']

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    row, col = map(int, input().strip().split())
    for i in range(row):
        r = list(map(str, input().strip()))
        if '1' in r:
            for j in range(col-1,-1,-1):
                if r[j] == '1':
                    code = ''.join(r[j-55:j+1])
                    # print(code)
                    break
    num_info = []
    for i in range(10):
        num_info.extend([idx for idx, num in enumerate(secure_code) if code[7*i:7*(i+1)] == num])

    num_info = list(map(int, num_info))
    # 정상적인 암호코드인지 판단
    odd_num = []
    even_num = []
    for i in range(8):
        if i%2:
            even_num.append(num_info[i])
        else:
            odd_num.append(num_info[i])
    if (sum(odd_num)*3 + sum(even_num))%10:
        print('#%d'%test_case, 0)
    else:
        print('#%d'%test_case, sum(num_info))

