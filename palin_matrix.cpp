#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int,int>;

int n;
map<int, int> cnt;
priority_queue<pii> q;
vector<vector<int>> a;

void put(vector<pii> pos)
{
    auto t(q.top());

    q.pop();

    if (t.first < pos.size())
    {
        cout << "NO\n";
        exit(0);
    }

    for (auto p : pos)
    {
        a[p.first][p.second] = t.second;
    }

    t.first -= pos.size();

    q.push(t);
}

int main(void)
{
    cin >> n;

    a = vector<vector<int>>(n, vector<int>(n));

    int x;
    for (int i = 0, m = n * n; i < m; i++)
    { 
        cin >> x;
        cnt[x] ++;
    }

    for (auto p : cnt)
    {
        q.push({ p.second, p.first });
    }

    for (int i = 0, m = n/2; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            put({ {i, j}, {n-i-1, j}, {i, n-j-1}, {n-i-1, n-j-1} });
        }
    }

    if (n % 2 != 0)
    {
        int m = n / 2;

        for (int i = 0; i < m; i++)
        {
            put({ {i, m}, {n-i-1, m} });
            put({ {m, i}, {m, n-i-1} });
        }

        put({ {m, m} });
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\n "[j<n-1];
    }

    return 0;
}
