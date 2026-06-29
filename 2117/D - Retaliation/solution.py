def possible(n,a):
    first=a[0]
    last=a[-1]
    if first>last:
        diff = first-last
        mustbe=n-1
        if diff%mustbe!=0:
            return False
        else:
            times=diff//mustbe
        store=first-n*times
        if store%(n+1)!=0 or store<0:
            return False
        for i in range(n):
            if (a[i]-times*(n-i))!=store:
                return False
        return True
    elif first<last:
        diff = last-first
        mustbe=n-1
        if diff%mustbe!=0:
            return False
        else:
            times=diff//mustbe
        store=first-times
        if store%(n+1)!=0 or store<0:
            return False
        for i in range(n):
            if (a[i]-times*(i+1))!=store:
                return False
        return True
    else:
        if first%(n+1)!=0 or first<0:
            return False
        for c in a:
            if c!=first:
                return False
        return True
 
 
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if possible(n,a):
        print("YES")
    else:
        print("NO")
 