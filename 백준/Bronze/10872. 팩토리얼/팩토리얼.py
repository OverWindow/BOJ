N=int(input())
Answer = 1

def func(i):
    global Answer
    if i==1 or i==0:
        return
    Answer *= i
    i-=1
    func(i)

func(N)
print(Answer)
