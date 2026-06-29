s = input()
ind = []
for c in range(len(s)):
    if s[c]=="B":
        ind.append(c)
ab = 0
ba = 0
aba = 0
bab = 0
p = 0
while p<len(s)-1:
    #print(p)
    if s[p]=="A":
        if p==len(s)-2:
            if s[p:p+2] == "AB":
                ab+=1
            p+=2
        else:
            if s[p:p+3]=="ABA":
                aba+=1
                p+=3
            elif s[p:p+2]=="AB":
                ab+=1
                p+=2
            else:
                p+=1
    elif s[p]=="B":
        if p==len(s)-2:
            if s[p:p+2] == "BA":
                ba+=1
            p+=2
        else:
            if s[p:p+3]=="BAB":
                bab+=1
                p+=3
            elif s[p:p+2]=="BA":
                ba+=1
                p+=2
            else:
                p+=1
    else:
        p+=1
if ab*ba>0:
    print("YES")
elif max(ab,ba)>0:
    if aba+bab>0:
        print("YES")
    else:
        print("NO")
else:
    if aba+bab>1:
        print("YES")
    else:
        print("NO")