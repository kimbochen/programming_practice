#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int,int>;
using vi = vector<int>;

int n;
vector<vi> a;
map<int,int> cnt;
priority_queue<pii> q;

void solveProb(void);
void put(vector<pii> pos);
int rev(int);

int main(void)
{
    solveProb();

    return 0;
}

int rev(int x)
{
    return n - 1 - x;
}

void solveProb(void)
{
    cin >> n;

    a = vector<vi>(n, vi(n));

    for (int i = 0, m = n * n; i < m; i++)
    {
        int key;
        cin >> key;
        cnt[key] ++;
    }

    for (auto [key, val] : cnt)
    {
        q.push({val, key});
    }

    for (int i = 0, m = n / 2; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            put({ {i, j}, {rev(i), j}, {i, rev(j)}, {rev(i), rev(j)} });
        }
    }

    if (n % 2 != 0)
    {
        int m = n / 2;

        for (int i = 0; i < m; i++)
        {
            put({ {i, m}, {rev(i), m} });
            put({ {m, i}, {m, rev(i)} });
        }

        put({ {m, m} });
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\n "[j<n-1];
        }
    }
}

void put(vector<pii> pos)
{
    pii e = q.top();

    q.pop();

    if (e.first < pos.size())
    {
        cout << "NO\n";
        exit(0);
    }

    for (auto [i, j] : pos)
        a[i][j] = e.second;

    e.first -= pos.size();

    q.push(e);
}
