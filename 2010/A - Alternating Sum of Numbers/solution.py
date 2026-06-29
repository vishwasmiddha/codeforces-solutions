loops = int(input())
for i in range(loops):
    n = int(input())
    l = list(map(int,input().split()))
    s = 0
    for j in range(len(l)):
        s += (-1)**j*l[j]
    print(s)