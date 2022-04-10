A,B,V = map(int,input().split())

if (V-A)%(A-B) != 0:
    print(2+(V-A)//(A-B))
else:
    print(1+(V-A)//(A-B))

    