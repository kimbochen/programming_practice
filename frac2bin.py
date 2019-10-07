
def fraction2binary(fraction):
    '''Converts decimal a fraction to binary'''
    ans = ''
    for _ in range(52):
        fraction *= 2
        integ = int(fraction)
        if integ == 1:
            ans += '1'
            fraction -= 1
        else:
            ans += '0'
    for i in range(0, 52, 4):
        print(f'[{i}:{i+3}] = {ans[i:i+4]}')

fraction2binary(float(input()))

# ans = fraction2binary(1 - 2**(-53))
# print(ans == '1111111111111111111111111111111111111111111111111111')
