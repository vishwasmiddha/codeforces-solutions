for _ in range(int(input())):
    n,x=map(int,input().split())
    if x<n:
        l=[]
        for i in range(n):
            if i!=x:
                l.append(str(i))
        l.append(str(x))
        print(" ".join(l))
    else:
        l = list(range(n))
        print(" ".join(str(m) for m in l))
        