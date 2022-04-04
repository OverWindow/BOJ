Limit = int(input())
HansuNum = 0

for i in range(1,Limit+1):
    if len(str(i)) == 1 or len(str(i)) == 2:
        HansuNum += 1
    else:
        L=[]
        for j in range(0,len(str(i))- 1):
            L.append( int(list(str(i))[j+1]) - int(list(str(i))[j]))

        if len(list(set(L))) == 1:
            HansuNum += 1

print(HansuNum)
