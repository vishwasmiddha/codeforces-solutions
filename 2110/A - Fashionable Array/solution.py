for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    a = list(m%2 for m in a)
   # print(a)
    if a[0]==a[-1]:
        print(0)
    else:
        counts=[]
        count = 0
        while a[count]==a[0]:
            count+=1
        counts.append(count)
        count = n-1
        while a[count]==a[n-1]:
            count-=1
        counts.append(n-1-count)
        print(min(counts))