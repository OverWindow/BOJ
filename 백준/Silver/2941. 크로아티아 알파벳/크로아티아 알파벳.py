Croatian_Word = input()
Croatian_Alpha = ['c=','c-','dz=','d-','lj','nj','s=','z=']
count = 0

for i in Croatian_Alpha:
    while i in Croatian_Word:
        Croatian_Word = Croatian_Word.replace(i,str(Croatian_Alpha.index(i)+1))
        count += 1
    


print(len(Croatian_Word))


        
    
