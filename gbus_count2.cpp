#include <iostream>
#define SIZE 5001

using namespace std;

struct BIT
{
    void update(int i, int k)
    {
        while (i <= SIZE)
        {
            arr[i] += k;
            i += (i & -i);
        }
    }

    int range_sum(int i)
    {
        int sum = 0;

        while (i > 0)
        {
            sum += arr[i];
            i -= (i & -i);
        }

        return sum;
    }

    int arr[SIZE] = { 0 };
};

void solve(void);

int main(void)
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i+1 << ':';
        solve();
    }

    return 0;
}

void solve()
{
    BIT bit;
    int N, P;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int A, B;

        cin >> A >> B;

        bit.update(A, 1);
        bit.update(B+1, -1);
    }

    cin >> P;

    for (int i = 0; i < P; i++)
    {
        int C;

        cin >> C;

        cout << ' ' << bit.range_sum(C);
    }
    cout << '\n';
}
