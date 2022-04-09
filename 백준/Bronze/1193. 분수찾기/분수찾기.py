X=int(input())
line_Sum = 1
i=1
while X > line_Sum:
    i += 1
    line_Sum += i
line = i + 1
if line%2!=0:
    front_num = X - line_Sum + i
    back_num = line - front_num
else:
    back_num = X - line_Sum + i
    front_num = line - back_num

print(f"{front_num}/{back_num}")
