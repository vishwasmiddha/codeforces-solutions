num = input()
if "0" in num:
    print("YES")
    print(0)
elif "8" in num:
    print("YES")
    print(8)
else:
    if int(num[0])%2==0:
        evens = [1]
        odds=[0]
    else:
        evens = [0]
        odds=[1]
    possible=False
    answer = 0
    for ind in range(1,len(num)):
        if int(num[ind])%2==0:
            evens.append(evens[-1]+1)
            odds.append(odds[-1])
        else:
            evens.append(evens[-1])
            odds.append(odds[-1]+1)
    for evenind in range(len(num)-1,-1,-1):
        if possible:
            break
        if int(num[evenind])%2==0:
            for tens in range(evenind-1,-1,-1):
                if int(num[tens]+num[evenind])%8==0:
                    possible = True
                    answer = num[tens]+num[evenind]
                elif int(num[tens]+num[evenind])%8==4 and tens!=0:
                    if odds[tens-1]>0:
                        possible=True
                        for c in range(tens-1,-1,-1):
                            if int(num[c])%2==1:
                                answer=num[c]+num[tens]+num[evenind]
                                break
                        break
    if possible:
        print("YES")
        print(answer)
    else:
        print("NO")
                    
                    