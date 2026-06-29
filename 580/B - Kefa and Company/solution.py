n,d=map(int,input().split())
m=[]
s={}
for _ in range(n):
    money,happy = map(int,input().split())
    m.append(money)
    if money in s:
        s[money]+=happy
    else:
        s[money]=happy
m.sort()
m2 = [m[0]]
for c in m:
    if m2[-1]!=c:
        m2.append(c)
p1,p2=0,0
maxsatisfy = s[m2[0]]
satisfy = maxsatisfy 
#print(satisfy)
while p1<len(m2):
    if p2==len(m2)-1:
        break
    else:
        p2+=1
        satisfy+=s[m2[p2]]
        #print(p1,p2,satisfy)
        while m2[p2]-m2[p1]>=d:
            #print(p1,p2,satisfy)
            satisfy-=s[m2[p1]]
            p1+=1
        if satisfy>maxsatisfy:
            maxsatisfy=satisfy
print(maxsatisfy)