for _ in range(int(input())):
    s=int(input())
    s = s**0.5
    if s==0:
        print(0,0)
    elif s%1==0 and s>=1:
        s=int(s)
        print(1,s-1)
    else:
        print(-1)