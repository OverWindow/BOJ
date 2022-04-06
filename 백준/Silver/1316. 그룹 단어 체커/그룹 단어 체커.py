N=int(input())
Word_List = []
Word_Before= 0

for i in range(N):
    word = input()
    Word_List.append(word)
    
Group_Words = Word_List [:]



for i in Word_List:
    Word_Before= 0
    
    Alphabet = 'abcdefghijklmnopqrstuvwxyz'
    for j in str(i):
        if j == Word_Before:
            
            continue
        elif j in Alphabet:
           
            Alphabet = Alphabet.replace(j,'')
            Word_Before = j
        else:
            
            Group_Words.remove(i)
            break
            
        

print(len(Group_Words))
