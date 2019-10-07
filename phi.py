x = float(input('Number: '))
i = 0

while round(x, 16) != 1.6180339887498950:
    x = 1 + 1/x
    i = i + 1
    print(f'{i} iteration: x = {x}')
