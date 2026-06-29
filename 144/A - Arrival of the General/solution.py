n = int(input())
boys = list(map(int,input().split()))
big = boys[0]
small = boys[0]
bigin = 0
smallin = 0
for i in range(len(boys)):
    if boys[i]>big:
        big = boys[i]
        bigin = i
    if boys[i]<=small:
        small = boys[i]
        smallin = i
if bigin<smallin:
    print(bigin + len(boys) - 1 - smallin)
else:
    print(bigin + len(boys) - smallin - 2)