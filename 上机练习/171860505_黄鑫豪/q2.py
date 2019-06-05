x = input()
s_a = x[0:x.index(' ')]
s_b = x[x.index(' ') + 1:]
a = []
b = []
c = [0]
for i in s_a:
    a.append(i)
for i in s_b:
    b.append(i)
for i in range(len(a)):
    a[i] = int(a[i])
for i in range(len(b)):
    b[i] = int(b[i])
a.reverse()
b.reverse()
x = len(a)
y = len(b)
for i in range(min(x, y)):
    c[i] = c[i] + a[i] + b[i]
    if c[i] > 9:
        c.append(1)
        c[i] = c[i] - 10
    else:
        c.append(0)
if x > y:
    for i in range(y + 1, x + 1):
        c[i] = c[i] + a[i]
        if c[i] > 9:
            c.append(1)
            c[i] = c[i] - 10
        else:
            c.append(0)
else:
    for i in range(x + 1, y + 1):
        c[i] = c[i] + b[i]
        if c[i] > 9:
            c.append(1)
            c[i] = c[i] - 10
        else:
            c.append(0)

c.reverse()
for i in c:
    print(i, end="")
