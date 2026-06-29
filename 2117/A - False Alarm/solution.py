for _ in range(int(input())):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    first=-1
    last=-1
    for i in range(n):
        if a[i]==1:
            first=i
            break
    for i in range(n-1,-1,-1):
        if a[i]==1:
            last=i
            break
    if first==-1:
        print("YES")
    elif (last-first+1)<=x:
        print("YES")
    else:
        print("NO")