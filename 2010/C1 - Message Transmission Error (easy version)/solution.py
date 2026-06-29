a = input()
n = len(a)
t = True
if n%2==1:
	for i in range(n//2+1,n-1):
#		print(a[0:i],a[n-i:n])
		if a[0:i]==a[n-i:n] and n>3:
			print("YES")
			print(a[0:i])
			t = False
			break
	if t or n<=3:
		print("NO")
else:
	for i in range(n//2+1,n):
#		print(a[0:i],a[n-i:n])
		if a[0:i]==a[n-i:n] and n>3:
			print("YES")
			print(a[0:i])
			t = False
			break
	if t or n<=3:
		print("NO")