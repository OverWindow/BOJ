A,B = map(int,input().split())
Rev_A = (A%10)*100 + (A%100)//10*10 + A//100
Rev_B = (B%10)*100 + (B%100)//10*10 + B//100
if Rev_A > Rev_B:
    print(Rev_A)
else:
    print(Rev_B)
