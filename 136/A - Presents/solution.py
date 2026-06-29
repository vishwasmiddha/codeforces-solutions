n = int(input())
l = [0]*n
gift = list(map(int,input().split()))
for i in range(n):
    l[gift[i]-1] = i+1
for c in l:
    print(c, end=" ")
    