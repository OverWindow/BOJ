T = int(input())
A = sorted(list(map(int,input().split())))
Max = A[-1]
for i in range(0,len(A)):
        A[i] = A[i]/Max * 100
Average = 0
for i in A:
    Average += i
print(float(Average/len(A)))
