n,m = map(int,input().split())
doubles = 0
while n < m:
    doubles+=1
    n *= 2
rem = n-m
subs = 0
submax = 2**doubles
while n-m !=0:
    if submax > n-m:
        submax = submax//2
    else:
        n -= submax
        subs += 1
print(doubles + subs)