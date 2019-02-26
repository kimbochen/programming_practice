#include <iostream>

using ull = unsigned long long;

int main(void)
{
    int q, a, b;
    ull n, x, y;

    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        std::cin >> n >> a >> b;

        if (2 * a >= b)
        {
            if (n % 2 == 0)
            {
                x = 0;
                y = n/2;
            }
            else
            {
                x = 1;
                y = (n-1)/2;
            }
        }
        else
        {
            x = n;
            y = 0;
        }

        std::cout << a * x + b * y << '\n';
    }

    return 0;
}
