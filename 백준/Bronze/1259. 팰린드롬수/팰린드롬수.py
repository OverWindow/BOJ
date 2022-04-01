while True:
    N=int(input())
    if N == 0:
        break
    else:
        L = [*str(N)]
        if L == list(reversed(L)):
            print("yes")
        else:
            print("no")
                    
    
