#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> a;

bool canFinish(int days)
{
    long long pages = 0, t = 0;

    for (int i = 0; i < n && a[i] > t; i++)
    {
        pages += a[i] - t;

        if ((i + 1) % days == 0) t++;
    }

    return (pages >= m);
}

int main(void)
{
    cin >> n >> m;

    a = vector<int>(n);

    for (auto& e : a) cin >> e;

    auto cmp = [](int a, int b)
    {
        return (a > b);
    };

    sort(a.begin(), a.end(), cmp);

    int lf = 1, rt = n+1;

    while (lf < rt)
    {
        int md = (lf + rt) / 2;

        if (canFinish(md))
            rt = md;
        else
            lf = md + 1;
    }

    if (lf > n)
        cout << -1 << endl;
    else
        cout << lf << endl;

    return 0;
}
