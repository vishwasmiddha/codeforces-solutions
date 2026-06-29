n,m,a,b=map(int,input().split())
if a<b/m:
    print(n*a)
elif n%m!=0:
    print(min((n//m)*b + (n%(m))*a,(n//m+1)*b))
else:
    print(n//m*b)