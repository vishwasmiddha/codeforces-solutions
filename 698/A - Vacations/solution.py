n = int(input())
days = list(map(int,input().split()))
cp = [0]*n
gym = [0]*n
rest=[0]*n
rest[0]=1
ini = days[0]
if ini<=1:
    gym[0]=-1
if ini%2==0:
    cp[0]=-1
for p in range(1,n):
    if days[p]<=1:
        gym[p]=-1
    else:
        if cp[p-1]==-1:
            gym[p]=rest[p-1]
        else:
            gym[p]=min(rest[p-1],cp[p-1])
    if days[p]%2==0:
        cp[p]=-1
    else:
        if gym[p-1]==-1:
            cp[p]=rest[p-1]
        else:
            cp[p]=min(rest[p-1],gym[p-1])
    compare = []
    for c in (cp[p-1],gym[p-1],rest[p-1]):
        if c!=-1:
            compare.append(c)
    rest[p]=min(compare)+1
compare = []
for c in (cp[-1],gym[-1],rest[-1]):
    if c!=-1:
        compare.append(c)
print(min(compare))