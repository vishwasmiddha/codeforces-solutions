def screen(a,b):
    n = len(a)
    m = len(b)
    num = 0
    for i in range(min(n,m)):
        if a[i]!=b[i]:
            break
        else:
            num+=1
    if num!=0:
        return m + n - num+1
    return m+n
 
loops = int(input())
for i in range(loops):
    print(screen(input(),input()))