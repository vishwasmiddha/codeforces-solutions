lo = int(input())
for i in range(lo):
    n = int(input())
    l=[]
    for j in range(n):
        s = input()
        for k in range(len(s)):
            if s[k]=="#":
                l.append(k+1)
                break
    l.reverse()
    for c in l:
        print(c,end=" ")
    print()