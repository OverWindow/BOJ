Alphabet='abcdefghijklmnopqrstuvwxyz'
word = input()

for i in Alphabet:
    if i in word:
        print(word.index(i),end=' ')
    else:
        print("-1",end=' ')

print()
