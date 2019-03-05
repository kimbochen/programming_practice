#include <iostream>
#include <vector>

// Problem description: https://codeforces.com/contest/1118/problem/B
void probB(void);

int main(void)
{
    probB();

    return 0;
}

void probB(void)
{
    int n;
    std::cin >> n;

    std::vector<int> weight(n);

    int odd_pre = 0, evn_pre = 0,
        odd_suf = 0, evn_suf = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];

        if (i % 2 == 0)
            evn_suf += weight[i];
        else
            odd_suf += weight[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            evn_suf -= weight[i];
        else
            odd_suf -= weight[i];

        if (odd_pre + evn_suf == evn_pre + odd_suf) ans ++;

        if (i % 2 == 0)
            evn_pre += weight[i];
        else
            odd_pre += weight[i];
    }

    std::cout << ans << '\n';
}
