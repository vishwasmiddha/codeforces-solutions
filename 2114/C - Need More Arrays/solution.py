for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    current=-1
    arrays = 0
    for c in arr:
        if c>=current+2:
            arrays+=1
            current=c
    print(arrays)