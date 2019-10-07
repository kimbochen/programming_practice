from collections import defaultdict
import sys

data = defaultdict(float)

for line in sys.stdin:
    ch, num = line.split(',')
    data[ch] += float(num)

for _ in range(3):
    top = max(data, key=data.get)
    num = data.pop(top)
    print(f'{top},{num}')
