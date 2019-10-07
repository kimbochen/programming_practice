#include <iostream>

using namespace std;

int main(void)
{
    int sc1, sc2, n;
    int lead = 0, max_lead = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> sc1 >> sc2;

        lead += sc1 - sc2;

        if (lead + max_lead < 0 || lead - max_lead > 0)
        {
            max_lead = lead;
        }
    }

    if (max_lead > 0)
    {
        cout << "1 " << max_lead << '\n';
    }
    else
    {
        cout << "2 " << -max_lead << '\n';
    }

    return 0;
}
