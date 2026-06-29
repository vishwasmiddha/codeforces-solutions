n = input()
if n[0]=="9":
    s = "9"
else:
    s = str(min(9-int(n[0]),int(n[0])))
for c in range(1,len(n)):
    c = n[c]
    if c in "56789":
        s += str(9-int(c))
    else:
        s += c
print(s)