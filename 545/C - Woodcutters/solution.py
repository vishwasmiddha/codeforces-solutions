n = int(input())
x = []
h = []
for _ in range(n):
    xl,hl=map(int,input().split())
    x.append(xl)
    h.append(hl)
l = [1]
if n==1:
    print(1)
else:
    if h[0]<=x[1]-x[0]:
        r=[1]
    else:
        r=[-1]
    no = [0]
    for i in range(1,n-1):
        #left fall
        left = []
        possibility=[l[i-1],r[i-1],no[i-1]]
        if possibility[0]!=-1 and h[i]<x[i]-x[i-1]:
            left.append(l[i-1]+1)
        if possibility[1]!=-1 and h[i]+h[i-1]<x[i]-x[i-1]:
            left.append(r[i-1]+1)
        if possibility[2]!=-1 and h[i]<x[i]-x[i-1]:
            left.append(no[i-1]+1)
        if len(left)==0:
            l.append(-1)
        else:
            l.append(max(left))
        no.append(max(possibility))
        right = []
        if possibility[0]!=-1 and h[i]<x[i+1]-x[i]:
            right.append(l[i-1]+1)
        if possibility[1]!=-1 and h[i]<x[i+1]-x[i] and h[i-1]<x[i]-x[i-1]:
            right.append(r[i-1]+1)
        if possibility[2]!=-1 and h[i]<x[i+1]-x[i]:
            right.append(no[i-1]+1)
        if len(right)==0:
            r.append(-1)
        else:
            r.append(max(right))
    final = []
    if l[-1]!=-1:
        final.append(l[-1]+1)
    final.append(no[-1]+1)
    if h[-2]<x[-1]-x[-2] and r[-1]!=-1:
        final.append(r[-1]+1)
    elif r[-1]!=-1:
        final.append(r[-1])
    print(max(final))