w, h = map(int, input().split())
p, q = map(int, input().split())
t = int(input())

move_x = []
for i in range(w):
    move_x.append(i)
for i in range(w, 0, -1):
    move_x.append(i)

arrive_x = (p + t) % (2*w)
arrive_x = move_x[arrive_x]

move_y = []
for i in range(h):
    move_y.append(i)
for i in range(h, 0, -1):
    move_y.append(i)
arrive_y = (q + t) % (2*h)
arrive_y = move_y[arrive_y]

print(arrive_x, arrive_y)