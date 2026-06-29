for _ in range(int(input())):
    n = int(input())
    s = input()
    one = 0
    for c in s:
        if c=='0':
            one+=1
        else:
            one+=n-1
    print(one)