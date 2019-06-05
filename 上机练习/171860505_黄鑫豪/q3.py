data = input()
data = data[1:-1]
data = data.split(',')
for i in range(len(data)):
    data[i] = int(data[i])
ans = 0
for i in range(len(data) - 1):
    if data[i + 1] > data[i]:
        ans = ans + data[i + 1] - data[i]
print(ans)
