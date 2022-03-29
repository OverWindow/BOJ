N=int(input())
Map = [[0 for i in range(N)]for i in range(N)]
a = 1

def star(n):
    global Map
    global a
    a *=3
    if a==n:
        return
    
    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                pass
            else:
                for k in range(a):
                    Map[a*i+k][a*j:a*(j+1)] = Map[k][:a]
    star(n)

    
if N == 3:
    Map[0][:3]=[1]*3
    Map[1][:3]=[1,0,1]
    Map[2][:3]=[1]*3
else:
    Map[0][:3]=[1]*3
    Map[1][:3]=[1,0,1]
    Map[2][:3]=[1]*3
    star(N)
    
for i in Map:
    for j in i:
        if j == 1:
            print("*",end='')
        else:
            print(" ",end='')
    print()

print()
