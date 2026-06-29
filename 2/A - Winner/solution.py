n = int(input())
s = {}
updation = {}
for i in range(1,n+1):
    inp = input().split()
    name = inp[0]
    score =  int(inp[1])
    if name in s:
        s[name]+=score
    else:
        s[name]=score
    updation[(name,i)]=s[name]
win = []
highscore = 0
for c in s:
    thescore=s[c]
    if thescore>highscore:
        win.clear()
        win.append(c)
        highscore = s[c]
    elif thescore==highscore:
        win.append(c)
if len(win)==1:
    print(win[0])
else:
    found = False
    for i in range(1,n+1):
        for c in win:
            if (c,i) in updation:
                if updation[(c,i)]>=highscore:
                    print(c)
                    found = True
        if found:
            break