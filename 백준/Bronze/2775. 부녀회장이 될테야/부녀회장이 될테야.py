T = int(input())
for i in range(T):
    k = int(input())
    n = int(input())
    before_floor= [i for i in range(1,n+1)]

    for _ in range(k):
        
        next_floor = [0 for i in range(n)]
        for i in range(0,n):
            for j in before_floor[:i+1]:
                next_floor[i] += j
        before_floor = next_floor[:]
        

    print(before_floor[-1])
    
    
