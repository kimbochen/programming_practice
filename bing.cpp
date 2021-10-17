#include <iostream>

const int N = 1'000'000'007;

long fibonacci(int n)
{
    if (n < 2) return n;

    int k = (n + 1) / 2;
    long a = fibonacci(k - 1);
    long b = fibonacci(k);

    if (n % 2 == 0) {
        return (2 * a + b) * b;
    }
    else {
        return (a * a) + (b * b);
    }
}

int main()
{
    int n{};
    std::cin >> n;

    long fib = fibonacci(n + 1);

    std::cout << fib % N << '\n';

    return 0;
}
