while True:
    N=int(input())
    if N == 0:
        break
    else:
        L = [*str(N)]
        if len(str(N)) % 2 == 0:
            pass
        else:
            del L[len(L)//2]
            
        for i in range(0,int(len(L)/2)):
            if L[i] == L[-1-i]:
                L[i] = 1
                L[-1-i] = 1
            else:
                L[i] = 0
                L[-1-i] = 0
        if sum(L) == len(L) or len(L) == 1:
            print("yes")
        else:
            print("no")
                    
    

