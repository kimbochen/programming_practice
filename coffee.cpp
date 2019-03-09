#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return (a > b);
}

int main(void)
{
    int n, m;
    vector<int> a;

    cin >> n >> m;

    a = vector<int>(n);

    for (auto& e : a) cin >> e;

    sort(a.begin(), a.end(), cmp);

    for (int days = 1; days <= n; days++)
    {
        int pages = 0, t = 0;

        for (int i = 0; i < n && a[i] > t; i++)
        {
            pages += a[i] - t;

            if ((i+1) % days == 0) t++;
        }

        if (pages >= m)
        {
            cout << days << endl;
            exit(0);
        }
    }

    cout << -1 << endl;

    return 0;
}
