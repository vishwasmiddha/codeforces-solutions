length, jod = map(int,input().split())
if length==1 and jod==0:
    print("0 0")
else:
    small = [0]*(length)
    large = small.copy()
    j2 = jod
    p2 = length-1
    while j2>1 and p2>0:
        if j2>=10:
            j2-=9
            small[p2]+=9
            p2-=1
        else:
            small[p2]+=j2-1
            j2=1
    small[0]+=j2
    if j2 <= 9 and small[0]!=0:
        
        for c in small:
            print(c,end="")
        print(" ",end="")
    else:
        print(-1,end=" ")
    
    
    
    
    
    
    
    
    j1 = jod
    p1 = 0
    while j1>0 and p1<length:
        if j1>9:
            large[p1]+=9
            p1+=1
            j1-=9
        else:
            large[p1]+=j1
            j1=0
    if j1==0 and large[0]!=0:
        for c in large:
            print(c,end="")
    else:
        print(-1)