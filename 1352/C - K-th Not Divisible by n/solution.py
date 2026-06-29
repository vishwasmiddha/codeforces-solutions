for _ in range(int(input())):
    n,k=map(int,input().split())
    tot = k
    account = k//n
    while account>0:
        early = tot//n
        tot += account
        account = tot//n -early
        #print(tot,account)
    print(tot)