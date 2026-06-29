for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    allminus = True
    findsumind = -1
    for c in range(n):
        if b[c]!=-1:
            findsumind = c
            allminus=False
    if allminus:
        small = min(a)
        big = max(a)
        print(max(k-big+small+1,0))
    else:
        add = a[findsumind]+b[findsumind]
        possible = True
        for num in range(n):
            if add>a[num]+k or add<a[num]:
                possible = False
                break
            if b[num]!=-1 and a[num]+b[num]!=add:
                possible=False
                break
        if possible:
            print(1)
        else:
            print(0)