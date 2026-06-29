n = int(input())
l1 = []
l2 = []
li = list(map(int,input().split()))
for i in range(len(li)):
    c=li[i]
    if c%2==0:
        l1.append(i)
    else:
        l2.append(i)
if len(l1)==1:
    print(l1[0]+1)
else:
    print(l2[0]+1)