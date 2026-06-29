for _ in range(int(input())):
    s=list(input())
    s.remove('(')
    s.reverse()
    s.remove(')')
    s.reverse()
    possible=False
    count = 0
    for c in s:
        if c=='(':
            count+=1
        else:
            count-=1
        if count<0:
            possible=True
            break
    if possible:
        print("YES")
    else:
        print("NO")