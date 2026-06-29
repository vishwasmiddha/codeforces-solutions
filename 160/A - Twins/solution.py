def morhalf(m,t,s):
    n=0
    for i in range(m):
       if m == len(t):
        return False
 
       n+=t[i]
 
    if n > s/2:
        return False
    else:
        return True
 
def coin(t):
    t.sort()
    t.reverse()
    s = sum(t)
 
    m = 1
    while morhalf(m,t,s):
        m+=1
    return m
    
 
loops = int(input())
li = list(map(int,input().split()))
print(coin(li))