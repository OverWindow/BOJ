All_number = set(range(1,10001))
Target_number = set()

for i in range(1,10001):
    for j in str(i):
        i += int(j)
    Target_number.add(i)

Self_number = sorted(All_number - Target_number)

for i in Self_number:
    print(i)

