import math
 
loops = int(input())
for i in range(loops):
    inp = list(map(int,input().split()))
    inp[0] = math.ceil(inp[0]/inp[2])
    inp[1] = math.ceil(inp[1]/inp[2])
    if inp[0]<=inp[1]:
        print(2*inp[1])
    else:
        print(2*inp[0]-1)