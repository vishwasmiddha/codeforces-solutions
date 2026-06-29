n,l=map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
small = max(arr[0],l-arr[-1])
for i in range(1,n):
    small = max(small,(arr[i]-arr[i-1])/2)
print(small)