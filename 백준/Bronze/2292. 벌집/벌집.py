N=int(input())
count = 1
Limit = 1
while True:
    if N <= Limit:
        print(count)
        break
    Limit += 6 * count
    count += 1
