for _ in range(int(input())):
    n,k=map(int,input().split())
    s=input()
    one = s.count('1')
    zero = s.count('0')
    left = n-k*2
    if left %2==0:
        left = left//2
        one-=left
        zero-=left
        if one>=0 and zero>=0 and one%2==0 and zero%2==0:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")