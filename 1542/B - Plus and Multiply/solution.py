import math
t=int(input())
for _ in range(t):
    n,a,b = map(int,input().split())
    x=1
    if a!=1:
        found = False
        while x<=n:
            if (n-x)%b==0:
                found=True
                break
            else:
                x*=a
        if found:
            print("Yes")
        else:
            print("No")
    else:
        if (n-1)%b==0:
            print("Yes")
        else:
            print("No")
            