n,t = map(int,input().split())
a = list(map(int,input().split()))
pointer1 = 0
pointer2 = 0
timeforrange = 0
starters = []
for pointer1 in range(n):
    if pointer2>=n:
        starters.append(n-pointer1)
    else:
        while timeforrange < t and pointer2!=n:
            timeforrange+=a[pointer2]
            pointer2+=1
        if timeforrange == t:
            starters.append(pointer2-pointer1)
            timeforrange-=a[pointer1]
        elif timeforrange > t:
            starters.append(pointer2-pointer1-1)
            timeforrange -= a[pointer2-1] + a[pointer1]
            pointer2-=1
        if pointer2==n:
            starters.append(n-pointer1)
print(max(starters))
            
    