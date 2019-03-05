#include <iostream>
#include <vector>

int main(void)
{
    int n;

    std::cin >> n;

    int a, suf_sum = 0;
    std::vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a;

        s[i] = (i % 2 == 0) ? a : -a;
        suf_sum += s[i];
    }

    int ans = 0;

    for (int i = 0, pre_sum = 0; i < n; i++)
    {
        pre_sum += s[i];

        if (pre_sum == suf_sum) ans ++;

        suf_sum -= s[i];
    }

    std::cout << ans << '\n';

    return 0;
}
