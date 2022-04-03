Alphabet=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
word = list(input())

for i in Alphabet:
    if i in word:
        if word.count(i) == 2:
            count = 0
            while True:
                if word[count] == i:
                    break
                count += 1
            print(count,end=' ')     
        else:
            print(word.index(i),end=' ')
    else:
        print("-1",end=' ')

print()
