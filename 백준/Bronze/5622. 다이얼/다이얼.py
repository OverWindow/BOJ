Input_Word = list(input())
Dial = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
seconds = 0

for i in Input_Word:
    for j in Dial:
        if i in str(j):
            seconds += Dial.index(j) + 3

print(seconds)

