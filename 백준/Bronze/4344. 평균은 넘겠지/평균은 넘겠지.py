C=int(input())
for i in range(C):
    A=list(map(int, input().split()))
    Ave = (sum(A) - A[0])/A[0]
    del A[0]
    for i in range(0,len(A)):
        if A[i] > Ave:
            A[i] = 1
        else:
            A[i] = 0

    Per = A.count(1) / len(A) * 100
    print("%.3f%%" %Per)
    
