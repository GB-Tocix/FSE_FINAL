move_x = [0, 0, 1, -1]
move_y = [1, -1, 0, 0]

the_map = [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 2]]


border_x = len(the_map)
border_y = len(the_map[0])
ans = 0


def dfs(past, cur_x, cur_y, left, path):
    global border_x
    global border_y
    global the_map
    global ans
    if the_map[cur_x][cur_y] == 2:
        if left == 0:
            ans = ans + 1
            print(path)
        return
    for i in range(4):
        x = cur_x + move_x[i]
        y = cur_y + move_y[i]
        if x in range(border_x) and y in range(border_y) \
                and ((the_map[x][y] == 0 and not past[x][y]) or the_map[x][y] == 2):
            past[x][y] = True
            path.append([x, y])
            dfs(past, x, y, left - 1, path)
            past[x][y] = False
            path.remove([x, y])


p = []
need_to_cover = 0
for i in range(border_x):
    tmp_line = []
    for j in range(border_y):
        if the_map[i][j] == 1:
            begin_x = i
            begin_y = j
        if the_map[i][j] == 0:
            need_to_cover = need_to_cover + 1
            tmp_line.append(False)
        else:
            tmp_line.append(True)
    p.append(tmp_line)

path = [[begin_x, begin_y]]
dfs(p, begin_x, begin_y, need_to_cover + 1, path)
print(need_to_cover)
print(ans)



