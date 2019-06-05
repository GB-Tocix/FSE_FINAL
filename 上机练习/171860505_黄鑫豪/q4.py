def x4(p):
    width = 0
    for i in p[0]:
        width = width + i
    ans = []
    for i in range(width):
        ans.append(0)
    for i in range(len(p)):
        tmp_sum = 0
        for j in range(len(p[i]) - 1):
            tmp_sum = tmp_sum + p[i][j]
            ans[tmp_sum] = ans[tmp_sum] + 1
    maximum = ans[1]
    for i in range(2, width):
        if ans[i] > maximum:
            maximum = ans[i]
    print(len(p) - maximum)


tmp = [[1, 2, 2, 1],
       [3, 1, 2],
       [1, 3, 2],
       [2, 4],
       [3, 1, 2],
       [1, 3, 1, 1]]
x4(tmp)
