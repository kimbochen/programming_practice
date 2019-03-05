#include <iostream>
#include <vector>
#define MAXSIZE 200001

using namespace std;

class BIT
{
public:
    BIT(int size_): size(size_) {}

    void update(int i, int delta)
    {
        while (i <= size)
        {
            arr[i] += delta;
            i += i & -i;
        }
    }

    int rangeSum(int i)
    {
        int sum = 0;

        while (i > 0)
        {
            sum += arr[i];
            i -= i & -i;
        }

        return sum;
    }

private:
    int arr[MAXSIZE] = { 0 };
    int size;
};

int main(void)
{
    int n;

    cin >> n;

    int a;
    BIT wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i % 2 == 0)
            wt.update(i+1, a);
        else
            wt.update(i+1, -a);
    }

    int ans = 0, sum = wt.rangeSum(n);

    for (int i = 0; i < n; i++)
    {
        if (wt.rangeSum(i) == sum - wt.rangeSum(i+1)) ans ++;
    }

    cout << ans << '\n';

    return 0;
}
